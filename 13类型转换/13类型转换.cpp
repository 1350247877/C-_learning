#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


class Building{};
class Animal {};
class Cat: public Animal{};

//static_cast ˵��ʹ��
void static_cast_test() {
	int a = 97;
	char c = static_cast<char>(a);//һ������ת��
	cout << c << endl;


	//������������ָ��
	//int * p = NULL;
	//char *p = static_cast<char*>(p);//����static_cast ��������û�м̳й�ϵ��ָ��

	//����ָ��
	//Building * building = NULL;
	//Animal *ani = static_cast<Building*>(building); //����

	//ת�����м̳й�ϵ��ָ��
	//����ָ��ת������ָ��
	Animal *ani2 = NULL;
	Cat * cat = static_cast<Cat*>(ani2);

	//����ָ��ת���ɸ���ָ��
	Cat* soncat = NULL;
	Animal * anifather = static_cast<Cat*> (soncat);

	//��������ת����������
	Animal aniobj;
	Animal & aniref = aniobj;
	Cat & cat2 = static_cast<Cat&> (aniref);

	//��������ת���ɸ�������
	Cat catobj;
	Cat & catref = catobj;
	Animal & anifater2 = static_cast<Animal&>(catref);

	//static_cast �������õ��������͡��������м̳й�ϵ��ָ���������

}

// dynamic_cast ת�����м̳й�ϵ��ָ��������ã���ת��ǰ����ж������ͼ��
void dynamic_cast_test() {

	//������������
	//int a = 10;
	//char c = dynamic_cast<char>(a);//�����������ڻ�����������

    //�ǻ�����ϵ��ָ��
	//Animal * ani = NULL;
	//Building * building = dynamic_cast<Building*>(ani);//����û�м̳й�ϵ

	//���м̳й�ϵ��ָ��
	//Animal * ani = NULL;
	//Cat * cat = dynamic_cast<Cat*> (ani);//����ԭ������dynamic_cast������ͽ��м�⡣��Ϊ������ָ��ת��������ָ�루��С�������Ͳ���ȫ��
	//����ָ�����ת��Ϊ����ָ�루�Ӵ�С�������Ͱ�ȫ��
	//����ָ��ת��������ָ�루��С�������Ͳ���ȫ�ˡ�

	Cat * cat = NULL;
	Animal * ani = dynamic_cast<Animal*>(cat);


	//���ۣ�dynamic_cast ֻ��ת�����м̳й�ϵ��ָ��������ã����� ֻ����������ת���ɻ�����



}

//const_cast  �����������͡�ָ�롢���û��߶���ָ�롣���á���constȡ������
void const_cast_test() {

	//1,������������
	int a = 10;
	const int& b = a;//����
	//b = 10;//������Ϊ���������޸�
	int & c = const_cast<int&>(b);//��const����ȡ����
	c = 20;//�����޸ģ���Ϊconst�Ѿ���ȡ����

	cout << "a: " << a << endl;
	cout << "b: " << b << endl;
	cout << "c: " << c << endl;

	//��ָ��
	const int *p = NULL;
	int * p2 = const_cast<int*>(p);//��const����ȡ����

	int *p3 = NULL;
	const int * p4 = const_cast<const int*>(p3);//����const����==ת����const int ����

	//�ܽ᣺���Ӻ�ȥ��һ��������const����

}

//reinterpret_cast ǿ������ת�����޹�ָ�����ͣ���������ָ�붼���Խ���ת��
typedef void(*FUNC)(int, int); //����ָ��
typedef int(*FUNC2)(int,char*);//����ָ��
void reinterpret_cast_test() {


	//1. �޹ص�ָ�����Ͷ����Խ���ת��
	Building * building = NULL;
	Animal * ani = reinterpret_cast<Animal*>(building);


	//2. ����ָ��ת��
	FUNC func1;
	FUNC2 func2 = reinterpret_cast<FUNC2>(func1);


}


/**
	�ܽ᣺����Ա����֪��Ҫת������ͱ�����ת��ǰʲô���ͣ�ת������ʲô���ͣ��Լ�ת������ʲô�����
	      һ���念��������������ת���������������ת��

*/


int main(void) {
	static_cast_test();
	const_cast_test();
}