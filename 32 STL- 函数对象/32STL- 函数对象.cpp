#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//1������������ʹ��ʱ����������ͨ������������, �����в����������з���ֵ ����ֱ����class Ҳ��
struct Myprint
{
	Myprint()
	{
		mNum = 0;
	}
	void operator()(int val)//
	{
		mNum++;
		cout << val << endl;
	}
public:
	int mNum;
};

int num = 0;//�����ڿ����У���������ʹ��ȫ�ֱ�������������
void Myprint02(int val)
{
	num++;
	cout << val << endl;
}
void test01()
{
	Myprint print;
	print(10);


	//���������������ͨ����һ�����е���
	//���������������ͨ�����������ղ���
	//�������󳬳��˺����ĸ������������Ա��溯���ĵ���״̬��
}

void test02()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(40);
	v.push_back(90);
	v.push_back(70);



	

	//���㺯�����ô���
#if 0
	Myprint02(10);
	Myprint02(20);
	cout << num << endl;
	
	Myprint print;
	print(10);
	print(20);
	print(20);
	cout << print.mNum << endl;
#endif
	Myprint print;
	Myprint print02 = for_each (v.begin(), v.end(),print );
	cout << "����ǰ  print���ô��� " << print.mNum << endl;
	cout << "���к�  print���ô��� " << print02.mNum << endl;
}
int main(void)
{
	//test01();
	test02();
	system("pause");
	return 0;
}