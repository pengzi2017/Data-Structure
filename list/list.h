//�����
//Լ������������Լ��i��ֵ��1��ʼ������size()��length()���ص�ֵ�����Ǵ�1��ʼ�����ģ���
#ifndef LIST_H
#define LIST_H
template<class T>
class List
{
public:
	//List();
	//virtual ~List()=0;
	virtual int Size()const = 0;//���������
	virtual int Length()const = 0;//��ĳ���
	//virtual int search(const T x)const = 0;//����x������x��λ�ã�
	virtual bool getData(int i,T&x)const = 0;//ȡ��i��������ֵ��x
	virtual bool setData(int i,const T x) = 0;//����i������ֵ���ó�x
	virtual bool insert(int i, const T x) = 0;//��iλ��  ��һλ  ����x
	virtual bool remove(int i, T&x) = 0;//ɾ����iλ��ֵ����ֵ��x
	virtual bool isEmpty()const = 0;//�ж��Ƿ��
	virtual bool isFull()const = 0;//�ж��Ƿ���
	virtual void sort() = 0;//����
	virtual void input(T endTag) = 0;
	virtual void output()const = 0;
//	virtual List<T>operator=(List<T> &L) = 0;
};

#endif // !LIST_H

