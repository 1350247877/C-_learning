#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

//���ݽ���
void Myswap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

//ģ�弼�������Ͳ���������д������Ժ�������
//Ϊ���ñ�������������ͨ������ģ�庯��
template<class T> //template<typename T> ���߱�������������Ҫд��������������Ҫ����ֻ�Ե�һ��������Ч
void Myswap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

void test01() {
	int a = 10;
	int b = 20;
	//1,�Զ������Ƶ�
	cout << "a:  " << a << "  b:  " << b << endl;
	Myswap(a, b);//�����������㴫���ֵ�������Ƶ�
	cout << "a:  " << a << "  b:  " << b << endl;

	//2,��ʾ��ָ������
	Myswap<int>(a, b);
	cout << "a:  " << a << "  b:  " << b << endl;

}


int main(void)
{
	test01();
	//ctrl + F5 ���е���
}
