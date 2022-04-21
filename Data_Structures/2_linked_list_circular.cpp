// find_if example
#include <iostream>     // std::cout
#include <vector>       // std::vector
#include <iomanip>
#include <utility>      // std::pair, std::make_pair


template<typename NODETYPE> class List;

template<typename NODETYPE>
class Node
{
    friend class List< NODETYPE >; // make List a friend
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
class List
{
    public:
    List();
    ~List();
    void insertAtFront(const NODETYPE &);
    void insertAtBack(const NODETYPE &);
    bool removeFromFront(void);
    bool removeFromBack(void);
    bool remove (const NODETYPE &);
    bool findInList(const NODETYPE &)const;
    bool isEmpty()const;
    void print() const;

    private:
    Node<NODETYPE> *fPtr;
    Node<NODETYPE> * ePtr;
    std::pair <Node<NODETYPE> *,bool> findNode(const NODETYPE &) const;
    Node<NODETYPE> *getNewNode(const NODETYPE &);
};

template<typename NODETYPE>
List<NODETYPE>::List()
:fPtr(0), ePtr(0)
{

}

template<typename NODETYPE>
List<NODETYPE>::~List()
{
    if(!isEmpty())
    {
        std::cout<<"Destrying the linked List"<<std::endl;
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
void List<NODETYPE>::insertAtFront(const NODETYPE &data)
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
        ePtr->nextPtr = fPtr;
    }
}

template <typename NODETYPE>
void List<NODETYPE>::insertAtBack(const NODETYPE & data)
{
    Node<NODETYPE>* newPtr(getNewNode(data));
    if(isEmpty())
    {
        fPtr = ePtr = newPtr;
    }
    else
    {
        ePtr->nextPtr = newPtr;
        ePtr = newPtr;
        ePtr->nextPtr = fPtr;
    }
}

template<typename NODETYPE>
bool List<NODETYPE>::removeFromFront(void)
{
    bool flag;
    if(isEmpty())
    {
        flag = false;
    }
    else
    {
        Node<NODETYPE> * tempPtr(fPtr);
        if(fPtr == ePtr)
        {
            fPtr = ePtr = 0;
        }
        else
        {
            fPtr = fPtr->nextPtr;
            ePtr->nextPtr = fPtr;
        }
        delete tempPtr;
        flag = true;
    }
    return flag;
}

template<typename NODETYPE>
bool List<NODETYPE>::removeFromBack(void)
{
    bool flag;
    if(isEmpty())
    {
        flag = false;
    }
    else
    {
        Node<NODETYPE>* tmpPtr(ePtr);
        if(fPtr == ePtr)
        {
            fPtr = ePtr = 0;
        }
        else
        {
            Node<NODETYPE>* currentPtr(fPtr);
            while(currentPtr->nextPtr != ePtr)
            {
                currentPtr = currentPtr->nextPtr;
            }
            ePtr = currentPtr;
            currentPtr->nextPtr=fPtr;
            delete tmpPtr;
            flag = true;
        }
    }
    return flag;
}

template<typename NODETYPE>
bool List<NODETYPE>::remove(const NODETYPE &data)
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
        else if(fPtr->getData() == data)
        {
            Node<NODETYPE>* tmpPtr(fPtr);
            fPtr = fPtr->nextPtr;
            ePtr->nextPtr = fPtr;
            delete tmpPtr;
            flag = true;

        }
        else
        {
            Node<NODETYPE>* currentPtr(fPtr->nextPtr);
            Node<NODETYPE>* prevPtr(fPtr);
            while(currentPtr != 0 && currentPtr->getData()!= data)
            {
                prevPtr = currentPtr;
                currentPtr = currentPtr->nextPtr;
               
            }

            if(currentPtr != 0)
            {
                prevPtr->nextPtr = currentPtr->nextPtr;
                delete currentPtr;
                flag = true;
            }
            else
            {
                flag = false;
            }
        }
    }
    return flag;
}


template<typename NODETYPE>
bool List<NODETYPE>::findInList(const NODETYPE &data)const
{
    const auto ret = findNode(data);
    if(ret.first == 0 && ret.second == false)
    {
        std::cout<<"The list is Empty"<<std::endl;
    }
    else if(ret.second == false)
    {
        std::cout<<"Element "<< data <<" does not exist in the list"<<std::endl;
    }
    else
    {
         std::cout<<"Element "<< ret.first->getData() <<" found in the list"<<std::endl;
    }
    return ret.second;
}

template<typename NODETYPE>
bool List<NODETYPE>::isEmpty() const
{
    return (fPtr == 0);
}

template<typename NODETYPE>
void List<NODETYPE>::print() const
{
    if(isEmpty())
    {
        std::cout<<"The list is empty"<<std::endl;
    }
    else
    {
        Node<NODETYPE> *currentPtr(fPtr);
        do
        {
            std::cout<<currentPtr->m_data<< " , ";
            currentPtr = currentPtr->nextPtr;
        } 
        while (currentPtr != fPtr);
        
        std::cout<<std::endl;
    }

}

template<typename NODETYPE>
Node<NODETYPE> *List<NODETYPE>::getNewNode(const NODETYPE &data)
{
    return new Node<NODETYPE>(data);
}

template<typename NODETYPE>
std::pair <Node<NODETYPE> *,bool> List<NODETYPE>::findNode(const NODETYPE &data)const
{
    bool flag = false;
    Node<NODETYPE> *findPtr(fPtr);

    if(isEmpty())
    {
        flag = false;
        findPtr = 0;
    }
    else
    {
        do
        {
            if(findPtr->getData() == data)
            {
                flag = true;
                break;
            }
            findPtr = findPtr->nextPtr;
        } 
        while (findPtr != fPtr);        
    }
    return std::make_pair(findPtr, flag);
}


int main () 
{
    List<int> iList;
    iList.insertAtFront(6);
    iList.insertAtFront(7);
    iList.insertAtFront(2);
    iList.insertAtFront(1);
    iList.insertAtFront(0);
    iList.insertAtBack(8);
    iList.print();

    iList.removeFromFront();
    iList.removeFromBack();
    iList.print();

    iList.findInList(2);
    iList.findInList(100);
    iList.print();

    iList.remove(6);
    iList.print();

    return 0;
}