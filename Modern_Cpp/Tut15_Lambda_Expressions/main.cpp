#include <iostream>
/*******************************************************************************
 *  Template Sort                                                              *
 *******************************************************************************/
template <typename T, int size, typename comp>
void bubbleSort(T(&array)[size], comp cp)
{
	for (size_t i = 0; i < size-1; i++)
	{
		for (size_t j = 0; j < size-1; j++)
		{
			if(cp(array[j], array[j+1]))
			{
				T temp = std::move(array[j]);
				array[j] = std::move(array[j+1]);
				array[j+1] = std::move(temp);
			}
		}
	}
}

/*******************************************************************************
 *  Template Operation Elements                                                *
 *******************************************************************************/
template <typename T, int size, typename Callback>
void ForEach(T(&array)[size], Callback cb)
{
	for (size_t i = 0; i < size; i++)
	{
		cb(array[i]);
	}
}

/*******************************************************************************
 *  Careate class Product                                                      *
 *******************************************************************************/
class Product
{
private:
	std::string name;
	float price;
public:
	Product(const std::string &nm , const float &p):name(nm),price(p)
	{

	}

	void AssignFinalPrice()
	{
		float taxes[]{12,5,5};
		float basePrice{price};
		ForEach(taxes,[&basePrice,this](float tax)
		{
			float taxedPrice = basePrice * tax /100.0f;
			this->price += taxedPrice;
		});
	}

	float getPrice()const
	{
		return price;
	}
	~Product()
	{

	}
};


/*******************************************************************************
 *  Main                                                                       *
 *******************************************************************************/
int main() 
{
	//using lambda expression(Ascending)
	std::cout<<"Sort Array using lambda expression Ascending"<<std::endl;
	int arr1[]{ 1,6,8,4,0 };
    for(auto const &x:arr1){[&x]{std::cout<<x<<" ";};};
	//ForEach(arr1,[] (auto x){std::cout<<x<<" ";});
	std::cout << std::endl;

	auto compAs = [] (auto x, auto y){return x>y;};
    bubbleSort(arr1, compAs);
	ForEach(arr1,[] (auto x){std::cout<<x<<" ";});
	std::cout<<std::endl;

	//using lambda expression(Designing)
	std::cout<<"Sort Array using lambda expression Desinding"<<std::endl;
	int arr2[]{ 1,6,8,4,0 };
	ForEach(arr2,[] (auto x){std::cout<<x<<" ";});
	std::cout << std::endl;

	auto compDs = [] (auto x, auto y){return x<y;};
    bubbleSort(arr2, compDs);
	ForEach(arr2,[] (auto x){std::cout<<x<<" ";});
	std::cout << std::endl;

	//using lambda expression(Add offset to Array)
	std::cout<<"Sort Array using lambda expression Ascending + Add offset "<<std::endl;
	int arr3[]{ 1,6,8,4,0 };
	int offset =5;
	ForEach(arr3,[] (auto x){std::cout<<x<<" ";});
	std::cout << std::endl;

    bubbleSort(arr3, compAs);
	ForEach(arr3,[] (auto x){std::cout<<x<<" ";});
	std::cout << std::endl;
	ForEach(arr3,[offset] (auto &x){x+=offset;});
	ForEach(arr3,[] (auto x){std::cout<<x<<" ";});
	std::cout<<std::endl;

	//using lambda expression tp calculate tax products
	std::cout<<"using lambda expression tp calculate tax products"<<std::endl;
	Product p{"watch", 500};
	p.AssignFinalPrice();
	std::cout<<"Final Price = "<<p.getPrice()<<std::endl;

	return 0;
}