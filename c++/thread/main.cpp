#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <pthread.h>
#include <iostream>
#include <unistd.h>

const unsigned int MaxCountThread = 4; ///< Max count create thread

/*
 * Description for create thread's
 */
typedef struct Thread_s
{
	unsigned int NumberThread;
	int ArgThread;
}Thread_t;

/*!
 * @brief Callback function Thread
 */
void* ThreadCallback(void *arg)
{
	Thread_t *pThreadDescr = (Thread_t*)arg;

	while(1)
	{
		std::cout << "NumberThread: " << pThreadDescr->NumberThread << "\tArgThread: " << pThreadDescr->ArgThread << std::endl;
		sleep(1);
	}
}

int main(int argc, char *argv[])
{
    Thread_t ThreadDescr[MaxCountThread];
    pthread_t Thread[MaxCountThread];

    for(unsigned int i = 0; i < MaxCountThread; i++)
    {
    	ThreadDescr[i].NumberThread = i;
    	ThreadDescr[i].ArgThread = rand();
    	if(pthread_create(Thread + i, nullptr, ThreadCallback, ThreadDescr + i) != 0)
    	{
    		std::cerr << "Error create thread " << i << std::endl;
    		return EXIT_FAILURE;
    	}
    }

	while(1)
	{
		sleep(10);
	}
}
