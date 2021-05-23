/*!
 * @file can_to_udp.c
 *
 * @brief CAN to UDP module
 *
 * @author Anosov Anton
 */

#include "can_to_udp.h"

static pthread_mutex_t mutex;

/*
 * @brief Polling thread, checking input data from UDP and CAN interfaces
 * @param argv - Input argument of thread
 */
static void *polling(void *argv) {
  struct sockets_info *s = (struct sockets_info *)argv;
  struct pollfd fds[EVENT_MAX];
  struct can_frame frame;
  struct sockaddr_in addr[SOCKETS_GROUP_MAX];
  int nbytes;
  char buf[CAN_MAX_DLC];

  for (int i = 0, j = 0; i < EVENT_MAX && j < SOCKETS_GROUP_MAX; i += 2, j++) {
    fds[i].fd = s[j].socket_can;
    fds[i].events = POLLIN;
    fds[i + 1].fd = s[j].socket_udp;
    fds[i + 1].events = POLLIN;
    addr[j].sin_family = AF_INET;
    addr[j].sin_port = htons(s[j].udp_port_client);
    addr[j].sin_addr.s_addr = inet_addr(s[j].udp_addr);
  }

  while (1) {
    if (poll(fds, EVENT_MAX, POLLING_MAX_TIMEOUT) > 0) {
      if (fds[EVENT_CAN_TO_UDP_1].revents & POLLIN) {
        pthread_mutex_lock(&mutex);
        fds[EVENT_CAN_TO_UDP_1].revents = 0;
        memset(&frame, 0, sizeof(struct can_frame));
        memset(buf, 0, sizeof(buf));
        nbytes = read(s[SOCKETS_GROUP_1].socket_can, &frame,
                      sizeof(struct can_frame));
        for (int i = 0; i < frame.can_dlc; i++) {
          buf[i] = frame.data[i];
        }
        sendto(s[SOCKETS_GROUP_1].socket_udp, buf, frame.can_dlc, 0,
               (struct sockaddr *)&addr[SOCKETS_GROUP_1],
               sizeof(struct sockaddr_in));
        pthread_mutex_unlock(&mutex);
      }
      if (fds[EVENT_UDP_TO_CAN_1].revents & POLLIN) {
        pthread_mutex_lock(&mutex);
        fds[EVENT_UDP_TO_CAN_1].revents = 0;
        memset(&frame, 0, sizeof(struct can_frame));
        memset(buf, 0, sizeof(buf));
        nbytes = recvfrom(s[SOCKETS_GROUP_1].socket_udp, buf, CAN_MAX_DLC, 0,
                          NULL, NULL);
        frame.can_id = s[SOCKETS_GROUP_1].can_id;
        frame.can_dlc = nbytes;
        for (int i = 0; i < nbytes; i++) {
          frame.data[i] = buf[i];
        }
        write(s[SOCKETS_GROUP_1].socket_can, &frame, sizeof(struct can_frame));
        pthread_mutex_unlock(&mutex);
      }
      if (fds[EVENT_CAN_TO_UDP_2].revents & POLLIN) {
        pthread_mutex_lock(&mutex);
        fds[EVENT_CAN_TO_UDP_2].revents = 0;
        memset(&frame, 0, sizeof(struct can_frame));
        memset(buf, 0, sizeof(buf));
        nbytes = read(s[SOCKETS_GROUP_2].socket_can, &frame,
                      sizeof(struct can_frame));
        for (int i = 0; i < frame.can_dlc; i++) {
          buf[i] = frame.data[i];
        }
        sendto(s[SOCKETS_GROUP_2].socket_udp, buf, frame.can_dlc, 0,
               (struct sockaddr *)&addr[SOCKETS_GROUP_2],
               sizeof(struct sockaddr_in));
        pthread_mutex_unlock(&mutex);
      }
      if (fds[EVENT_UDP_TO_CAN_2].revents & POLLIN) {
        pthread_mutex_lock(&mutex);
        fds[EVENT_UDP_TO_CAN_2].revents = 0;
        memset(&frame, 0, sizeof(struct can_frame));
        memset(buf, 0, sizeof(buf));
        nbytes = recvfrom(s[SOCKETS_GROUP_2].socket_udp, buf, CAN_MAX_DLC, 0,
                          NULL, NULL);
        frame.can_id = s[SOCKETS_GROUP_2].can_id;
        frame.can_dlc = nbytes;
        for (int i = 0; i < nbytes; i++) {
          frame.data[i] = buf[i];
        }
        write(s[SOCKETS_GROUP_2].socket_can, &frame, sizeof(struct can_frame));
        pthread_mutex_unlock(&mutex);
      }
    }
  }
}

/*
 * @brief Initialization CAN interface
 * @param s - Pointer of description
 * @return 0 - successfully, -1 - error create socket, -2 - error bind socket
 */
static int initCan(struct sockets_info *s) {
  struct sockaddr_can addr;
  struct ifreq ifr;
  struct can_filter filter;

  memset(&addr, 0, sizeof(struct sockaddr_can));
  memset(&ifr, 0, sizeof(struct ifreq));

  if ((s->socket_can = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0) {
    perror("CAN_Socket");
    return -1;
  }

  strcpy(ifr.ifr_name, s->can_name);
  ioctl(s->socket_can, SIOCGIFINDEX, &ifr);

  addr.can_family = AF_CAN;
  addr.can_ifindex = ifr.ifr_ifindex;

  if (bind(s->socket_can, (struct sockaddr *)&addr,
           sizeof(struct sockaddr_can)) < 0) {
    perror("CAN_Bind");
    return -2;
  }

  filter.can_id = s->can_id;
  filter.can_mask = 0xFFF;
  setsockopt(s->socket_can, SOL_CAN_RAW, CAN_RAW_FILTER, &filter,
             sizeof(filter));

  return 0;
}

/*
 * @brief Initialization UDP interface (server)
 * @param s - Pointer of description
 * @return 0 - successfully, -1 - error create socket, -2 - error bind socket
 */
static int initUdp(struct sockets_info *s) {
  struct sockaddr_in addr;

  memset(&addr, 0, sizeof(struct sockaddr_in));

  if ((s->socket_udp = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
    perror("UDP_Socket");
    return -1;
  }

  addr.sin_family = AF_INET;
  addr.sin_port = htons(s->udp_port_server);
  addr.sin_addr.s_addr = inet_addr(s->udp_addr);

  if (bind(s->socket_udp, (struct sockaddr *)&addr,
           sizeof(struct sockaddr_in)) < 0) {
    perror("UDP_Bind");
    return -2;
  }

  return 0;
}

/*
 * @brief Initialization sockets description
 * @param s - Pointer of description
 */
static void initSockets(struct sockets_info *s) {
  s[SOCKETS_GROUP_1].can_id = CAN_ID_1;
  s[SOCKETS_GROUP_1].can_name = CAN_NAME_1;
  s[SOCKETS_GROUP_1].udp_addr = UDP_ADDR_SERVER_1;
  s[SOCKETS_GROUP_1].udp_port_server = UDP_PORT_SERVER_1;
  s[SOCKETS_GROUP_1].udp_port_client = UDP_PORT_CLIENT_1;
  s[SOCKETS_GROUP_2].can_id = CAN_ID_2;
  s[SOCKETS_GROUP_2].can_name = CAN_NAME_2;
  s[SOCKETS_GROUP_2].udp_addr = UDP_ADDR_SERVER_2;
  s[SOCKETS_GROUP_2].udp_port_server = UDP_PORT_SERVER_2;
  s[SOCKETS_GROUP_2].udp_port_client = UDP_PORT_CLIENT_2;
}

int main(int argc, char **argv) {
  pthread_t thread;
  int status;
  struct sockets_info sockets[SOCKETS_GROUP_MAX];

  initSockets(sockets);

  for (int i = SOCKETS_GROUP_1; i < SOCKETS_GROUP_MAX; i++) {
    status = initCan(sockets + i);
    if (status != 0) {
      printf("main error: can't init CAN, status = %d\n", status);
      exit(EXIT_FAILURE);
    }

    status = initUdp(sockets + i);
    if (status != 0) {
      printf("main error: can't init UDP, status = %d\n", status);
      exit(EXIT_FAILURE);
    }
  }

  status = pthread_create(&thread, NULL, polling, (void *)sockets);
  if (status != 0) {
    printf("main error: can't create thread, status = %d\n", status);
    exit(EXIT_FAILURE);
  }

  pthread_mutex_init(&mutex, NULL);

  while (1);

  return 0;
}
