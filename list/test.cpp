#include"circleList.h"
#include<iostream>
#include<Windows.h>
using namespace std;

int main()
{
	//template class SeqList<int>;
	CircleList<int> myList(0);
	myList.input(0);

	cout<<"length"<<myList.Length()<<endl;
	myList.output();
	int x;
	ListNode<int> *ptr = myList.locate(3);
	cout << ptr->data << endl;

	myList.getData(3,x);
	cout << "x:" << x << endl;
	myList.setData(3, 10);
	myList.output();

	myList.remove(3, x);
	myList.output();

	myList.insert(0, 1000);
	myList.output();

	system("pause");
	return 0;
}