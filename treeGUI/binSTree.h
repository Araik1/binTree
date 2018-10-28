#ifndef BIN_S_TREE
#define BIN_S_TREE

#include "treeNode.h"

template <class T>
class binSTree
{
	treeNode<T> *root, * current;
	treeNode<T> *p;

	unsigned s;

    treeNode<T> *getTreeNode(const T& item = T(), treeNode<T> *lptr = nullptr, treeNode<T> *rptr = nullptr);
	void freeTreeNode(treeNode<T> *p);
	treeNode<T> *FindNode(const T &item, treeNode <T> * &parent);

public:
	binSTree(const T& item = T());
	~binSTree();


	unsigned size() const;
	bool IsEmpty() const;
	void Insert(const T & item);
	treeNode<T>* getRoot() const;
	int Find(T & item);
	void Delete(const T& item);
	void DeleteTree(treeNode<T> *p);
	void ClearList();
    void Update(const T &item);

};

#include "binSTree.cpp"

#endif
