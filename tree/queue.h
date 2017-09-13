//а╢й╫╤сап
#ifndef LINK_QUEUE_H
#define LINK_QUEUE_H
#include<iostream>
using namespace std;

template<class T>
struct LinkNode
{
	T data;
	LinkNode<T> *next;
	LinkNode() :next(NULL) {};
	LinkNode(T &da) :next(NULL), data(da) {};
};

template<class T>
class LinkQueue
{
public:
	LinkQueue() :front(NULL), rear(NULL) {};
	~LinkQueue() { makeEmpty(); };
	bool enQueue(T &d);
	bool deQueue(T &d);
	bool getFront(T &d);
	bool isEmpty()const { return front == NULL ? true : false; };
	bool isFull()const { return true; };
	int getSize()const;
	void outPut()const;
	//friend osrteam operator<<(ostream &os, LinkQueue<T> &dt);
private:
	LinkNode<T> *front, *rear;
	void makeEmpty();
};

#endif // !LINK_QUEUE_H

template<class T>
bool LinkQueue<T>::enQueue(T &d)
{
	if (front == NULL) {
		front = rear = new LinkNode<T>(d);
		if (front == NULL)return false;
	}
	else
	{
		rear->next = new LinkNode<T>(d);
		if (rear->next == NULL)return false;
		rear = rear->next;
	}
	return true;
}

template<class T>
bool LinkQueue<T>::deQueue(T & d)
{
	if (isEmpty())return false;
	LinkNode<T> *tab = front->next;
	d = front->data;
	delete front;
	front = tab;
	return true;
}

template<class T>
bool LinkQueue<T>::getFront(T & d)
{
	if (isEmpty())return false;
	d = front->data;
	return true;
}

template<class T>
int LinkQueue<T>::getSize() const
{
	LinkNode<T> *tab = front;
	int num = 0;
	while (tab->next != NULL)
	{
		tab = tab->next;
		num++;
	}
	return num;
}

template<class T>
void LinkQueue<T>::outPut() const
{
	LinkNode<T> *tab = front;
	while (tab != NULL)
	{
		cout << tab->data << ",";
		tab = tab->next;
	}
	cout << endl;
}

template<class T>
void LinkQueue<T>::makeEmpty()
{
	LinkNode<T> *tab;
	while (front != NULL)
	{
		tab = front->next;
		delete front;
		front = tab;
	}
}
