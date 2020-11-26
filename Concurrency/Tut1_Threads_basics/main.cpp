#include <iostream>
#include <list>
#include <thread>
#include <string>
std::list<int> g_Data;
const int SIZE = 5000000;

/*******************************************************************************
 *  String class                                                               *
 *******************************************************************************/
class String 
{
public:
	String(std::string file):file_(file) 
	{
		std::cout << "String()" << std::endl;
	}

	String(const String &) 
	{
		std::cout << "String(const String&)" << std::endl;
	}

	String & operator=(const String&) 
	{
		std::cout << "operator=(const String&)" << std::endl;

		return *this;
	}

	std::string getFileName(void)const
	{
		return file_;
	}

	~String() {
		std::cout << "~String()" << std::endl;
	}
private:
std::string file_;
};

/*******************************************************************************
 *  Download callable Function                                                 *
 *******************************************************************************/
void Download(const String &file) 
{
	std::cout << "[Downloader]Started download of file :" << file.getFileName() << std::endl; 
	for (int i = 0; i < SIZE; ++i) {
		g_Data.push_back(i);
	}
	std::cout << "[Downloader]Finished download" << std::endl; 
}

/*******************************************************************************
 *  Main                                                 *
 *******************************************************************************/
int main() 
{
	String file("DataFile");

	std::cout << "[main]User started an operation" << std::endl; 
	//use std::ref and std::cref to pass arguments as reference & const reference, respectively
	//create a thread for Download
	std::thread thDownloader(Download,std::cref(file) );


	//create another operation
	std::cout << "[main]User started another operation" << std::endl;

	//Always check before joining a thread
	if (thDownloader.joinable()) 
	{
		thDownloader.join() ;
	}
	return 0;
}