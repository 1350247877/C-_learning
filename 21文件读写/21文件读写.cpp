#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream> //��ȡ�ļ���ͷ�ļ�
using namespace std;

//1,�ļ���д
void test01() {
	const char * filename = "source.txt";
	const char * TargeName = "target.txt";

	//1,��һ�ִ��ļ��ķ�ʽ
	ifstream ism(filename, ios::in); //ֻ���ķ�ʽ���ļ�
	//ofstream osm(TargeName, ios::out);//û��׷��Ч��
	ofstream osm(TargeName, ios::out |ios::app); //��׷��Ч��
	// 2. �ڶ��ִ��ļ��ķ�ʽ
	//ifstream ism;
	//ism.open(filename, ios::in);

	if (!ism) {
		cout << "���ļ�ʧ��" << endl;
		return;
	}
    // ��ȡ�ļ�
	char ch;
	while (ism.get(ch))
	{
		cout << ch;
		osm.put(ch);//����ȥ
	}

	//�ر��ļ�
	ism.close();
	osm.close();
}

int main(void) {
	test01();
	return 0;
}