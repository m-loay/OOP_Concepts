#include <iostream>     // std::cout
#include <vector>       // std::vector
#include <iomanip>
#include <utility>      // std::pair, std::make_pair


template<typename NODETYPE> class BTREE;

template<typename NODETYPE>
class Node
{
    friend class BTREE< NODETYPE >; // make BTREE a friend
    public:
    Node(const NODETYPE &data);
    NODETYPE getData() const;

    private:
    NODETYPE m_data;
    Node<NODETYPE> *m_leftPtr;
    Node<NODETYPE> *m_rightPtr;
};

template<typename NODETYPE>
Node<NODETYPE>::Node(const NODETYPE & data)
:m_data(data), m_leftPtr(0), m_rightPtr(0)
{

}

template<typename NODETYPE>
NODETYPE Node<NODETYPE>::getData()const
{
    return m_data;
}

template<typename NODETYPE>
class BTREE
{
    public:
    BTREE();
    ~BTREE();
    void insertNode(const NODETYPE &);
    void preOrderTraversal()const;
    void inOrderTraversal()const;
    void postOrderTraversal()const;

    private:
    Node<NODETYPE> *m_rootPtr{0};
    void insertNodeHelper(Node<NODETYPE> *&, const NODETYPE &);
    void preOrderTraversalHelper(Node<NODETYPE> *)const;
    void inOrderTraversalHelper(Node<NODETYPE> *)const;
    void postOrderTraversalHelper(Node<NODETYPE> *)const;
};

template<typename NODETYPE>
BTREE<NODETYPE>::BTREE()
{

}

template<typename NODETYPE>
BTREE<NODETYPE>::~BTREE()
{

}

template<typename NODETYPE>
void BTREE<NODETYPE>::insertNode(const NODETYPE &data)
{
    insertNodeHelper(m_rootPtr, data);
}

template<typename NODETYPE>
void BTREE<NODETYPE>::insertNodeHelper( Node<NODETYPE> *& rootPtr, const NODETYPE &data)
{
    if(rootPtr == 0)
    {
        rootPtr = new Node<NODETYPE> (data);
    }
    else
    {
        if(data < rootPtr->getData())
        {
            insertNodeHelper(rootPtr->m_leftPtr, data);
        }
        else if (data > rootPtr->getData())
        {
            insertNodeHelper( rootPtr->m_rightPtr, data);
        }
        else
        {
            /*Do noyhing*/
        }
    }
}

template<typename NODETYPE>
void BTREE<NODETYPE>::preOrderTraversal()const
{
    preOrderTraversalHelper(m_rootPtr);
}

template<typename NODETYPE>
void BTREE<NODETYPE>::preOrderTraversalHelper(Node<NODETYPE> *rootP)const
{
    if(rootP !=0)
    {
        std::cout<<rootP->getData()<<" ";
        preOrderTraversalHelper(rootP->m_leftPtr);
        preOrderTraversalHelper(rootP->m_rightPtr);
    }
}

template<typename NODETYPE>
void BTREE<NODETYPE>::inOrderTraversal()const
{
    inOrderTraversalHelper(m_rootPtr);
}

template<typename NODETYPE>
void BTREE<NODETYPE>::inOrderTraversalHelper(Node<NODETYPE> *rootP)const
{
    if(rootP !=0)
    {
        inOrderTraversalHelper(rootP->m_leftPtr);
        std::cout<<rootP->getData()<<" ";
        inOrderTraversalHelper(rootP->m_rightPtr);
    }
}

template<typename NODETYPE>
void BTREE<NODETYPE>::postOrderTraversal()const
{
    postOrderTraversalHelper(m_rootPtr);
}

template<typename NODETYPE>
void BTREE<NODETYPE>::postOrderTraversalHelper(Node<NODETYPE> *rootP)const
{
    if(rootP !=0)
    {
        postOrderTraversalHelper(rootP->m_leftPtr);
        postOrderTraversalHelper(rootP->m_rightPtr);
        std::cout<<rootP->getData()<<" ";
    }
}

int main () 
{
    BTREE<int> intBtree;
    std::vector<int> vect{ 27,13,42,6,17,33,48};
    int size(static_cast<int>(vect.size()));
    for (int i = 0; i < size; i++)
    {
        intBtree.insertNode(vect.at(i));
    }
    
    std::cout<<"PreOrder"<<std::endl;
    intBtree.preOrderTraversal();
    std::cout<<std::endl;

    std::cout<<"InOrder"<<std::endl;
    intBtree.inOrderTraversal();
    std::cout<<std::endl;

    std::cout<<"PostOrder"<<std::endl;
    intBtree.postOrderTraversal();
    std::cout<<std::endl;

    return 0;
}