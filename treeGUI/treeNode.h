#ifndef TREE_NODE
#define TREE_NODE

template<class T>
class treeNode
{
	treeNode<T> *l;
	treeNode<T> *r;
public:
	T data;

	treeNode(const T& item = T(), treeNode<T> *lptr = nullptr, treeNode<T> *rptr = nullptr);
	
	treeNode<T> *left() const;
	treeNode<T> *right() const;
	void SetLeft(treeNode<T> *lptr);
	void SetRight(treeNode<T> *rptr);
};

#include "treeNode.cpp"

#endif