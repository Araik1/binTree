#ifndef TREE_NODE1
#define TREE_NODE1

#include "treeNode.h"

template<class T>
treeNode<T>::treeNode(const T& item, treeNode<T> *lptr, treeNode<T> *rptr)
{
	data = item;
	l = lptr;
	r = rptr;
}

template<class T>
treeNode<T>* treeNode<T>::left() const
{
	return l;
}

template<class T>
treeNode<T>* treeNode<T>::right() const
{
	return r;
}

template<class T>
void treeNode<T>::SetLeft(treeNode<T>* lptr)
{
	l = lptr;
}

template<class T>
void treeNode<T>::SetRight(treeNode<T>* rptr)
{
	r = rptr;
}


#endif