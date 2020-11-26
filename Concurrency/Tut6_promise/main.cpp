#include <iostream>
#include <thread>
#include <chrono>
#include <future>


/*******************************************************************************
 *  Donwload callable for thDownloader                                         *
 *******************************************************************************/
int Download(std::promise<int> & data) 
{
	//use future getter to get promise data
	auto f = data.get_future();

	std::cout<<"sec_thread(Download) Waiting for Input"<<std::endl;
	//consume the data
	auto count = f.get();
	std::cout<<"sec_thread(Download) Input is acquired/consumed"<<std::endl;

	int sum{};
	using namespace std::chrono_literals;
	std::cout<<"sec_thread(Download) execute"<<std::endl;
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
 *  mainThread: Function that runs downloads and consumes it's output AsyncPolicy  *
 *******************************************************************************/
void mainThreadAsyncPolicy (void)
{
	using namespace std::chrono_literals;

	//create promise object
	std::promise<int> data;

	//call download using async that take callable and input for it
	std::future<int> result = std::async(std::launch::async, Download,std::ref(data));
	std::this_thread::sleep_for(1s);
	std::cout<<"mainThreadAsyncPolicy execute"<<std::endl;

	std::cout<<"mainThreadAsyncPolicy set data in promise"<<std::endl;
	data.set_value(10);

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

	std::cout<<"\n\nMain thread --> Async policy"<<std::endl;
	mainThreadAsyncPolicy();

	return 0;
}