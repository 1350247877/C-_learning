#include<iostream>

using namespace std;
//�쳣�����﷨
int divied(int x, int y) {
	if (y == 0) {
		throw y;//�׳��쳣
	}
}

void test01() {
	//������ȥ�����쳣
	try {
		divied(10, 0);
	}
	catch (int e ) { //�쳣�Ǹ������ͽ���ƥ���,catch(int)
		cout << "����Ϊ " << e << endl;
	}
}
void CallDivide(int x,int y) {
	divied(x, y);
}

void test02() {
	try {
		CallDivide(1,0);
	}
	catch (int e) {
		cout << " test02 ����Ϊ " << e << endl;
	}
}

//�쳣�纯��
//�쳣���봦��
int main()
{
	//test01();
	test02();
}