#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream> //��ȡ�ļ���ͷ�ļ�
using namespace std;
class Person {
public:
	Person(){}
	Person(int age, int id) : age(age), id(id) {}
	void show() {
		cout << "Age: " << age<<"  id: "<<id<< endl;
	}
	
public:
	int age;
	int id;
};
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


//2.�������ļ��������������л�
void test02() {

	//�ı�ģʽ�������ı��ļ���
	//������ģʽ�����Ƕ������ļ���
	Person p1(10, 20), p2(30, 40);//�����Ʊ���
	//��p1,p2 д�뵽�ļ���
	
	const char * TargetName = "target.txt";
	ofstream osm(TargetName, ios::out|ios::binary);

	osm.write((char*)&p1, sizeof(Person));//�����Ƶķ�ʽд�ļ�
	osm.write((char*)&p2, sizeof(Person));
	osm.close();


	//��ȡ�ļ�
	cout << "��ȡ�ļ�" << endl;
	ifstream ism(TargetName, ios::in | ios::binary);
	Person  p3,p4;
	ism.read((char *)&p3, sizeof(Person)); //���ļ��ж�ȡ�������ļ�
	ism.read((char *)&p4, sizeof(Person)); //���ļ��ж�ȡ�������ļ�

	p3.show();
	p4.show();
	cout << p3.age << endl;
}
int main(void) {
	//test01();
	test02();
	return 0;
}