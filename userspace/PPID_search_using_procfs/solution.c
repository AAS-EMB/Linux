#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    FILE *pFile;
    int PPID;

    if((pFile = fopen("/proc/self/stat", "r")) == NULL) {
        fprintf(stderr, "Cannot open file.\n");
        exit(EXIT_FAILURE);
    }

    fscanf(pFile, "%*d %*s %*c %d", &PPID);
    printf("%d\n", PPID);
    fclose(pFile);

    return 0;
}
