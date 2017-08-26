#ifndef SEQSTACK_H
#define SEQSTACK_H
#include<iostream>
#include"stack.h"
const int defaultSize = 100;
using namespace std;

template<class T>
class SeqStack:public Stack<T>
{
public:
	SeqStack();
	~SeqStack();
	void push(const T&x);
	bool pop(T &x);
	bool getTop(T &x)const;
	bool isEmpty()const;
	bool isFull()const;
	int getSize()const;  //返回栈中元素个数
	friend ostream &operator<<(ostream &os,SeqStack<T> &L);
private:
	int top;//栈顶索引，
	int size;//栈的最大容量
	T *data;
	void overFlow();//当栈满时执行的操作
};

#endif

template<class T>
SeqStack<T>::SeqStack()
{
	data = new T[defaultSize];
	size =defaultSize;
	top =-1;
}

template<class T>
SeqStack<T>::~SeqStack()
{
	delete[] data;
}

template<class T>
void SeqStack<T>::push(const T & x)
{
	if (size - top < 10)
		overFlow();
	else
		data[top + 1] = x;
	top++;
}

template<class T>
bool SeqStack<T>::pop(T & x)
{
	if (top != -1)
	{
		x = data[top];
		top--;
		return true;
	}
	else
		return false;
}

template<class T>
bool SeqStack<T>::getTop(T & x) const
{
	if (top == -1)
		return false;
	else
		x = data[top];
	return true;
}

template<class T>
bool SeqStack<T>::isEmpty() const
{
	if (top == -1)
		return true;
	else
		return false;
}

template<class T>
bool SeqStack<T>::isFull() const
{
	return false;//因为总是有多余的十个空间，所以永远不会真正的满栈；
}

template<class T>
int SeqStack<T>::getSize() const
{
	return top+1;
}

template<class T>
ostream &operator<<(ostream &os,SeqStack<T>& L)
{
	for (int i = 0; i < L.getSize(); i++)
	{
		os << L.data[i] << ",";
	}
	os<<endl;
	return os;
}

template<class T>
void SeqStack<T>::overFlow()
{
	T *data_new = new T[size + defaultSize];
	for (int i = 0; i <= top; i++)
		data_new[i] = data[i];
	delete[] data;
	data = data_new;
	size = size + defaultSize;
}
