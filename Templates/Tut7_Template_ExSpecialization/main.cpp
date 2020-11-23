#include <iostream>
#include <vector>

/*******************************************************************************
 *  PrettyPrinter Class                                                        *
 *******************************************************************************/
template<typename T>
class PrettyPrinter 
{
	T *m_pData;
public:
	PrettyPrinter(T *data) :m_pData(data) 
	{

	}
	void Print() {
		std::cout << "{" << *m_pData << "}" << std::endl;
	}

	T * GetData() {
		return m_pData;
	}
};

/*******************************************************************************
 *  PrettyPrinter Class(Specialized class for char* type                       *
 *******************************************************************************/
template<>
class PrettyPrinter<char*> 
{
	char *m_pData;
public:
	PrettyPrinter(char *data) :m_pData(data) {

	}
	void Print() {
		std::cout << "{" << m_pData << "}" << std::endl;
	}
	char * GetData() {
		return m_pData;
	}
};

/*******************************************************************************
 *  Specialized version of member function print for vector<int> type          *
 *******************************************************************************/
template<>
void PrettyPrinter<std::vector<int>>::Print() 
{
	std::cout << "{";
	for (const auto &x : *m_pData) {
		std::cout << x;
	}
	std::cout << "}" << std::endl;
}

/*******************************************************************************
 *  Main                                                                       *
 *******************************************************************************/
int main() 
{
	int data = 5;
	float f = 8.2f;
	std::string h = "hello";
	PrettyPrinter<int> p1(&data);
	p1.Print();
	PrettyPrinter<float> p2(&f);
	p2.Print();


	char *p{ "Hello world" };
	PrettyPrinter<char*> p3(p);
	p3.Print();
	char *pData = p3.GetData();
	std::vector<int> v{ 1,2,3,4,5 };
	PrettyPrinter<std::vector<int>> pv(&v);
	pv.Print();
	return 0;
}