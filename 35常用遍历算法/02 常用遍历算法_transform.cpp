#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//���ñ����㷨 transform

class Transform
{
	//�º���
public:
	int operator()( int v)
	{
		return v+10;//���Լ���һЩ�߼�����
	}
};

class MyPrint {
public:
	void  operator()(int v){
		cout << " v = " << v << " ";
	}
};

void test01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int> vTarget;//Ŀ������

	vTarget.resize(v.size());//��Ҫ��ǰ���ٿռ�

	transform(v.begin(), v.end(), vTarget.begin(), Transform());
	
	for_each(vTarget.begin(), vTarget.end(),MyPrint());
	cout << endl;

}

int main()
{
	test01();
	system("pause");
	return 0;
}