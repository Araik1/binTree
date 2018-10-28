#pragma once 
#include "binSTree.h" 

template <typename T>
void LOder(treeNode <T> *t, void Visit(T &Item))
{
	if (t != NULL)
	{
		LOder(t->left(), Visit());
		Visit(t->data);
		LOder(t->right(), Visit());

	}
}
template <typename T>
void NOder(treeNode <T> *t, void Visit(T &Item))
{
	if (t != NULL)
	{
		Visit(t->data);
		NOder(t->left(), Visit());
		NOder(t->right(), Visit());

	}
}
template <typename T>
void ROder(treeNode <T> *t, void Visit(T &Item))
{
	if (t != NULL)
	{

		ROder(t->left(), Visit());
		ROder(t->right(), Visit());
		Visit(t->data);

	}
}

template <typename T>
void CountLeaf(treeNode<T>*t, int &count)
{
	if (t != nullptr)
	{
		CountLeaf(t->left(), count);
		CountLeaf(t->right(), count);
		if ((t->left() == nullptr) && (t->right() == nullptr))
			count++;

	}
}
template <typename T>
int Depth(treeNode <T> *t)
{
	int DL, DR, DV;
	if (t == nullptr)
		DV = -1;
	else
	{
		DL = Depth(t->left());
		DR = Depth(t->right());
		DV = 1 + (DL > DR ? DL : DR);

	}
	return DV;

}
template <typename T>
void MakeSearchTree(const binSTree<T> *t)
{
	int n, i, d;
	cout << "input number of nodes" << endl;
	cin >> n;
	for (auto i = 0; i < n; i++)
	{
		cout << "input Node" << endl;
		cin >> d;
		t->Insert(d);
	}
}