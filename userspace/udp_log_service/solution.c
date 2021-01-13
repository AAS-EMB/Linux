#include <stdio.h>
#include <netdb.h>
#include <netinet/ip.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>

struct sockaddr_in Local;

int main(int argc, char **argv) {
    if(argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
   
    char Buff[BUFSIZ];
    int ServerSocket = socket(AF_INET, SOCK_DGRAM, 0);
    uint16_t ServerPort = atoi(argv[1]);
   
    inet_aton("127.0.0.1", &Local.sin_addr);
    Local.sin_port = htons(ServerPort);
    Local.sin_family = AF_INET;

    bind(ServerSocket, (struct sockaddr*) &Local, sizeof(Local));

    while(1) {
        memset(Buff, 0, BUFSIZ);
        ssize_t Length = read(ServerSocket, Buff, BUFSIZ);
        
        if(!strncmp(Buff, "OFF\n", strlen("OFF\n"))) break;
        
        fprintf(stdout, "%s\n", Buff);
    }

    return 0;
}
