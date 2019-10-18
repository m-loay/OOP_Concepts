/*
 * TreeNode.h
 *
 *  Created on: Oct 2, 2016
 *      Author: modys
 */

#ifndef TREENODE_H_
#define TREENODE_H_

template <typename NODETYPE> class TreeList;

template <typename NODETYPE>
class TreeNode
{
	friend class TreeList<NODETYPE>;
public:

	TreeNode(const NODETYPE &val)
		:left(0),right(0),data(val)
			{

			}
	NODETYPE getData()const
	{
		return data;
	}


private:
	TreeNode<NODETYPE>*left;
	TreeNode<NODETYPE>*right;
	NODETYPE data;
};


#endif /* TREENODE_H_ */
