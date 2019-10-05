#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
//�º��������� bindlst bind2nd; ��������

struct MyPrint :public binary_function<int,int,void> //������Ҫ�̳�binary_function<��һ���������ڶ�������������ֵ����>
{
	void operator()(int v,int val ) const //������Ҫ��������
	{
		cout << "v:  " << v << "  val:  " << val << endl;
		cout << v+val  << "  ";
	}
	   
};
void test01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//��ͨ 
	//for_each(v.begin(), v.end(), MyPrint());
	//��������,����Ԫ�ĺ�������ת���һԪ�ĺ�������
	int addNum = 100;
	for_each(v.begin(), v.end(), bind2nd(MyPrint(),addNum));
	//
	for_each(v.begin(), v.end(), bind1st(MyPrint(), addNum));
	//bind2nd,��bind1st�������ǣ�
	//bind2nd ��addNum��Ϊ��������ĵڶ�������
	//bind1st ��addNUM��Ϊ��������ĵ�һ������
}
struct MyPrint2 
{
	void operator()(int v) const
	{
		
		cout << v  << "  ";
	}

};

struct Mycompare :public binary_function<int ,int,bool>//��Ԫν�ʣ�
{
public:
	bool operator()(int v1, int v2) const
	{
		return v1 > v2;
	}
};
struct MyGreater5 :public unary_function<int,bool> //һԪν��
{
public:
	bool operator()(int v) const
	{
		return v > 5;
	}
};

//�º��������� not1 not2
void test02()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(rand()%100);
	}
	for_each(v.begin(), v.end(), MyPrint2());
	cout << endl;
	//sort(v.begin(), v.end(), Mycompare());
	//cout << endl;
	sort(v.begin(), v.end(), not2(Mycompare()));//ȡ��������
	cout << endl;
	for_each(v.begin(), v.end(),MyPrint2());
	cout << endl;
	//not1 ��not2 ������
	//�����һԪν��ȡ������not1
	//����Զ�Ԫν��ȡ������not2
	vector<int>::iterator it = find_if(v.begin(), v.end(), MyGreater5());
	cout << *it << endl;
	vector<int>::iterator it2 = find_if(v.begin(), v.end(), not1(MyGreater5()));
	if (it2 == v.end())
	{
		cout << " û���ҵ� " << endl;
	}
	else
	{
		cout << *it2 << endl;
	}
	
}



//�º��������� ptr_fun
void myPrint03(int val)
{
	cout << val << " " ;
}
void myPrint04(int val,int v)
{
	cout << " val  " << val << " v " << v;
	cout << val + v << " " << endl;;
}
void test03()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(rand() % 100);
	}

	for_each(v.begin(), v.end(), myPrint03); cout << endl;
	//��������䣬����Ҫ����ͨ����ת�ɺ�������ʹ��ptr_fun
	for_each(v.begin(), v.end(), ptr_fun(myPrint03)); cout << endl;
	for_each(v.begin(), v.end(), bind2nd(ptr_fun(myPrint04), 10)); cout << endl;
}

class Person
{

public:
	Person(int age, int id) :age(age), id(id) {}
	void show() {
		cout << "age: " << age << "  id: " << id << endl;
	} 
public:
	int age;
	int id;
};

//��Ա���������� mem_fun�� mem_fun_ref
void test04()
{
	//��������д�ŵ��Ƕ��������ָ�룬����for_each�㷨��ӡ��ʱ�򣬵����࣬
	//�Լ��ṩ�Ĵ�ӡ����
	vector<Person> v;
	Person p1(10, 20), p2(30, 40), p3(50, 60);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);

	//��ʽ:&����::������
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::show));

	vector<Person*> v2;
	v2.push_back(&p1);
	v2.push_back(&p2);
	v2.push_back(&p3);

	//��ʽ:&����::������
	for_each(v2.begin(), v2.end(), mem_fun(&Person::show));

	//mem_fun �� mem_fun_ref������
	//�����ŵ��Ƕ���ָ�룺ʹ��mem_fun
	//���ʹ�õ��Ƕ���ʹ��mem_fun_ref

}


int main(void)
{
	//test01();
	//test02();
	//test03();
	test04();	
	system("pause");
	return 0;
}
