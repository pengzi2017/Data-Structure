#ifndef QUEUE_H
#define QUEUE_H
const int defaultSize = 100;
template<class T>
class Queue
{
public:
	Queue() {};
	~Queue() {};
	virtual bool enQueue(T &data) = 0;
	virtual bool deQueue(T &data) = 0;
	virtual bool getFront(T &data) = 0;
	virtual bool isEmpty()const = 0;
	virtual bool isFull()const = 0;
	virtual int getSize()const = 0;
};
#endif
