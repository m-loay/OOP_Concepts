// find_if example
#include <iostream>     // std::cout
#include <vector>       // std::vector
#include <iomanip>
#include <utility>      // std::pair, std::make_pair


template<typename NODETYPE> class Qeue;

template<typename NODETYPE>
class Node
{
    friend class Qeue< NODETYPE >; // make Qeue a friend
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
class Qeue
{
    public:
    Qeue();
    ~Qeue();
    void enqeue(const NODETYPE &);
    bool deqeue(void);
    bool isEmpty()const;
    void print() const;

    private:
    Node<NODETYPE> *fPtr;
    Node<NODETYPE> * ePtr;
    Node<NODETYPE> *getNewNode(const NODETYPE &);
};

template<typename NODETYPE>
Qeue<NODETYPE>::Qeue()
:fPtr(0), ePtr(0)
{

}

template<typename NODETYPE>
Qeue<NODETYPE>::~Qeue()
{
    if(!isEmpty())
    {
        std::cout<<"Destrying the Qeue"<<std::endl;
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
void Qeue<NODETYPE>::enqeue(const NODETYPE &data)
{
    Node<NODETYPE>* newPtr(getNewNode(data));

    if(isEmpty())
    {
        fPtr = ePtr = newPtr;
    }
    else
    {
        newPtr->nextPtr = fPtr;
        fPtr = newPtr;
    }
}

template<typename NODETYPE>
bool Qeue<NODETYPE>::deqeue(void)
{
    bool flag;
    if(isEmpty())
    {
        flag = false;
    }
    else
    {
        if(fPtr == ePtr)
        {
            fPtr = ePtr = 0;
        }
        else
        {
            Node<NODETYPE>* tmpPtr(ePtr);
            Node<NODETYPE>* currentPtr(fPtr);
            while(currentPtr->nextPtr != ePtr)
            {
                currentPtr = currentPtr->nextPtr;
            }
            ePtr = currentPtr;
            currentPtr->nextPtr=0;
            delete tmpPtr;
            flag = true;
        }
    }
    return flag;
}

template<typename NODETYPE>
bool Qeue<NODETYPE>::isEmpty() const
{
    return (fPtr == 0);
}

template<typename NODETYPE>
void Qeue<NODETYPE>::print() const
{
    if(isEmpty())
    {
        std::cout<<"The Qeue is empty"<<std::endl;
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
Node<NODETYPE> *Qeue<NODETYPE>::getNewNode(const NODETYPE &data)
{
    return new Node<NODETYPE>(data);
}

int main () 
{
    Qeue<int> iList;
    iList.enqeue(6);
    iList.enqeue(7);
    iList.enqeue(2);
    iList.enqeue(1);
    iList.enqeue(0);
    iList.print();

    iList.deqeue();
    iList.print();

    iList.deqeue();
    iList.print();

    return 0;
}