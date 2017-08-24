//虚基类
//约定：这里首先约定i的值从1开始，包括size()，length()返回的值，都是从1开始计数的！！
#ifndef LIST_H
#define LIST_H
template<class T>
class List
{
public:
	//List();
	//virtual ~List()=0;
	virtual int Size()const = 0;//表的最大体积
	virtual int Length()const = 0;//表的长度
	//virtual int search(const T x)const = 0;//查找x，返回x的位置；
	virtual bool getData(int i,T&x)const = 0;//取第i个数，传值给x
	virtual bool setData(int i,const T x) = 0;//将第i个数的值设置成x
	virtual bool insert(int i, const T x) = 0;//在i位置  后一位  插入x
	virtual bool remove(int i, T&x) = 0;//删除第i位的值，传值给x
	virtual bool isEmpty()const = 0;//判断是否空
	virtual bool isFull()const = 0;//判断是否满
	virtual void sort() = 0;//排序
	virtual void input(T endTag) = 0;
	virtual void output()const = 0;
//	virtual List<T>operator=(List<T> &L) = 0;
};

#endif // !LIST_H

