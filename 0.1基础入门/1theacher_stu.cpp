#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include<ctime>
using namespace std;
/**
����������

ѧУ������������Ŀ��ÿ����ʦ����5��ѧ�����ܹ���3����ʦ����������

���ѧ������ʦ�Ľṹ�壬��������ʦ�Ľṹ���У�����ʦ������һ�����5��ѧ����������Ϊ��Ա

ѧ���ĳ�Ա�����������Է���������������3����ʦ��ͨ��������ÿ����ʦ��������ѧ����ֵ

���մ�ӡ����ʦ�����Լ���ʦ������ѧ�����ݡ�

*/

struct Studnet
{
	string name;
	int score;
};
struct Teacher
{
	string name;
	Studnet sArray[5];
};

//��������
void allocateSpace(Teacher tArray[], int len)
{
	string tName = "��ʦ";
	string sName = "ѧ��";
	string nameSeed = "ABCDE";
	for (int i = 0; i < len; i++) {
		tArray[i].name = tName + nameSeed[i];
		for (int j = 0; j < 5; j++)
		{
			tArray[i].sArray[j].name = sName + nameSeed[j];
			tArray[i].sArray[j].score = rand() % 61 + 60;

		}
	}
}
//��ӡ����
void printTeachers(Teacher tArray[], int len)
{
	for (int i = 0; i < len; i++)
	{
		
		cout << tArray[i].name << endl;
		for (int j = 0; j < 5; j++)
		{
			cout << "\t������" << tArray[i].sArray[j].name << " ������" << tArray[i].sArray[j].score << endl;
		}
	}
}

int main()
{
	srand((unsigned int)time(NULL));//��������ӣ��� #include <ctime>
	Teacher tArray[3];//��ʦ����
	int len = sizeof(tArray) / sizeof(Teacher);
	allocateSpace(tArray, len);
	printTeachers(tArray, len); 
	system("pause");
	return 0;

}