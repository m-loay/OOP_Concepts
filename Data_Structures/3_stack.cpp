#include <iostream>     // std::cout
#include <vector>       // std::vector
#include <iomanip>
#include <utility>      // std::pair, std::make_pair


template<typename NODETYPE> class Stack;

template<typename NODETYPE>
class Node
{
    friend class Stack< NODETYPE >; // make stack a friend
    public:
    Node(const NODETYPE &data);
    NODETYPE getData() const;

    private:
    NODETYPE m_data;
    Node<NODETYPE> *nextPtr;
};

template<typename NODETYPE>
Node<NODETYPE>::Node(const NODETYPE & data)
:m_data(data), nextPtr(0)
{

}

template<typename NODETYPE>
NODETYPE Node<NODETYPE>::getData()const
{
    return m_data;
}

template<typename NODETYPE>
class Stack
{
    public:
    Stack();
    ~Stack();
    void push(const NODETYPE &);
    std::pair <NODETYPE ,bool> pop(void);
    bool isEmpty()const;
    void print() const;

    private:
    Node<NODETYPE> *fPtr;
    Node<NODETYPE> *getNewNode(const NODETYPE &);
};

template<typename NODETYPE>
Stack<NODETYPE>::Stack()
:fPtr(0)
{

}

template<typename NODETYPE>
Stack<NODETYPE>::~Stack()
{
    if(!isEmpty())
    {
        std::cout<<"Destrying the stack"<<std::endl;
        Node<NODETYPE> *currentPtr(fPtr);
        Node<NODETYPE> *tempPtr;

        while(currentPtr != 0)
        {
            tempPtr = currentPtr;
            currentPtr = currentPtr->nextPtr;
            delete tempPtr;
        }
    }
}

template<typename NODETYPE>
void Stack<NODETYPE>::push(const NODETYPE &data)
{
    Node<NODETYPE>* newPtr(getNewNode(data));

    if(isEmpty())
    {
        fPtr = newPtr;
    }
    else
    {
        newPtr->nextPtr = fPtr;
        fPtr = newPtr;
    }
}

template<typename NODETYPE>
std::pair <NODETYPE ,bool> Stack<NODETYPE>::pop(void)
{
    bool flag;
    NODETYPE data;
    if(isEmpty())
    {
        flag = false;
    }
    else
    {
        Node<NODETYPE> * tempPtr(fPtr);
        data = tempPtr->getData();
        fPtr = fPtr->nextPtr;
        delete tempPtr;
        flag = true;
    }
    return std::make_pair(data, flag);
}

template<typename NODETYPE>
bool Stack<NODETYPE>::isEmpty() const
{
    return (fPtr == 0);
}

template<typename NODETYPE>
void Stack<NODETYPE>::print() const
{
    if(isEmpty())
    {
        std::cout<<"The list is empty"<<std::endl;
    }
    else
    {
        Node<NODETYPE> *currentPtr(fPtr);
        while (currentPtr != 0)
        {
            std::cout<<currentPtr->m_data<< " , ";
            currentPtr = currentPtr->nextPtr;
        }
        std::cout<<std::endl;
    }
}

template<typename NODETYPE>
Node<NODETYPE> *Stack<NODETYPE>::getNewNode(const NODETYPE &data)
{
    return new Node<NODETYPE>(data);
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