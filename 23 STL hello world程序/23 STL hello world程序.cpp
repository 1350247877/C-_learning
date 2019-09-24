#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector> //��̬���飬�ɱ�����
#include<algorithm> //�㷨
using namespace std;


void PrintVector(int v)
{
	cout << v << endl;
}


//STL�����﷨
void test01(){
	//����һ������������֪�����������ŵ�Ԫ��������int
	vector<int> v;
	v.push_back(30);
	v.push_back(2);
	v.push_back(3);
	v.push_back(9);

	//ͨ��stl�ṩ��for_each �㷨
	//�����ṩ�ĵ�����
	//vector<int> ::iterator ����������
	vector<int> ::iterator pBegin = v.begin();
	vector<int> ::iterator pEnd = v.end();

	//�����п��ܴ�Ż������������ͣ�Ҳ�����ܴ���Զ������������
	for_each(pBegin, pEnd, PrintVector);

}



class Person
{
public:
	Person(int age, int id):age(age), id(id) {}
public:
	int age;
	int id;
};

void test02()
{
	//���������������ƶ�������Ԫ��������Person
	vector<Person> v;
	Person p1(10, 20), p2(30, 40), p3(30, 40);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);

	for (vector<Person>::iterator it = v.begin();it != v.end(); it++)
	{
		cout << (*it).id <<"  "<<  (*it).age << endl;
	}



}

//�������Person����ָ�룬���Ҵ�ӡfor_each
int main(void)
{
	//test01();
	test02();
	return 0;
}