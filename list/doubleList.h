#ifndef DOUBLELIST_H
#define DOUBLELIST_H
#include<iostream>
using namespace std;
template<class T>
struct DoubleNode
{
	T data;
	DoubleNode<T> *lLink, *rLink;
	DoubleNode(DoubleNode<T> *lptr = NULL, DoubleNode<T>*rptr = NULL) { lLink = lptr; rLink = rptr; };
	DoubleNode(T value, DoubleNode<T> *lptr = NULL, DoubleNode<T>*rptr = NULL) { lLink = lptr; rLink = rptr; data=value; };
};

template<class T>
class DoubleList
{
public:
	DoubleList(T value) { first = new DoubleNode<T>(value); first->lLink = first->rLink = first; };
	~DoubleList() { makeEmpty(); };
	int Size()const { return Length(); };//���������
	int Length()const;//��ĳ���
	void makeEmpty();//������գ�
	DoubleNode<T> *getHead() { return first; };
	DoubleNode<T> *search(const T x)const;//����x������x��λ�ã�
	DoubleNode<T> *locate(int i)const;//������i��Ԫ�صĵ�ַ��
	bool getData(int i, T&x)const;//ȡ��i��������ֵ��x
	bool setData(int i, const T x);//����i������ֵ���ó�x
	bool insert(int i, const T x);//��iλ��  ��һλ  ����x�����i����0������뵽��ͷλ��
	bool remove(int i, T&x);//ɾ����iλ��ֵ����ֵ��x //
	bool isEmpty()const { return first->rlink ==first ? true : false; };//�ж��Ƿ��
	bool isFull()const { return false; };//�ж��Ƿ���,
	void sort();////
	void input(T endtag);
	void output()const;
private:
	DoubleNode<T> *first;
};


#endif

template<class T>
int DoubleList<T>::Length() const
{
	int i = 0;
	DoubleNode<T> *ptr = first->rLink;
	while (ptr !=first )
	{
		i++;
		ptr = ptr->rLink;
	}
	return i;
}

template<class T>
void DoubleList<T>::makeEmpty()
{
	DoubleNode<T> *ptr;
	while (first->rLink !=first)
	{
		ptr = first->rLink;
		first->rLink = ptr->rLink;
		delete ptr;
	}
}

template<class T>
DoubleNode<T>* DoubleList<T>::search(const T x) const
{
	DoubleNode<T> *ptr = first->rLink;
	while (ptr != first)
	{
		if (ptr->data == x)
			return ptr;
		else
			ptr = ptr->rLink;
	}
	return NULL;
}

template<class T>
DoubleNode<T>* DoubleList<T>::locate(int i) const
{
	DoubleNode<T> *ptr=first;
	if (first->rLink == first || i == 0)return ptr;
	int tab = 1;
	while(tab<=i && ptr->rLink!=first)
	{
		tab++;
		ptr = ptr->rLink;
	}
	return ptr;
}

template<class T>
bool DoubleList<T>::getData(int i, T & x) const
{
	DoubleNode<T> *ptr = locate(i);
	if (ptr != NULL)
	{
		x = ptr->data;
		return true;
	}
	else
		return false;
}

template<class T>
bool DoubleList<T>::setData(int i, const T x)
{
	DoubleNode<T> *ptr = locate(i);
	if (ptr != NULL)
	{
		ptr->data=x;
		return true;
	}
	else
		return false;
}

template<class T>
bool DoubleList<T>::insert(int i, const T x)
{
	DoubleNode<T> *bptr = locate(i);
	if (bptr == NULL)return false;
	bptr = bptr->rLink;
	DoubleNode<T> *uptr = locate(i);
	DoubleNode<T> *ptr = new DoubleNode<T>(x);
	ptr->rLink = bptr;
	ptr->lLink = uptr;
	bptr->lLink = ptr;
	uptr->rLink = ptr;
	return true;
}

template<class T>
bool DoubleList<T>::remove(int i, T & x)
{
	DoubleNode<T> *ptr = locate(i);
	if (ptr == NULL)return false;
	else
	{
		ptr->rLink->lLink = ptr->lLink;
		ptr->lLink->rLink = ptr->rLink;
		x = ptr->data;
		delete ptr;
		return true;
	}
}

template<class T>
void DoubleList<T>::sort()
{
	////////////
}

template<class T>
void DoubleList<T>::input(T endTag)
{
	DoubleNode<T> *newptr, *front;
	T value;
	makeEmpty();
	front = first;
	cin >> value;
	while (value != endTag)
	{
		newptr = new DoubleNode<T>(value);
		front->rLink = newptr;
		front->rLink->lLink = front;
		front = newptr;
		cin >> value;
	}
	front->rLink = first;
	first->lLink = front;
}

template<class T>
void DoubleList<T>::output() const
{
	DoubleNode<T> *ptr = first->rLink;
	while (ptr !=first)
	{
		cout << ptr->data << ",";
		ptr = ptr->rLink;
	}
	cout << endl;
}
