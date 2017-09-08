//—≠ª∑∂”¡–
#ifndef SEQ_QUEUE_H
#define SEQ_QUEUE_H
#include"queue.h"
#include<iostream>
using namespace std;
template<class T>

class SeqQueue:public Queue<T>
{
public:
	SeqQueue(int sz=100);
	~SeqQueue();
	bool enQueue(T &data);
	bool deQueue(T &data);
	bool getFront(T &data);
	bool isEmpty()const {return front == rear ? true : false; };
	bool isFull()const {return (rear+1)%maxSize==front? true : false; };
	int getSize()const {return (rear-front+maxSize)%maxSize; };
	friend osrteam operator<<(ostream &os, SeqQueue<T> &dt);
private:
	int front, rear;
	T *element;
	int maxSize;
	void makeSize();
};

#endif

template<class T>
SeqQueue<T>::SeqQueue(int sz):maxSize(sz),front(0),rear(0)
{
	element = new T[maxSize];
}

template<class T>
SeqQueue<T>::~SeqQueue()
{
	delete[] element;
}

template<class T>
bool SeqQueue<T>::enQueue(T & data)
{
	if (isFull())makeSize();
	rear=(rear+1)%maxSize;
	element[rear] = data;
	return true;
}

template<class T>
bool SeqQueue<T>::deQueue(T & data)
{
	if (isEmpty())return false;
	data = element[front];
	front = (front+1)%maxSize;
	return true;
}

template<class T>
bool SeqQueue<T>::getFront(T & data)
{
	if (isEmpty())return false;
	data = element[front];
	return true;
}

template<class T>
void SeqQueue<T>::makeSize()
{
	T *otherElem = new T[maxSize + defaultSize];
	for (int i =front; i!=rear; i=(i+1)%maxSize)
		otherElem[i] = element[i];
	maxSize = maxSize + defaultSize;
	delete[] element;
	element = otherElem;
}

template<class T>
osrteam operator<<(ostream &os, SeqQueue<T> &dt)
{
	for (int i = dt.front; i != dt.rear; i = (i + 1) % dt.makeSize)
		os << dt.element[i] << ",";
	os << endl;
	return os;
}