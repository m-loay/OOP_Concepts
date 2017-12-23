/*
 * TreeList.h
 *
 *  Created on: Oct 2, 2016
 *      Author: modys
 */

#ifndef TREELIST_H_
#define TREELIST_H_
#include <iostream>
#include "TreeNode.h"
using namespace std;

template <typename NODETYPE>
class TreeList
{
public:
	TreeList();
	void insertNode (const NODETYPE &);
	void preOrderTraversal()const;
	void inOrderTraversal()const;
	void postOrderTraversal()const;

private:
	TreeNode<NODETYPE>*root;
	TreeNode <NODETYPE> *getNewNode(const NODETYPE &);
	void insertNodeHelper (TreeNode<NODETYPE>**,const NODETYPE &);
	void preOrderTraversalHelper(TreeNode<NODETYPE>*)const;
	void inOrderTraversalHelper(TreeNode<NODETYPE>*)const;
	void postOrderTraversalHelper(TreeNode<NODETYPE>*)const;
};

template <typename NODETYPE>
TreeList<NODETYPE>::TreeList()
:root(0)
{

}

template <typename NODETYPE>
void TreeList<NODETYPE>::insertNode(const NODETYPE &val)
{
	insertNodeHelper(&root,val);
}

template <typename NODETYPE>
void TreeList<NODETYPE>::insertNodeHelper(TreeNode<NODETYPE>**r,const NODETYPE &val)
{
	if(*r == 0)
	{
		*r = getNewNode(val);
	}
	else
	{
		if(val <(*r)->data)
			insertNodeHelper(&((*r)->left),val);
		else if (val >(*r)->data)
			insertNodeHelper(&((*r)->right),val);
		else
			return;
	}
}

template <typename NODETYPE>
void TreeList<NODETYPE>::preOrderTraversal()const
{
	preOrderTraversalHelper(root);
}

template <typename NODETYPE>
void TreeList<NODETYPE>::preOrderTraversalHelper(TreeNode<NODETYPE>*p)const
{
	if(p!=0)
	{
		cout<<p->data<<" ";
		preOrderTraversalHelper(p->left);
		preOrderTraversalHelper(p->right);
	}
}

template <typename NODETYPE>
void TreeList<NODETYPE>::inOrderTraversal()const
{
	inOrderTraversalHelper(root);
}

template <typename NODETYPE>
void TreeList<NODETYPE>::inOrderTraversalHelper(TreeNode<NODETYPE>*p)const
{
	if(p!=0)
	{
		inOrderTraversalHelper(p->left);
		cout<<p->data<<" ";
		inOrderTraversalHelper(p->right);
	}
}

template <typename NODETYPE>
void TreeList<NODETYPE>::postOrderTraversal()const
{
	postOrderTraversalHelper(root);
}

template <typename NODETYPE>
void TreeList<NODETYPE>::postOrderTraversalHelper(TreeNode<NODETYPE>*p)const
{
	if(p!=0)
	{
		postOrderTraversalHelper(p->left);
		postOrderTraversalHelper(p->right);
		cout<<p->data<<" ";
	}
}

template <typename NODETYPE>
TreeNode <NODETYPE> * TreeList<NODETYPE>::getNewNode(const NODETYPE &value)
{
	return new TreeNode<NODETYPE>(value);
}
#endif /* TREELIST_H_ */
