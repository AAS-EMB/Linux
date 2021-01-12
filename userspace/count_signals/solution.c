#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

volatile int CountSigusr1, CountSigusr2;

void SignalHandler(int Signalno) {
    switch(Signalno) {
        case SIGUSR1:
            CountSigusr1++;
            break;
        case SIGUSR2:
            CountSigusr2++;
            break;
        case SIGTERM:
            printf("%d %d\n", CountSigusr1, CountSigusr2);
            exit(EXIT_SUCCESS);
    }
}

int main(int argc, char **argv) {
    signal(SIGUSR1, SignalHandler);
    signal(SIGUSR2, SignalHandler);
    signal(SIGTERM, SignalHandler);

    while(1) {
        usleep(500000);
    }

    return 0;
} 
