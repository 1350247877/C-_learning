#include<iostream>
#include <string>
#include <algorithm>
#include<vector>
#include<deque>
#include<time.h>
using namespace std;
//ѡ����
class Person
{
public:
	Person(string name, int score)
	{
		this->m_Name = name;
		this->m_Score = score;
	}
public:
	string m_Name; //����
	int m_Score;  //ƽ����
};



void createPerson(vector < Person> & v)
{
	string nameSeed = "ABCDEF";
	for (int i = 0; i < 5; i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];

		int score = 0;

		Person p(name, score);

		//��������person���� ���뵽������
		v.push_back(p);
	}
}

//���
void setScore(vector<Person> &v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//����ί���������뵽deque������
		deque<int> d;
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;
			d.push_back(score);
		}
		//����
		sort(d.begin(), d.end());
		//ȥ����ߺ���ͷ�
		d.pop_back();
		d.pop_front();

		//ƽ����
		int sum = 0;
		for (deque<int>::iterator dt = d.begin(); dt != d.end(); dt++)
		{
			sum += *dt;
		}

		int avg = sum / d.size();

		//��ƽ���� ��ֵ��ѡ������
		it->m_Score = avg;
	}
}
void showScore(vector<Person>&v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "������ " << it->m_Name << " ƽ���֣� " << it->m_Score << endl;
	}
}
int main2(void)
{
	//���������
	srand((unsigned int)time(NULL));
	//1.����5��ѡ��
	vector<Person> v;
	createPerson(v);
	setScore(v);
	showScore(v);
	system("pause");

	return 0;

}

