//˳���
#ifndef SEQLIST_H
#define SEQLIST_H
#include"list.h"
#include<iostream>
using namespace std;
const int defaultSize = 100;
template<class T>
class SeqList:public List<T>
{
public:
	SeqList(int sz=defaultSize);
	SeqList(SeqList<T>&L);
	~SeqList() { delete[] data; };
	int Size()const {return size;};//���������
	void resize();//������Ĵ�С
	int Length()const {return length;};//��ĳ���
	int search(const T x)const;//����x������x��λ��,�Ҳ����򷵻ظ�ֵ��
	bool getData(int i, T&x)const;//ȡ��i��������ֵ��x
	bool setData(int i, const T x);//����i������ֵ���ó�x
	bool insert(int i, const T x);//��iλ��  ��һλ  ����x(i��1����)
	bool remove(int i, T&x);//ɾ����iλ��ֵ����ֵ��x(i��1������
	bool isEmpty()const//�ж��Ƿ��
	{
		if (length == 0)
			return true;
		else
			return false;
	}
	bool isFull()const//�ж��Ƿ���
	{
		if (length == size)
			return true;
		else
			return false;
	}
	void sort();//����
	void input(T endTag);
	void output()const;
	//friend ostream operator<<(ostream &out,SeqList<T>&L);
	SeqList<T>operator=(SeqList<T>&L);
private:
	T *data;
	int length;//���ȣ���1����
	int size;//�������
};
template<class T>
SeqList<T>::SeqList(int sz)
{
	size = sz;
	data = new T[size];
	length = 0;
}

template<class T>
SeqList<T>::SeqList(SeqList<T>& L)
{
	size = L.size;
	length = L.length;
	data = new T[size + defaultSize];
	if (data == NULL)
	{
		cout << "�ڴ�������" << endl;
		exit(1);
	}
	for (int i = 0; i < length; i++)
		data[i] = L.data[i];
}

template<class T>
void SeqList<T>::resize()
{
	T *datas = new T[size];
	for (int i = 0; i < length; i++)
		datas[i] = data[i];
	data = new T[size + defaultSize];
	for (int i = 0; i < length; i++)
		data[i] = datas[i];
	size = size + defaultSize;
	delete[] datas;
}

template<class T>
int SeqList<T>::search(const T x) const
{
	for (int i = 0; i < length; i++)
	{
		if (data[i] == x)
			return i + 1;
	}
	return -1;
}

template<class T>
bool SeqList<T>::getData(int i, T & x) const
{
	if (i<1 || i>length)
		return false;
	else
	{
		x = data[i - 1];
		return true;
	}
}

template<class T>
bool SeqList<T>::setData(int i, const T x)
{
	if (i<1 || i>length)
		return false;
	else
		data[i - 1] = x;
	return true;
}

template<class T>
bool SeqList<T>::insert(int i, const T x)
{
	if (i<0 || i>length)return false;
	if (size - length < 10)
		resize();
	for (int j = length; j > i; j--)
		data[j] = data[j - 1];
	data[i] = x;
	length++;
	return true;
}

template<class T>
bool SeqList<T>::remove(int i, T & x)
{
	if (i < 1 || i>length)return false;
	x = data[i - 1];
	for (int j = i - 1; i < length; i++)
		data[j] = data[j + 1];
	length--;
	return true;
}

template<class T>
void SeqList<T>::sort()
{
	//����ð������
	int bubbleNum;
	do
	{
		bubbleNum = 0;
		for (int i = 0; i<length - 1; i++)
			if (data[i] > data[i + 1])
			{
				T temp = data[i + 1];
				data[i + 1] = data[i];
				data[i] = temp;
				bubbleNum++;
			}
	} while (bubbleNum != 0);
}

template<class T>
void SeqList<T>::input(T endTag)
{
	T value;
	cin >> value;
	while (value != endTag)
	{
		if (size - length < 10)
			resize();
		data[length] = value;
		length++;
		cin >> value;
	}
}

template<class T>
void SeqList<T>::output() const
{
	for (int i = 0; i < length; i++)
		cout << data[i] << ",";
	cout << endl;
}

template<class T>
SeqList<T> SeqList<T>::operator=(SeqList<T>& L)
{
	size = L.size;
	length = L.length;
	data = new T[size];
	for (int i = 0; i < length; i++)
		data[i] = L.data[i];
	return *this;
}

#endif
