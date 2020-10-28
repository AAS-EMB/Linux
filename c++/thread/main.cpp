#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>

std::mutex ThreadMutex;

/*!
 * @brief Callback function Thread
 */
void ThreadCallback(void)
{
	ThreadMutex.lock();
	std::cout << "Enter thread ID = " << std::this_thread::get_id() << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(rand()%10));
	std::cout << "Leave thread ID = " << std::this_thread::get_id() << std::endl;
	ThreadMutex.unlock();
}

int main(void)
{
     srand((unsigned int)time(0));
     std::thread t1(ThreadCallback);
     std::thread t2(ThreadCallback);
     std::thread t3(ThreadCallback);
     t1.join();
     t2.join();
     t3.join();
     return 0;
}