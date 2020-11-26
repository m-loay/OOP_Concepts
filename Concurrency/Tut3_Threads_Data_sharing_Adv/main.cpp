#include <iostream>
#include <list>
#include <thread>
#include <string>
#include <mutex>
std::list<int> g_Data;
const int SIZE = 10000;
std::mutex g_Mutex;

/*******************************************************************************
 *  Donwload callable for thDownloader                                         *
 *******************************************************************************/
void Download() 
{
	for (int i = 0; i < SIZE; ++i) 
	{
		//Use std::lock_guard to lock a mutex (RAII)
		std::lock_guard<std::mutex> mtx(g_Mutex);
		g_Data.push_back(i);
		if (i == 500)
			return;
	}
}

/*******************************************************************************
 *   Donwload2 callable for thDownloader2                                      *
 *******************************************************************************/
void Download2() 
{
	for (int i = 0; i < SIZE; ++i) 
	{
		std::lock_guard<std::mutex> mtx(g_Mutex);
		g_Data.push_back(i);
	}
}

/*******************************************************************************
 *  Main                                                                        *
 *******************************************************************************/
int main() 
{
	std::thread thDownloader(Download);
	std::thread thDownloader2(Download2);
	thDownloader.join();
	thDownloader2.join();
	std::cout << g_Data.size() << std::endl; 
	return 0;
}