/*!
 * @file can_to_udp.h
 *
 * @brief CAN to UDP module
 *
 * @author Anosov Anton
 */

#ifndef CAN_TO_UDP_H_
#define CAN_TO_UDP_H_
#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <net/if.h>
#include <pthread.h>
#include <sys/ioctl.h>
#include <sys/poll.h>
#include <sys/socket.h>

#include <linux/can.h>
#include <linux/can/raw.h>

#include <arpa/inet.h>
#include <sys/socket.h>

/* UDP client and server configuration */
#define UDP_ADDR_SERVER_1 "127.0.0.1"
#define UDP_ADDR_SERVER_2 "127.0.0.1"
#define UDP_PORT_SERVER_1 (4001)
#define UDP_PORT_SERVER_2 (4002)
#define UDP_PORT_CLIENT_1 (5001)
#define UDP_PORT_CLIENT_2 (5002)

/* CAN interface configuration */
#define CAN_NAME_1 "vcan0"
#define CAN_NAME_2 "vcan1"
#define CAN_ID_1 (0x510)
#define CAN_ID_2 (0x520)

#define POLLING_MAX_TIMEOUT 10

/* Sockets group name (UDP + CAN sockets) */
enum sockets_group_name {
  SOCKETS_GROUP_1,
  SOCKETS_GROUP_2,
  SOCKETS_GROUP_MAX
};

/* Event names */
enum event_name {
  EVENT_CAN_TO_UDP_1,
  EVENT_UDP_TO_CAN_1,
  EVENT_CAN_TO_UDP_2,
  EVENT_UDP_TO_CAN_2,
  EVENT_MAX
};

/* Sockets information description */
struct sockets_info {
  int socket_udp;
  int socket_can;
  char *udp_addr;
  char *can_name;
  uint16_t udp_port_server;
  uint16_t udp_port_client;
  int can_id;
};

#ifdef __cplusplus
}
#endif
#endif /* CAN_TO_UDP_H_ */
