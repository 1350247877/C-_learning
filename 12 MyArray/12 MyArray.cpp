#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

template<class T>
class MyArray {

public:
	MyArray(int capacity) {
		this->mCapacity = capacity;
		this->mSize = 0;
		//�����ڴ�
		this->pAddr = new T[this->mCapacity];
	}
	//copy
	MyArray(const MyArray &arr) {
		this->mSize = arr.mSize;
		this->mCapacity = arr.mCapacity;
		//�����ڴ�
		this->pAddr = new T[this->mCapacity];
		//���ݿ���
		for (int i = 0; i < this->mSize; i++) {
			this->pAddr[i] = arr.pAddr[i];
		}
	}

	T & operator[](int index) {
		return this->pAddr[index];//����һ������
	}
	//�Ⱥ�����
	MyArray<T> operator= (const MyArray &arr) {
		if (this->pAddr != NULL) {
			delete[] this->pAddr;
		}
		this->mSize = arr.mSize;
		this->mCapacity = arr.mCapacity;
		//�����ڴ�
		this->pAddr = new T[this->mCapacity];
		//���ݿ���
		for (int i = 0; i < this->mSize; i++) {
			this->pAddr[i] = arr.pAddr[i];
		}
		return *this;
	}
	
	void PushBack(T& data) {
		//�ж��������Ƿ���λ��
		if (this->mSize == this->mCapacity) {
			return;
		}
		//���ÿ������� = �Ų�����
		//1������Ԫ�ر����ܹ�������
		//2.��������ֵԢ�⣬��������Ԣ�⣬�������з���Ԫ�أ����Ƿ���Ԫ�صĿ����ݣ�����Ԫ�ر���
		//3,���Ԫ�صĳ�Ա��ָ�룬ע�������ǳ���������⡣
		this->pAddr[this->mSize] = data;
		//mSize++
		this->mSize++;
	}
//#if 0
	//����ֵȡ����
	void PushBack(T&& data) {
		//�ж��������Ƿ���λ��
		if (this->mSize == this->mCapacity) {
			return;
		}

		this->pAddr[this->mSize] = data;
		//mSize++
		this->mSize++;
	}
//#endif

	//��������
	MyArray() {
		if (this->pAddr != NULL) {
			delete[] this->pAddr;
		}
	}
public:

	//һ���������¶��ٸ�Ԫ��
	int mCapacity;
	int mSize;
	//�������ݵ��׵�ַ
	T* pAddr;
};

void test() {
	MyArray<int> marray(20);
	int a = 10, b = 20, c = 30, d = 40;
	marray.PushBack(a);
	marray.PushBack(b);
	marray.PushBack(c);
	marray.PushBack(d);

	//���ܶ���ֵȡ���ã�&&
	//��ֵ֮�����ڶ���ʹ��
	//��ʱ�����������ڵ�ǰ��ʹ��
	marray.PushBack(100);


	for (int i = 0; i < marray.mSize; i++) {
		cout << marray[i] << endl;
	}
}
class Person {};
void test02()
{
	Person p1, p2;
	MyArray<Person> arr(10);
	arr.PushBack(p1);
	arr.PushBack(p2);

}

int main() {
	test();
}