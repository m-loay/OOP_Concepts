/*
 * main.cpp
 *
 *  Created on: Oct 2, 2016
 *      Author: modys
 */
#include <iostream>
#include "TreeList.h"

using namespace std;

int main()
{
	TreeList<int>intTree;
	intTree.insertNode(27);
	intTree.insertNode(13);
	intTree.insertNode(42);
	intTree.insertNode(6);
	intTree.insertNode(17);
	intTree.insertNode(33);
	intTree.insertNode(48);

	cout<<"inOrderTraversal"<<endl;
	intTree.inOrderTraversal();

	cout<<"\npreOrderTraversal"<<endl;
	intTree.preOrderTraversal();

	cout<<"\npostOrderTraversal"<<endl;
	intTree.postOrderTraversal();

}
