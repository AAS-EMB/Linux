#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char Path[16] = "proc";

int main(int argc, char **argv) {
    FILE *pFile;
    int PPID = -1;
    char Dst[128];

    if(argc != 2) {
        fprintf(stderr, "Usage: %s <PID>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    while(1) {
        if(PPID == -1) {
            printf("%s\n", argv[1]);
            sprintf(Dst, "/%s/%s/stat", Path, argv[1]); 
        } else {
            sprintf(Dst, "/%s/%d/stat", Path, PPID);
        }
        if((pFile = fopen(Dst, "r")) == NULL) {
            fprintf (stderr, "Cannot open file.\n");
            exit(EXIT_FAILURE);
        }
        fscanf(pFile, "%*d %*s %*c %d", &PPID);
        printf("%d\n", PPID);
        fclose(pFile);
        if(PPID == 1) break;
    }

    return 0;
}
