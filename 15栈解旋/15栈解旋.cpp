#include<iostream>

using namespace std;


class Person {
public:
	Person() {
		cout << "���󹹽���" << endl;
	}
	~Person() {
		cout << "����������" << endl;
	}
};

//�쳣�����﷨
int divied(int x, int y) {

	Person p1, p2; // ջ��������dived�����쳣����ֲ����������Զ���������
	if (y == 0) {
		throw y;//�׳��쳣
	}
}

void test01() {
	//������ȥ�����쳣
	try {
		divied(10, 0);
		divied(20, 0);
	}
	catch (int e) { //�쳣�Ǹ������ͽ���ƥ���,catch(int)
		cout << "����Ϊ " << e << endl;
	}
}


//�쳣�纯��
//�쳣���봦��
int main()
{
	test01();
}