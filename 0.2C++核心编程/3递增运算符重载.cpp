#include<iostream>
using namespace  std;
class MyInteger {
public:
	friend ostream & operator<<(ostream &out, MyInteger myint);
	MyInteger(int num)
	{
		this->m_Num = num;
	}
	//ǰ�� ++
	MyInteger & operator ++() {
		this->m_Num++;
		return  *this; // ǰ�õ�������Ҫ���ص�������
	}
	//����++,�����intֻ�Ǹ�ռλ������������������ǰ�úͺ��õ�����ֻ����int
	MyInteger operator++(int)
	{
		MyInteger temp = *this;
		this->m_Num++;
		return temp;//���õ��� ���ر�����ֵ����Ϊtemp�Ǿֲ��ģ�����������ã��ֲ�temp���ͷ��˺󣬾��ǷǷ�����

	}
private :
	int m_Num;
};

ostream & operator<< (ostream &out, MyInteger myint) {
	out << myint.m_Num;
	return out;
}

//ǰ��++ ��++ �ٷ���
int test01()
{
	MyInteger myInt(10);

	cout << ++myInt << endl;
	cout << myInt << endl;
	return 0;
}
//����++ �ȷ��� ��++
int test02()
{
	MyInteger myInt(20);
	cout << myInt++ << endl;
	cout << myInt << endl;
	return 0;
}
int main04() {

	//test01();
	test02();

	system("pause");

	return 0;
}