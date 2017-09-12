//—≠ª∑∂”¡–
#ifndef SEQ_QUEUE_H
#define SEQ_QUEUE_H
#include"queue.h"
#include<iostream>
#include<ostream>
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
	bool isFull()const {return (rear+1)%maxSizes==front? true : false; };
	int getSize()const {return (rear-front+maxSizes)%maxSizes; };
	/*
	friend osrteam &operator<<(ostream &os, SeqQueue &dt)//////////////????????????????????????????
	{
		for (int i = dt.front; i != dt.rear; i = (i + 1) % dt.makeSize)
			os << dt.element[i] << ",";
		os << endl;
		return os;
	};
	*/
	void outPut();
private:
	int front, rear;
	T *element;
	int maxSizes;
	void makeSize();
};

#endif

template<class T>
SeqQueue<T>::SeqQueue(int sz):maxSizes(sz),front(0),rear(0)
{
	element = new T[maxSizes];
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
	element[rear] = data;
	rear = (rear + 1) % maxSizes;
	return true;
}

template<class T>
bool SeqQueue<T>::deQueue(T & data)
{
	if (isEmpty())return false;
	data = element[front];
	front = (front+1)%maxSizes;
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
void SeqQueue<T>::outPut()
{
	for (int i =front; i !=rear; i = (i + 1)%maxSizes)
		cout<<element[i] << ",";
	cout<< endl;
}

template<class T>
void SeqQueue<T>::makeSize()
{
	T *otherElem = new T[maxSizes + defaultSize];
	for (int i =front; i!=rear; i=(i+1)%maxSizes)
		otherElem[i] = element[i];
	maxSizes = maxSizes + defaultSize;
	delete[] element;
	element = otherElem;
}
/*
template<class T>
osrteam operator<<(ostream &os, SeqQueue<T> &dt)
{
	for (int i = dt.front; i != dt.rear; i = (i + 1) % dt.makeSize)
		os << dt.element[i] << ",";
	os << endl;
	return os;
}
*/