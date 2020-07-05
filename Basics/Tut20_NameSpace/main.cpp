/*
 * main.cpp
 *
 *  Created on: Jun 14, 2016
*/

#include<iostream>

namespace Math
{
	float calculateAverage(const float &x, const float &y)
	{
		return (x+y)/2;
	}
	
} // namespace Math

namespace Basic
{
	float calculateAverage(const float &x, const float &y)
	{
		return (x+y)/2;
	}	
} // namespace Basic



int main()
{
	float x(12.5f);
	float y(10.2f);

	//Call calculateAverage using full qualified name
	std::cout<<"Output from Math Namespace --> "<<Math::calculateAverage(x,y)<<std::endl;
	std::cout<<"Output from Basic Namespace --> "<<Basic::calculateAverage(x,y)<<std::endl;

	//Call using declarative and open specific type
	using namespace Math;
	std::cout<<"Output from Math Namespace --> "<<calculateAverage(x,y)<<std::endl;
	// using namespace Basic;
	// std::cout<<"Output from Basic Namespace --> "<<calculateAverage(x,y)<<std::endl;
	//will cause compilation issue.
}
