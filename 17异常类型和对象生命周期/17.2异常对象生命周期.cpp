#include<iostream>
using namespace std;


class MyException {
public:
	MyException() {
		cout << "���캯��" << endl;
	}

	MyException(const MyException &ex) {
		cout << "���캯��" << endl;
	}

	~MyException() {
		cout << "��������" << endl;
	}

};
void func() {
	//throw &(MyException());
	//throw MyException(); //�����������󣬵��ù���
	throw new MyException();
}

void test01()
{
	//��ͨ����Ԫ�أ����ã�ָ��
	//��ͨԪ�أ��쳣����catch������֮�������
	//���õĻ������õ��ÿ������죬�쳣����catch������֮�������
	//ָ�� �Ļ��� ��Ҫ����дthrow new MyException()�������ֶ�����ָ�룬�ſ��ԡ�
	try {
		func();
	} 
	catch (MyException *e) { //��������
		cout << "�쳣����" << endl;
		delete e;//ָ����Ҫ�Լ��ֶ�ȥ����
	}
}
int main() {

	test01();
	return 0;
	


}