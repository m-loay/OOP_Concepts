#include <iostream>     // std::cout
#include <vector>       // std::vector
#include <iomanip>
#include <utility>      // std::pair, std::make_pair

template<typename NODETYPE> class Stack;
template<typename NODETYPE>
class Stack
{
    public:
    Stack(const int &size=10);
    ~Stack();
    void push(const NODETYPE &data);
    std::pair <NODETYPE ,bool> pop (void);
    bool isFull(void)const;
    bool isEmpty(void)const;
    void print(void)const;

    private:
    int m_top;
    unsigned int m_size;
    const static unsigned int m_capacity{100};
    NODETYPE array[m_capacity];
};

template<typename NODETYPE>
Stack<NODETYPE>::Stack(const int & size)
:m_size((size>0 && size < m_capacity) ? size:  m_capacity - 1),
 m_top(-1)
{

}

template<typename NODETYPE>
Stack<NODETYPE>::~Stack()
{
    if(!isEmpty())
    {
        std::cout<<"Destrying the stack"<<std::endl;
    }
}

template<typename NODETYPE>
void Stack<NODETYPE>::push(const NODETYPE &data)
{
    if(!isFull())
    {
        array[++m_top] = data;
    }
}

template<typename NODETYPE>
std::pair <NODETYPE ,bool> Stack<NODETYPE>::pop (void)
{
    bool flag(false);
    NODETYPE data;
    if(!isEmpty())
    {
        data = array[m_top--];
        flag = true;
    }
    return std::make_pair(data, flag);
}

template<typename NODETYPE>
bool Stack<NODETYPE>::isEmpty(void) const
{
    return (m_top <= -1);
}

template<typename NODETYPE>
bool Stack<NODETYPE>::isFull(void) const
{
    bool flag(m_top >= static_cast<int> (m_capacity - 1));
    return flag;
}

template<typename NODETYPE>
void Stack<NODETYPE>::print(void) const
{
    if(isEmpty())
    {
        std::cout<<"The stck is empty"<<std::endl;
    }
    else
    {
        for(int i=m_top; i>=0; i--)
        {
            std::cout<<array[i]<<" ";
        }
        std::cout<<std::endl;
    }
}

int main () 
{
    Stack<int> iStack;
    iStack.push(6);
    iStack.push(7);
    iStack.push(2);
    iStack.push(1);
    iStack.push(0);
    iStack.print();

    auto ret = iStack.pop();
    std::cout<<"Poped Value "<<ret.first<<std::endl;
    iStack.print();

    ret = iStack.pop();
    std::cout<<"Poped Value "<<ret.first<<std::endl;
    iStack.print();

    return 0;
}