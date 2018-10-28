#ifndef BIN_S_TREE1
#define BIN_S_TREE1

#include "binSTree.h"

template<class T>
treeNode<T>* binSTree<T>::getTreeNode(const T & item, treeNode<T>* lptr, treeNode<T>* rptr)
{
	treeNode<T> *p;
	p = new treeNode<T>(item, lptr, rptr);

	//возвращает адрес созданного узла
	//если памяти не хватило вернет nullptr
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
	//узел D имеет двух сыновей
		else
		{
			// найти и отсоединить заменяющий узел R для узла D.
			// в левом поддереве узла D найти максимальный узел
			// из всех узлов, меньших чем узел D.
			// отсоединить этот узел от дерева.
			// PofRNodePtr  - указатель на родителя заменяющего узла
			treeNode<T> *PofRNodePtr = DNodePtr;

			// первой возможной заменой является левый сын узла D
			RNodePtr = DNodePtr->left();

			while (RNodePtr->right() != nullptr)
			{
				PofRNodePtr = RNodePtr;
				RNodePtr = RNodePtr->right();
			}

			if (PofRNodePtr == DNodePtr)
				// левый сын удаляемого узла является заменяющим
				// присоединить правое поддерево узла D к узлу R
				RNodePtr->setRight(DNodePtr->right());
			else
			{
				// мы спустились вниз по правой ветви как минимум на один узел.
				// удалить заменяющий узел из дерева,
				// присоединив его правую ветвь к родительскому узлу
				PofRNodePtr->setRight(RNodePtr->left());
			}
		}

	// завершить присоединение к родительскому узлу.
	// удалить корневой узел. назначить новый корень.
	if (RNodePtr == NULL)
		root = RNodePtr;
	// присоединить узел R к узлу P с правильной стороны
	else if (DNodePtr->data() < PNodePtr->data())
		PNodePtr->setLeft(RNodePtr);
	else
		PNodePtr->setRight(RNodePtr);

	// удалить узел из памяти и уменьшить размер списка
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
