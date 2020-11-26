#include <iostream>
#include <thread>
#include <chrono>
#include <future>


/*******************************************************************************
 *  Donwload callable for thDownloader                                         *
 *******************************************************************************/
int Download(int count) 
{
	std::cout<<"sec_thread(Download) execute"<<std::endl;
	int sum{};
	using namespace std::chrono_literals;
	for (int i = 0; i < count; ++i) 
	{
		sum += i;
		std::cout<<" . ";
		std::this_thread::sleep_for(300ms);
	}
	std::cout<<std::endl;
	return sum;
}

/*******************************************************************************
 *  mainThread: Function that runs downloads and consumes it's output  *
 *******************************************************************************/
void mainThread (void)
{
	//call download using async that take callable and input for it
	std::future<int> result = std::async(Download,10);
	std::cout<<"mainThread execute"<<std::endl;

	// block task termination until ready then return or throw the stored exception
	if(result.valid())
	{
		//.get()consume the return of download function, this can be consumed only once.
		auto sum = result.get();
		std::cout<<"Sum = "<<sum<<std::endl;
	}

}

/*******************************************************************************
 *  mainThread: Function that runs downloads and consumes it's output AsyncPolicy  *
 *******************************************************************************/
void mainThreadAsyncPolicy (void)
{
	using namespace std::chrono_literals;

	//call download using async that take callable and input for it
	std::future<int> result = std::async(std::launch::async, Download,10);
	std::this_thread::sleep_for(1s);
	std::cout<<"mainThreadAsyncPolicy execute"<<std::endl;

	// block task termination until ready then return or throw the stored exception
	if(result.valid())
	{
		//.get()consume the return of download function, this can be consumed only once.
		auto sum = result.get();
		std::cout<<"Sum = "<<sum<<std::endl;
	}
}

/*******************************************************************************
 *  mainThread: Function that runs downloads and consumes it's output deferred Policy  *
 *******************************************************************************/
void mainThreadDeferredPolicy (void)
{
	using namespace std::chrono_literals;

	//call download using async that take callable and input for it
	std::future<int> result = std::async(std::launch::deferred, Download,10);
	std::this_thread::sleep_for(1s);
	std::cout<<"mainThreadAsyncPolicy execute"<<std::endl;

	// block task termination until ready then return or throw the stored exception
	if(result.valid())
	{
		//.get()consume the return of download function, this can be consumed only once.
		auto sum = result.get();
		std::cout<<"Sum = "<<sum<<std::endl;
	}
}

/*******************************************************************************
 *  Main                                                                        *
 *******************************************************************************/
int main() 
{

	std::cout<<"\n\nMain thread --> No launch policy"<<std::endl;
	mainThread();

	std::cout<<"\n\nMain thread --> Async policy"<<std::endl;
	mainThreadAsyncPolicy();

	std::cout<<"\n\nMain thread --> Deferred Policy"<<std::endl;
	mainThreadDeferredPolicy();

	return 0;
}