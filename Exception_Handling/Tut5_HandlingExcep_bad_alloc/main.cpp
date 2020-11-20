#include <iostream>

int main()
{
	double *ptr[50];

	// aim each ptr[i] at a big block of memory
	try
	{
		// allocate memory for ptr[ i ]; new throws bad_alloc on failure
		for ( int i = 0; i < 50; ++i )
		{
			ptr[i] = new double[UINT16_MAX*10000U];
			std::cout << "ptr[" << i << "] points to 50,000,000 new doubles\n";
		} // end for
	} // end try
	catch(std::bad_alloc &memoryAllocationException)
	{
		std::cerr << "Exception occurred: "<< memoryAllocationException.what() <<std::endl;
	} // end catch
} // end main