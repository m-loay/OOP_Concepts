#include <iostream>
#include <new> // set_new_handler function prototype
#include <cstdlib> // abort function prototype
using namespace std;

 // using set_new_handler to handle failed memory allocation
void customNewHandler()
{
	std::cerr << "customNewHandler was called";
	abort();
} // end function customNewHandler

 int main()
{
 	double *ptr[ 50 ];

	// specify that customNewHandler should be called on
	// memory allocation failure
	set_new_handler( customNewHandler );

	// aim each ptr[i] at a big block of memory; customNewHandler will be
	// called on failed memory allocation
	for ( int i = 0; i < 50; ++i )
	{
		ptr[ i ] = new double[UINT16_MAX*10000U]; // may throw exception
		cout << "ptr[" << i << "] points to 50,000,000 new doubles\n";
	} // end for
} // end main