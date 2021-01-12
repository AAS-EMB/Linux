#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFF_SIZE 256

int main(int argc, char **argv) {
    FILE *pFile;
    char Buff[MAX_BUFF_SIZE];
    int Sym = 0;
    int Counter = 0;

    if(argc != 3) {
        fprintf(stderr, "Usage: %s <func> <arg>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    sprintf(Buff, "%s %s", argv[1], argv[2]);

    if((pFile = popen(Buff, "r")) == NULL) {
        perror("popen");
        exit(EXIT_FAILURE);
    }
  
    while((Sym = fgetc(pFile)) != EOF) {
        if(Sym == '0') Counter++;
    }

    printf("%d\n", Counter);
    pclose(pFile);

    return 0;
} 
