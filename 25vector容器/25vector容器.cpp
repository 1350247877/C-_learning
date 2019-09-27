#include<iostream>
#include<string>
#include<vector>
using namespace std;

void PrintVector(vector<int> & v)
{
	for(vector<int>::iterator it = v.begin();it != v.end();it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}


void test01()
{
	vector<int> v1; //Ĭ�Ϲ���

	int arr[] = { 20,10,23,90 };
	vector<int> v2(arr, arr + sizeof(arr) / sizeof(int));//ʹ�������vector���г�ʼ��
	vector<int> v3(v2.begin(), v2.end());
	vector<int> v4(v3);

	PrintVector(v4);
	
}
//��ֵ����
void test02()
{
	int arr[] = { 20,10,23,90 };
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));
	
	vector<int> v2;
	v2.assign(v1.begin(), v1.end());

	//����
	vector<int> v3;
	v3 = v2;
	int arr1[] = { 200,100,300,400 };
	vector<int> v4(arr1, arr1 + sizeof(arr1) / sizeof(int));

	v4.swap(v1);//���ݽ�����ֻ�Ƕ��ڲ�ָ������˽���
	PrintVector(v1);
	PrintVector(v2);
	PrintVector(v3);
	PrintVector(v4);

	cout <<"---------------" <<endl;

}
//��С����
void test03()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	PrintVector(v1);
	if (v1.empty())
	{
		cout << "v1Ϊ��" << endl;
	}
	else
	{
		cout << "v1��Ϊ��" << endl;
		cout << "v1������ = " << v1.capacity() << endl;
		cout << "v1�Ĵ�С = " << v1.size() << endl;
	}

	//resize ����ָ����С ����ָ���ĸ���Ĭ����0�����λ�ã������������ذ汾�滻Ĭ�����
	v1.resize(15, 10);
	PrintVector(v1);

	//resize ����ָ����С ����ָ���ĸ�С����������Ԫ�ر�ɾ��
	v1.resize(5);
	PrintVector(v1);
}
//����ȡ����
void test04()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1.at(i) << " ";
	}
	cout << endl;

	cout << "v1�ĵ�һ��Ԫ��Ϊ�� " << v1.front() << endl;
	cout << "v1�����һ��Ԫ��Ϊ�� " << v1.back() << endl;
}
//�����ɾ��
void test05()
{
	vector<int> v1;
	//β��
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	PrintVector(v1);
	//βɾ
	v1.pop_back();
	PrintVector(v1);
	//����
	v1.insert(v1.begin(), 100);
	PrintVector(v1);

	v1.insert(v1.begin(), 2, 1000);
	PrintVector(v1);

	//ɾ��
	v1.erase(v1.begin());
	PrintVector(v1);

	//���
	v1.erase(v1.begin(), v1.end());
	v1.clear();
	PrintVector(v1);
}

//�����ռ�
void test06()
{
	//vector������ݻᣬ�Զ��������������Ԫ�صĻ��ǣ��ռ�������𣿡����ᣬ
	vector<int> v;
	for (int i = 0; i < 100000; i++)
	{
		v.push_back(i);
	}
	cout << "size:" << v.size() << endl;
	cout << "capacity:" << v.capacity() << endl;

	v.resize(10);
	cout << "--------------------" << endl;
	cout << "size:" << v.size() << endl;
	cout << "capacity:" << v.capacity() << endl;


	//�����ռ�,
	vector<int>(v).swap(v);
	cout << "--------------------" << endl;
	cout << "size:" << v.size() << endl;
	cout << "capacity:" << v.capacity() << endl;

}

void test07()
{
	vector<int> v;

	//Ԥ���ռ�
	v.reserve(100000);

	int num = 0;
	int* p = NULL;
	for (int i = 0; i < 100000; i++) {
		v.push_back(i);
		if (p != &v[0]) {
			p = &v[0];
			num++;
		}
	}

	cout << "���� �ռ���ٴ� ��  num:" << num << endl;
}
int main()
{
	//test01();
	test02();
	test03();
	test04();
	test05();
	test06();
	test07();
}
