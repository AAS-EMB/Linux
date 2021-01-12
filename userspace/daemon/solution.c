#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

pid_t PID;

void SignalHandler(int Signalno) {
    switch(Signalno) {
        case SIGURG:
            exit(EXIT_SUCCESS);
    }
}

int main(int argc, char **argv) {
    daemon(0, 1);
    PID = getpid();
    printf("%d\n", (int)PID);
    fclose(stdin);
    fclose(stdout);
    fclose(stderr);
    signal(SIGURG, SignalHandler);
    
    while(1) {
        sleep(1000);
    }

    return 0;
} 
