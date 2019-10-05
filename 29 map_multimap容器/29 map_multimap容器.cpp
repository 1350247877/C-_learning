#include<iostream>
#include<map>
#include<string>
using namespace std;
void printMap(map<int,int> &m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key ==  " << it->first << "  value = " << it->second << endl;
	}
	cout << endl;
}
void test01()
{
	
	map<int, int> m;//Ĭ�Ϲ��캯��
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));
	m.insert(pair<int, int>(5, 50));

	printMap(m);
	if (m.empty())
	{
		cout << " m Ϊ��" << endl;
	}
	else
	{
		cout << "m��Ϊ�� " << endl;
		cout << "m�Ĵ�СΪ�� " << m.size() << endl;

	}
}

void test02()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));

	map<int, int>m2;
	m2.insert(pair<int, int>(4, 100));
	m2.insert(pair<int, int>(5, 200));
	m2.insert(pair<int, int>(6, 300));


	cout << "����ǰ" << endl;
	printMap(m);
	printMap(m2);

	cout << "������" << endl;
	m.swap(m2);
	printMap(m);
	printMap(m2);

}

void test03()
{
	//����
	map<int, int> m;
	//��һ�ֲ��뷽ʽ
	m.insert(pair<int, int>(1, 10));
	//�ڶ��ֲ��뷽ʽ
	m.insert(make_pair<int, int>(2, 20));
	//�����ֲ��뷽ʽ
	m.insert(map<int, int>::value_type(3, 30));
	//�����ֲ��뷽ʽ
	m[4] = 40;
	//ɾ��
	m.erase(m.begin());
	printMap(m);

	m.erase(3);
	printMap(m);

	//���
	m.erase(m.begin(), m.end());
	m.clear();
	printMap(m);

}
//map���Һ�ͳ��
void test04()
{
	map<int, int> m;
	m.insert(pair<int, int>(1, 10));
	m.insert(make_pair<int, int>(2, 20));
	m.insert(map<int, int>::value_type(3, 30));

	//����
	map<int,int> ::iterator pos = m.find(3);

	if (pos != m.end())
	{
		cout << " �ҵ���Ԫ�� key = " << (*pos).first << " value = " << (*pos).second << endl;
	}
	else
	{
		cout << "δ�ҵ�Ԫ��" << endl;
	}

	pair<map<int, int> ::iterator ,map<int,int>::iterator> ret= m.equal_range(2);//����������key��keyelem��ȵ������޵�������������
	map<int, int>::iterator ret2 = m.lower_bound(2);//���ص�һ��key>= keyElemԪ�صĵ�����
	map<int, int>::iterator ret3 = m.upper_bound(2);////���ص�һ��key> keyElemԪ�صĵ�����

	//(*(ret.first)).first
	if (ret.first->second)
	{
		cout << "�ҵ�low_bound " << endl;
	}
	else
	{
		cout << "û���ҵ�" << endl;
	}
	if (ret.second->second)
	{
		cout << "�ҵ�upper_bound " << endl;
	}
	else
	{
		cout << "û���ҵ�" << endl;
	}

	//ͳ��
	int num = m.count(3);
	cout << " num = " << num << endl;
}

//map��������
class MyCompare2
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};
void test05()
{
	//Ĭ�ϴ�С��������
	//���÷º���ʵ�ִӴ�С����
	map<int, int, MyCompare2> m;
	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(4, 40));
	m.insert(make_pair(5, 50));

	for (map<int, int, MyCompare2>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key: " << it->first << " value " << it->second << endl;
	}


}

//map���䣬��map�з����Զ������ͣ���Ҫ����º�����������map�������Զ�����������զ���򣬻ᱨ��
class Mykey {
public:
	Mykey(int index, int id)
	{
		this->m_id = id;
		this->m_index = index;
	}
public:
	int m_index;
	int m_id;
};

struct myCompare3
{
public:
	bool operator()(Mykey key1, Mykey key2)
	{
		return key1.m_index > key2.m_index;
	}
};
void test06()
{
	map<Mykey, int,myCompare3> mymap;//�Զ������Զ����������ͣ�զ�ţ�
	mymap.insert(make_pair (Mykey(1, 2), 10));
	mymap.insert(make_pair(Mykey(2, 5), 20));
	mymap.insert(make_pair(Mykey(3, 6), 30));
	for(map<Mykey,int, myCompare3> ::iterator it = mymap.begin(); it != mymap.end(); it++)
	{
		cout << it->first.m_index << "  :   " << it->first.m_id <<" value: "<<it->second<< endl;
	}
}

void test07()
{
	map<int, int> mymap;
	mymap.insert(make_pair(1, 1));
	mymap.insert(make_pair(2, 2));
	mymap.insert(make_pair(3, 3));

	mymap.find(3);
}
int main(void)
{
	//test01();
	//test03();
	test04();	
	test05();
	test06();
	system("pause");
}