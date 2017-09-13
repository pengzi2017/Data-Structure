//二叉树
#ifndef BINARYTREE_H
#define BINARYTREE_H
#include<iostream>
#include"queue.h"
using namespace std;

template<class T>
struct BinTreeNode
{
	T data;
	BinTreeNode<T> *leftChild, rightChild;
	BinTreeNode()leftChild(NULL), rightChild(NULL) {};
	BinTreeNode(T x, BinTreeNode<T> *lc=NULL, BinTreeNode<T> *rc=NULL) :data(x), leftChild(lc), rightChild(rc) {};
};

template<class T>
class BinaryTree
{
public:
	BinaryTree() :root(NULL) {};
	BinaryTree(BinaryTree<T> &r) { root = copy(r.root); };
	~BinaryTree() { destroy(root); };
	bool isEmpty() { return root == NULL ? true : false; };
	BinTreeNode<T> *parent(BinTreeNode<T> *statr,BinTreeNode<T> *current);//返回current父节点
	BinTreeNode<T> *leftChild(BinTreeNode<T> *current) { return current->leftChild; };
	BinTreeNode<T> *rightChild(BinTreeNode<T> *current) { return current->rightChild; };
	int hight(BinTreeNode<T>*subTree)const;//???????????????
	int size(BinTreeNode<T>*subTree)const;//树的节点数?????????????
	BinTreeNode<T> *getRoot() { return root; };
	void preOrder(BinTreeNode<T> *subTree,void(*visit)(BinTreeNode<T> *p));//前序遍历
	void inOrder(BinTreeNode<T> *subTree, void(*visit)(BinTreeNode<T> *p));//中序遍历
	void levelOrder(void(*visit)(BinTreeNode<T> *p));//层次遍历,借助队列
	void postOrder(BinTreeNode<T> *subTree, void(*visit)(BinTreeNode<T> *p));//后序遍历
	BinTreeNode<T> *find(BinTreeNode<T> *subTree,T &item);
	void CreatBinTree(istream &in, BinTreeNode<T> *subTree);//从文件读入二叉树
private:
	BinTreeNode<T> *root;
	void destory(BinTreeNode<T> *subTree);
	BinTreeNode<T> *copy(BinTreeNode<T> *subTree);
};
#endif // !TREE_H

template<class T>
BinTreeNode<T>* BinaryTree<T>::parent(BinTreeNode<T>*start,BinTreeNode<T>* current)
{
	if (start == NULL)return NULL;
	if (start->leftChild == current || start->rightChild == current)return start;
	BinTreeNode<T> *p;
	if (p = parent(start->leftChild, current) != NULL)return p;
	else
		return parent(start->rightChild, current);
}

template<class T>
int BinaryTree<T>::hight(BinTreeNode<T> *subTree)const
{
	if (subTree == NULL)return 0;
	else
	{
		int i = hight(subTree->leftChild);
		int j = hight(subTree->rightChild);
		return (i < j) ? j + 1 : i + 1;
	}
}

template<class T>
int BinaryTree<T>::size(BinTreeNode<T>*subTree)const
{
	if (subTree == NULL)return 0;
	else
		return 1 + size(subTree->leftChild) + size(subTree->rightChild);
}

template<class T>
void BinaryTree<T>::preOrder(BinTreeNode<T> *subTree, void(*visit)(BinTreeNode<T>*p))
{
	if (subTree != NULL)
	{
		visit(subTree);
		preOrder(subTree->leftChild,visit);
		preOrder(subTree->rightChild,visit);
	}
}

template<class T>
void BinaryTree<T>::inOrder(BinTreeNode<T> *subTree, void(*visit)(BinTreeNode<T>*p))
{
	if (subTree != NULL)
	{
		inOrder(subTree->leftChild,visit);
		visit(subTree);
		inOrder(subTree->rightChild,visit);
	}
}

template<class T>
void BinaryTree<T>::levelOrder(void(*visit)(BinTreeNode<T>*p))
{
	LinkQueue<BinTreeNode<T> *> Q;
	BinTreeNode<T> *p = root;
	Q.enQueue(p);
	while (!Q.isEmpty())
	{
		Q.deQueue(p);
		visit(p);
		if (p->leftChild != NULL)Q.enQueue(p->leftChild);
		if (p->rightChild != NULL)Q.enQueue(p->rightChild);
	}
}

template<class T>
void BinaryTree<T>::postOrder(BinTreeNode<T> *subTree, void(*visit)(BinTreeNode<T>*p))
{
	if (subTree != NULL)
	{
		postOrder(subTree->leftChild,visit);
		postOrder(subTree->rightChild,visit);
		visit(subTree);
	}
}

template<class T>
BinTreeNode<T>* BinaryTree<T>::find(BinTreeNode<T>* subTree, T & item)
{
	return NULL;
}

template<class T>
void BinaryTree<T>::CreatBinTree(istream & in, BinTreeNode<T>* subTree)
{

}

template<class T>
void BinaryTree<T>::destory(BinTreeNode<T>* subTree)
{
	if (subTree != NULL)
	{
		destoty(subTree->leftChild);
		destory(subTree->rightChild);
		delete subTree;
	}
}

template<class T>
BinTreeNode<T>* BinaryTree<T>::copy(BinTreeNode<T>* subTree)
{
	if (subTree == NULL)return NULL;
	BinTreeNode<T> *temp = new BinTreeNode<T>;
	temp->data = subTree->data;
	temp->leftChild = copy(subTree->leftChild);
	temp->rightChild = copy(subTree->rightChild);
	return temp;
}
