#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int It = 0;
    struct hostent *pHost;

    if(argc != 2) {
        fprintf(stderr, " Usage: %s <host name>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
   
    if((pHost = gethostbyname(argv[1])) == NULL) {
        fprintf(stderr, "Error gethostbyname()\n");
        exit(EXIT_FAILURE);
    }

    while(pHost->h_addr_list[It] != NULL) {
        struct in_addr *pAddr = (struct in_addr*) pHost->h_addr_list[It++];
        printf("%s\n", inet_ntoa(*pAddr));
    }

    return 0;
} 
