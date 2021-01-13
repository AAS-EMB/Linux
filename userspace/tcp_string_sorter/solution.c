#include <stdio.h>
#include <netdb.h>
#include <netinet/ip.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>

struct sockaddr_in Local;

static int CmpStringPointer(const void *p1, const void *p2) {
    char Elem1 = *((char*)p1);
    char Elem2 = *((char*)p2);
    if(Elem1 < Elem2)      return 1;
    else if(Elem1 > Elem2) return -1;
    else                   return 0;
}

int main(int argc, char **argv) {
    if(argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
   
    char Buff[BUFSIZ];
    int ServerSocket = socket(AF_INET, SOCK_STREAM, 0);
    uint16_t ServerPort = atoi(argv[1]);
   
    inet_aton("127.0.0.1", &Local.sin_addr);
    Local.sin_port = htons(ServerPort);
    Local.sin_family = AF_INET;

    bind(ServerSocket, (struct sockaddr*) &Local, sizeof(Local));
    listen(ServerSocket, 5);

    int ClientSocket = accept(ServerSocket, NULL, NULL);

    while(1) {
        memset(Buff, 0, BUFSIZ);
        ssize_t Length = read(ClientSocket, Buff, BUFSIZ);
        if(!strncmp(Buff, "OFF\n", strlen("OFF\n"))) {
            close(ClientSocket);
            break;
        }
        qsort(Buff, strlen(Buff), sizeof(char), CmpStringPointer); 
        write(ClientSocket, Buff, strlen(Buff) + 1);
    }

    return 0;
}
