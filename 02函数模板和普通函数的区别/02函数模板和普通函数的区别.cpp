#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;



//����ģ��Ĳ�������һһ��Ӧ
template<class T>
int MyAdd(T a, T b)
{
	cout << "ģ�庯��" << endl;
	return a + b;
}

//��Ϊ��ͨ�������Խ����Զ�����ת����
//����ģ��Ĳ�������һһ��
//C++ �����������������������£�������ѡ����ͨ������
int MyAdd(int a, char b) {
	cout << "��ģ�庯��" << endl;
	return a + b;
}

//ģ�庯�������Խ�������
template<class T>
void Print(T a) {

}
template<class T>
void Print(T a, T b) {

}

void test02() {
	int a = 10;
	int b = 20;
	char c1 = 'a';
	char c2 = 'b';
	MyAdd(a, c1);//��ģ��
	MyAdd(a, b);//ģ�� --C++ �����������������������£�������ѡ����ͨ��������MyAdd<>(a,b) �������ͻ����ģ�庯����
	MyAdd(c1, b);//��ģ��  ---��Ϊ��ͨ�����еĲ������Խ����Զ�����ת��������ģ��Ĳ�������һһ��Ӧ
#if 0
	MyAdd(a, c1);
	MyAdd(a, b);
	MyAdd(c1, b);

#endif 


}


int main(void)
{
	test02();
	//ctrl + F5 ���е���
}