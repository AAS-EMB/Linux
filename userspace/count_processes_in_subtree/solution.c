#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_COUNT_PROCESS 256

int main(int argc, char **argv) {
    FILE *pFile;
    int Count = 0;
    int It = 0;
    char *pLine = NULL;
    size_t Len = 0;
    ssize_t NRead;
    int PID[MAX_COUNT_PROCESS] = {0};
    int TmpPID, TmpPPID;

    if(argc != 2) {
        fprintf(stderr, "Usage: %s <PID>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int PPID = atoi(argv[1]);

    if((pFile = popen("cat /proc/[0-9]*/status", "r")) == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    while(1) {
        while ((NRead = getline(&pLine, &Len, pFile)) != -1) {
            if(!strncmp(pLine, "Pid:", 4)) {
                sscanf(pLine, "%*s %d", &TmpPID);
            } else if(!strncmp(pLine, "PPid:", 5)) {
                sscanf(pLine, "%*s %d", &TmpPPID);
                if(TmpPPID == PPID) {
	                PID[Count] = TmpPID;
	                Count++;
	            }	
            }
        }
        free(pLine);
        pclose(pFile);
        pLine = NULL;
        Len = 0;
        if(PID[It] != 0) {
            PPID = PID[It];
	        It++;
            if((pFile = popen("cat /proc/[0-9]*/status", "r")) == NULL) {
                perror("fopen");
                exit(EXIT_FAILURE);
            }
        } else {
            break;
        }
    }
    Count++;
    printf("%d\n", Count);
    
    return 0;
} 
