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
 *  Function Pointer to be used by Sort                                        *
 *******************************************************************************/
bool CompAs (int x, int y)
{
    return x>y;
}

bool CompDs (int x, int y)
{
    return x<y;
}

/*******************************************************************************
 *  Function Object to be used by Sort                                         *
 *******************************************************************************/
struct Comp
{
    bool operator ()(int x , int y)
    {
        return x > y;
    }
};

/*******************************************************************************
 *  Main                                                                       *
 *******************************************************************************/
int main() 
{
    //using function pointers

    //Assending
    std::cout<<"Sort Array using Function pointer Assending"<<std::endl;
    int arr1[]{ 1,6,8,4,0 };
    for (const auto &x : arr1){std::cout << x << " ";}
    std::cout << std::endl;
    bubbleSort(arr1, CompAs);
    for (const auto &x : arr1){std::cout << x << " ";}
    std::cout<<std::endl;

    //Descending
    std::cout<<"Sort Array using Function pointer Descending"<<std::endl;
    int arr2[]{ 1,6,8,4,0 };
    for (const auto &x : arr2){std::cout << x << " ";}
    std::cout << std::endl;
    bubbleSort(arr2, CompDs);
    for (const auto &x : arr2){std::cout << x << " ";}
    std::cout<<std::endl;

    //using function objects Ascending
    Comp comp;
    std::cout<<"Sort Array using Function pointer function objects"<<std::endl;
    int arr3[]{ 1,6,8,4,0 };
    for (const auto &x : arr3){std::cout << x << " ";}
    std::cout << std::endl;
    bubbleSort(arr3, comp);
    for (const auto &x : arr3){std::cout << x << " ";}
    std::cout<<std::endl;

    return 0;
}