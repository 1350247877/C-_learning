#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>


using namespace std;

class Person
{

public:
	Person(const char * name, int age)
	{
		this->pName = new char[strlen(name) + 1];
		this->age = age;
		strcpy(this->pName, name);
		this->age = age;
	}
	Person(const Person &p)//��ֵ������Ϊ���ÿ���
	{
		this->pName = new char[strlen(p.pName) + 1];
		strcpy(this->pName, p.pName);
		this->age = p.age;
	}

	Person &operator=(const Person &p)
	{
		if (this->pName != NULL)
		{
			delete this->pName;
		}
		this->pName = new char[strlen(p.pName) + 1];
		strcpy(this->pName, pName);
		this->age = age;

		return *this;
	}
	~Person()
	{
		if (this->pName != NULL)
		{
			delete[] this->pName;
		}
	}
public:
	char * pName;//ָ�룬���׳���ǳ���������⡣
	int age;
};

void test01()
{
	Person p1("aaa",20);
	vector<Person> v1;
	v1.push_back(p1);
}

int main(void)
{
	test01();
	system("pause");
	return 0;
}