#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip> //���Ʒ���
using namespace std;

//��׼������
void test01() {
	char ch;
	//while ((ch = cin.get()) != EOF) {
	//	cout << ch << endl;
	//}

	//cin.get
	char ch2;
	cin.get(ch2);//��ȡһ���ַ�

	char buf[256] = { 0 };
	//cin.get(buf, 256);
	cin.getline(buf, 256);//��ȡһ������,�������з�
	cout << buf << endl;
}
//cin.ignore ���Ե�ǰ�ַ�
void test02() {
	char ch;
	cin.get(ch);//�ӻ�����Ҫ���ݣ�����
	//cin.ignore();
	cin.ignore(10,'\n'); //���Ե�ǰ�ַ����ӻ�����ȡ����
	cin.get(ch);
	cout << ch << endl;
}
void test03()
{
	cout << "��������������ַ���" << endl;
	char ch;
	ch = cin.peek();//͵��һ�»����������ص�һ���ַ�
	if (ch >= '0' && ch <= '9')
	{
		int number;
		cin >> number;
		cout << "�������������: " << number << endl;
	}
	else {
		char buf[] = { 0 };
		cin >> buf;
		cout << "����������ַ���: " << buf << endl;
	}
}


//cin.putback  �Żص�������   cin.get  �ӻ�����ȡ��һ���ַ�
void test04()
{
	cout << "��������������ַ���" << endl;
	char ch;
	cin.get(ch); //�ӻ�����ȡ��һ���ַ�

	if (ch >= '0' &&ch <= '9')
	{
		//ch�Żص�������
		cin.putback(ch);
		int number;
		cin >> number;
		cout << "�������������: " << number << endl;
	}
	else {
		//ch�Żص�������
		cin.putback(ch);
		char buf[] = { 0 };
		cin >> buf;
		cout << "����������ַ���: " << buf << endl;
	}
}

//��׼�����
void test05() {
	cout << "hello world "; //����д�Ŀͻ���
	//cout.flush(); //��Ҫˢ�»�����
	cout.put('h').put('d').put('1') << endl; //��ʽ����ַ�
	cout.write("Hello songdongdong ",strlen("Hello songdongdong "));

}
//��ʽ�����
void test06() {
	int number = 10;
	cout.unsetf(ios::dec);//ж�ص�ǰĬ�ϵ�10��������ķ�ʽ
	cout.setf(ios::oct);//���ð˽������
	cout.setf(ios::showbase);//�Ѱ˽��Ƶ�0��x���ֳ���
	cout << number << endl;//012 ���˽��Ƶ���ʽ��
	cout.unsetf(ios::oct);//ж�ذ˽���
	cout.setf(ios::hex);//����16�������
	cout << number << endl;

	cout.width(10);
	cout.fill('*');//Ĭ���Ҷ���
	cout << number << endl;
	cout.setf(ios::left); //�����
	cout << number << endl;


	//ͨ�����Ʒ� ���ã���Ҫ����#include<iomanip> //���Ʒ���
	int number2 = 10;
	cout << hex
		<< setiosflags(ios::showbase) //#include<iomanip> //���Ʒ���
		<< setw(10)
		<< setfill('~')
		<< setiosflags(ios::left)
		<< number2
		<< endl;

}


int main(void)
{
	cout;//ȫ��������
	cin;
	//cerr�л�������clogû��Ŷ������
	cerr;//��׼����������ݵ���ʾ��
	clog;//��ע��־��������ݵ���ʾ��


	//test01();
    //test02();
	//test03();
	//test04();
	//test05();
	test06();
	return 0;
}