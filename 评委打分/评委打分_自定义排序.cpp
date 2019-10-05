#include<list>
#include<string>
#include<deque>
#include<iostream>


using namespace  std;
class Person2 {
public:
	Person2(string name, int age, int height)
	{
		this->m_Age = age;
		this->m_Height = height;
		this->m_Name = name;
	}
public:
	int m_Age;
	int m_Height;
	string m_Name;
};

bool ComparePerson(Person2& v1, Person2 & v2)
{
	if (v1.m_Age == v2.m_Age)
	{
		return v1.m_Height > v2.m_Height;
	}
	else
	{
		return v1.m_Age < v2.m_Age;
	}
}

void test01()
{
	list<Person2> l;
	Person2 p1("����", 35, 175);
	Person2 p2("�ܲ�", 45, 180);
	Person2 p3("��Ȩ", 40, 170);
	Person2 p4("����", 25, 190);
	Person2 p5("�ŷ�", 35, 160);
	Person2 p6("����", 35, 200);


	l.push_back(p1);
	l.push_back(p2);
	l.push_back(p3);
	l.push_back(p4);
	l.push_back(p5);
	l.push_back(p6);

	for (list<Person2>::iterator it = l.begin(); it != l.end(); it++)
	{
		cout << "������ " << it->m_Name << " ���䣺 " << it->m_Age
			<< " ��ߣ� " << it->m_Height << endl;
	}

	cout << "------------------------------" << endl;
	l.sort(ComparePerson);
	for (list<Person2>::iterator it = l.begin(); it != l.end(); it++) {
		cout << "������ " << it->m_Name << " ���䣺 " << it->m_Age
			<< " ��ߣ� " << it->m_Height << endl;
	}
}

int main()
{
	test01();
	system("pause");

	return 0;
}