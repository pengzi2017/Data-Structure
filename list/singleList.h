//单链表；
#ifndef SINGLELIST_H
#define SINGLELIST_H
#include<iostream>
#include"list.h"
using namespace std;

template<class T>
struct ListNode
{
	T data;
	ListNode<T> *link;         //注意这个指针类型
	ListNode(ListNode<T> *ptrs = NULL) { link = ptrs; };
	ListNode(T datas, ListNode<T> *ptrs = NULL) { data = datas; link = ptrs; }
};

template<class T>
class SingleList:public List<T>
{
public:
	SingleList() { first = new LinkNode<T>; };
	SingleList(const T data) { first = new ListNode<T>(data); }
	SingleList(SingleList<T> &L);
	~SingleList() { makeEmpty(); };
	int Size()const { return Length(); };//表的最大体积
	int Length()const;//表的长度
	void makeEmpty();//将表清空；
	ListNode<T> *getHead() { return first; };
	ListNode<T> *search(const T x)const;//查找x，返回x的位置；
	ListNode<T> *locate(int i)const;//搜索第i个元素的地址,如果i等于零，则返回头结点的地址；
	bool getData(int i, T&x)const;//取第i个数，传值给x
	bool setData(int i, const T x);//将第i个数的值设置成x
	bool insert(int i, const T x);//在i位置  后一位  插入x,如果i等于0，则插入在最开头位置！！！
	bool remove(int i, T&x);//删除第i位的值，传值给x
	bool isEmpty()const { return first->link == NULL ? true : false; };//判断是否空
	bool isFull()const { return false; };//判断是否满,
	void sort();//排序
	void input(T endtag);
	void output()const;
	SingleList<T>operator=(SingleList<T>&L);
protected:
	ListNode<T> *first;
};
#endif // !SINGLELIST_H

template<class T>
SingleList<T>::SingleList(SingleList<T> &L)
{
	T value;
	ListNode<T> *srcptr = L.getHead();
	ListNode<T> *desptr = first = new ListNode<T>;
	while (srcptr->link != NULL)
	{
		value = srcptr->link->data;
		desptr->link = new LinkNode<T>(value);
		desptr = desptr->link;
		srcptr = srcptr->link;
	}
}

template<class T>
int SingleList<T>::Length() const
{
	int i = 0;
	ListNode<T> *ptr = first->link;
	while (ptr != NULL)
	{
		i++;
		ptr = ptr->link;
	}
	return i;
}

template<class T>
void SingleList<T>::makeEmpty()
{
	ListNode<T> *ptr;
	while (first->link != NULL)
	{
		ptr = first->link;
		first->link = ptr->link;
		delete ptr;
	}
}

template<class T>
ListNode<T>* SingleList<T>::search(const T x) const
{
	ListNode<T> *ptr = first->link;
	while (ptr != NULL)
	{
		if (ptr->data == x)break;
		else ptr = ptr->link;
	}
	return ptr;
}

template<class T>
ListNode<T>* SingleList<T>::locate(int i) const
{
	ListNode<T> *ptr = first;
	int tab = 1;
	if (i == 0||ptr->link==NULL)return ptr;
	while (ptr->link != NULL && tab <= i)
	{
		ptr = ptr->link;
		tab++;
	}
	return ptr;
}

template<class T>
bool SingleList<T>::getData(int i, T & x) const
{
	ListNode<T> *ptr = locate(i);
	if (ptr != NULL)
	{
		x = ptr->data;
		return true;
	}
	else
		return false;
}

template<class T>
bool SingleList<T>::setData(int i, const T x)
{
	ListNode<T> *ptr = locate(i);
	if (ptr != NULL)
	{
		ptr->data = x;
		return true;
	}
	else
		return false;
}

template<class T>
bool SingleList<T>::insert(int i, const T x)
{
	ListNode<T> *ptr = locate(i);
	if (ptr != NULL)
	{
		ListNode<T> *isptr = ptr->link;
		ListNode<T> *inptr = new ListNode<T>(x);
		ptr->link = inptr;
		inptr->link = isptr;
		return true;
	}
	else
		return false;
}

template<class T>
bool SingleList<T>::remove(int i, T & x)
{
	ListNode<T> *ptr = locate(i - 1);
	if (ptr->link != NULL)
	{
		ListNode<T> *rmptr = ptr->link;
		x = rmptr->data;
		ptr->link = rmptr->link;
		delete rmptr;
		return true;
	}
	else
		return false;
}

template<class T>
void SingleList<T>::sort()
{
	//排序。。。
}

template<class T>
void SingleList<T>::input(T endtag)
{
	ListNode<T> *newptr, *last;
	T value;
	makeEmpty();
	cin >> value;
	last = first;
	while (value != endtag)
	{
		newptr = new ListNode<T>(value);
		last->link = newptr;
		last = newptr;
		cin >> value;
	}
}

template<class T>
void SingleList<T>::output() const
{
	ListNode<T> *ptr = first->link;
	while (ptr != NULL)
	{
		cout << ptr->data << ",";
		ptr = ptr->link;
	}
	cout << endl;
}

template<class T>
SingleList<T> SingleList<T>::operator=(SingleList<T>& L)
{
	T value;
	ListNode<T> *srcptr = L.getHead();
	ListNode<T> *desptr = first = new ListNode<T>;
	while (srcptr->link != NULL)
	{
		value = srcptr->link->data;
		desptr->link = new LinkNode<T>(value);
		desptr = desptr->link;
		srcptr = srcptr->link;
	}
	return *this;
}



