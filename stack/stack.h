//派生了顺序栈和链式栈，二者只是存储方式不同而已
#ifndef STACK_H
#define STACK_H
template<class T>
class Stack
{
public:
	Stack() {};
	virtual void push(const T&x) = 0;
	virtual bool pop(T &x) = 0;
	virtual bool getTop(T &x)const = 0;
	virtual bool isEmpty()const = 0;
	virtual bool isFull()const = 0;
	virtual int getSize()const = 0;

};

#endif
