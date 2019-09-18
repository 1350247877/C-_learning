#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

template <class T>
class Animal {
public:
	void makeSound() {
		cout << mAge << "  ��Ķ����ڽ�������ȥ�ġ�����" << endl;
	}
public:
	T mAge;
};

template<class T>
class Cat :public Animal<T>
{

public:
	void makeSound() {
		cout << mAge << "��è�ڽУ�" << endl;
	}

public:
	T mAge;

};

int main(void) {
	Cat<int> cat;
	cat.makeSound();

	return 0;
}