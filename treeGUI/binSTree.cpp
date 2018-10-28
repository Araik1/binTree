#ifndef BIN_S_TREE1
#define BIN_S_TREE1

#include "binSTree.h"

template<class T>
treeNode<T>* binSTree<T>::getTreeNode(const T & item, treeNode<T>* lptr, treeNode<T>* rptr)
{
	treeNode<T> *p;
	p = new treeNode<T>(item, lptr, rptr);

	//���������� ����� ���������� ����
	//���� ������ �� ������� ������ nullptr
	return p;
}

template<class T>
void binSTree<T>::freeTreeNode(treeNode<T>* p)
{
	delete p;
}

template<class T>
treeNode<T>* binSTree<T>::FindNode(const T & item, treeNode<T>*& parent)
{
	treeNode <T> *t = root;
	parent = nullptr;
	while (t != nullptr)
	{
		if (item == t->data)
			break;
		else
		{
			parent = t;
			if (item < t->data)
				t = t->GetLch();
			else
				t = t->GetRch();
		}
	}
	return t;
}

template<class T>
binSTree<T>::binSTree(const T & item)
{
	root = getTreeNode(item);
}

template<class T>
binSTree<T>::~binSTree()
{
}

template<class T>
unsigned binSTree<T>::size() const
{
	return s;
}

template<class T>
bool binSTree<T>::IsEmpty() const
{
	if (s == 0)
		return true;
	else
		return false;

}

template<class T>
void binSTree<T>::DeleteTree(treeNode<T> *p)
{
	if (p != nullptr)
	{
		DeleteTree(p->left());
		DeleteTree(p->right());

        freeTreeNode(p);
	}
}

template <class T>
void binSTree<T>::ClearList() {
	DeleteTree(root);
	root = nullptr;
}

template<class T>
void binSTree<T>::Update(const T &item)
{
    if ((current != nullptr && current->get_data()) == item)
        current->set_data(item);
	else
        Insert(item);
}

template<class T>
void binSTree<T>::Insert(const T & item)
{
	treeNode<T> *t = root;
	treeNode<T> *parent = nullptr;
	treeNode<T> *newnode = getTreeNode(item);
	while (t != nullptr)
	{
		parent = t;
		if (item < t->data)
			t = t->left();
		else
			t = t->right();

	}
	if (parent == nullptr)
		root = newnode;
	else
		if (item < parent->data)
			parent->SetLeft(newnode);
		else
			parent->SetRight(newnode);

	current = newnode;
	s++;

}

template <class T>
void binSTree<T>::Delete(const T& item)
{
	treeNode<T> *DNodePtr, *PNodePtr, *RNodePtr;
	
	if ((DNodePtr = FindNode(item, PNodePtr)) == nullptr)
		return;

	if (DNodePtr->right() == nullptr)
		RNodePtr = DNodePtr->left();
	else
		if (DNodePtr->left() == nullptr)
			RNodePtr = DNodePtr->right();
	//���� D ����� ���� �������
		else
		{
			// ����� � ����������� ���������� ���� R ��� ���� D.
			// � ����� ��������� ���� D ����� ������������ ����
			// �� ���� �����, ������� ��� ���� D.
			// ����������� ���� ���� �� ������.
			// PofRNodePtr  - ��������� �� �������� ����������� ����
			treeNode<T> *PofRNodePtr = DNodePtr;

			// ������ ��������� ������� �������� ����� ��� ���� D
			RNodePtr = DNodePtr->left();

			while (RNodePtr->right() != nullptr)
			{
				PofRNodePtr = RNodePtr;
				RNodePtr = RNodePtr->right();
			}

			if (PofRNodePtr == DNodePtr)
				// ����� ��� ���������� ���� �������� ����������
				// ������������ ������ ��������� ���� D � ���� R
				RNodePtr->setRight(DNodePtr->right());
			else
			{
				// �� ���������� ���� �� ������ ����� ��� ������� �� ���� ����.
				// ������� ���������� ���� �� ������,
				// ����������� ��� ������ ����� � ������������� ����
				PofRNodePtr->setRight(RNodePtr->left());
			}
		}

	// ��������� ������������� � ������������� ����.
	// ������� �������� ����. ��������� ����� ������.
	if (RNodePtr == NULL)
		root = RNodePtr;
	// ������������ ���� R � ���� P � ���������� �������
	else if (DNodePtr->data() < PNodePtr->data())
		PNodePtr->setLeft(RNodePtr);
	else
		PNodePtr->setRight(RNodePtr);

	// ������� ���� �� ������ � ��������� ������ ������
	freeTreeNode(DNodePtr);
	size--;
}


template<class T>
treeNode<T>* binSTree<T>::getRoot() const
{
	return root;
}

template<class T>
int binSTree<T>::Find(T & item)
{
    treeNode <T> *parent;
	current = FindNode(item, parent);
	if (current != nullptr)
	{
		item = current->data;
		return 1;

	}
	else
		return 0;
}



#endif
