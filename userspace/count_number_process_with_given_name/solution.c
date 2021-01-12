#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
   system("pidof -c systemd | wc -w");
   return 0;
}
