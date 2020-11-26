#include <iostream>
#include <thread>
#include <chrono>
#include <future>
const int SIZE = 10;

/*******************************************************************************
 *  Donwload callable for thDownloader                                         *
 *******************************************************************************/
void Download() 
{
	std::cout<<"sec_thread(Download) execute"<<std::endl;
	using namespace std::chrono_literals;
	for (int i = 0; i < SIZE; ++i) 
	{
		std::cout<<" . ";
		std::this_thread::sleep_for(300ms);
	}
	std::cout<<std::endl;
}

/*******************************************************************************
 *  Problem: Function that shows the issue when a thread blocks another Thread  *
 *******************************************************************************/
void problem (void)
{
	//call Download
	Download();
	std::cout<<"main_thread(problem) execute"<<std::endl;
}

/*******************************************************************************
 *  solution: Function that shows the solution when a thread blocks another Thread  *
 *******************************************************************************/
void solution (void)
{
	//call download using async
	std::future<void> result = std::async(Download);
	std::cout<<"main_thread(solution) execute"<<std::endl;

	// block task termination until ready then return or throw the stored exception
	result.get();
}

/*******************************************************************************
 *  Main                                                                        *
 *******************************************************************************/
int main() 
{
	std::cout<<"First Example to show the issue --> Problem executes"<<std::endl;
	problem();

	std::cout<<"2nd Example to show the solution --> solution executes"<<std::endl;
	solution();

	return 0;
}