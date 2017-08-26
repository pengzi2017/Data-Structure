#ifndef LISTSTACK_H
#define LISTSTACK_H
#include<iostream>
#include"stack.h"
using namespace std;
template<class T>
struct StackNode
{
	T *data;
	StackNode<T>* link;
	StackNode() { link = NULL; }
};

template<class T>
class ListStack:public Stack<T>
{
public:
	ListStack();
	~ListStack();
	void push(const T&x);
	bool pop(T &x);
	bool getTop(T &x)const;
	bool isEmpty()const;
	bool isFull()const {return false;};
	int getSize()const;
private:
	StackNode<T> *top;
};

#endif

template<class T>
ListStack<T>::ListStack()
{
	top = new ListNode<T>;
}

template<class T>
ListStack<T>::~ListStack()
{
	StackNode<T> *ptr;
	while (top->link!= NULL)
	{
		ptr=top->link;
		delete top;
		top = ptr;
	}
}

template<class T>
void ListStack<T>::push(const T & x)
{
	StackNode<T> *ptr1=top->link;
	StackNode<T> *ptr = new StackNode<T>(x);
	top = ptr;
	ptr->link = ptr1;
}

template<class T>
bool ListStack<T>::pop(T & x)
{
	if(top->link==NULL)
		return false;
	StackNode<T> *ptr = top->link;
	x = top->data;
	delete top;
	top = ptr;
	return true;
}

template<class T>
bool ListStack<T>::getTop(T & x) const
{
	if (top->link == NULL)
		return false;
	else
		x = top->data;
	return true;
}

template<class T>
bool ListStack<T>::isEmpty() const
{
	if (top->link == NULL)
		return true;
	else
		return false;
}

template<class T>
int ListStack<T>::getSize() const
{
	int size=0;
	StackNode<T> *ptr = top;
	while (ptr->link!=NULL)
	{
		ptr = ptr->link;
		size++;
	}
	return size;
}
