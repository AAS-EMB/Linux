#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(int argc, char **argv) {
    void *pHandle;
    int (*pFunc)(int);
    char *pError;

    if(argc != 4) {
        fprintf(stderr, "Usage: %s <libSolution.so> <function> <arg>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    pHandle = dlopen(argv[1], RTLD_LAZY);
    if(!pHandle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(EXIT_FAILURE);
    }
    dlerror();
    pFunc = (int (*)(int)) dlsym(pHandle, argv[2]);
    pError = dlerror();
    if(pError != NULL) {
   	    fprintf(stderr, "%s\n", pError);
	    exit(EXIT_FAILURE);
    }
    printf("%d\n", (*pFunc)(atoi(argv[3])));
    dlclose(pHandle);

    return 0;
}

