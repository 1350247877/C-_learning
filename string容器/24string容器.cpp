#include<iostream>
#include<string>
using namespace std;

//��ʼ��
void test01() {
	string a1; //�޲ι��캯��
	string a2("abcdefg", 10);
	string a3("abcdefd");
	string a4(a3);//��������

	cout << a1 << endl;
	cout << a2 << endl;
	cout << a3 << endl;
	cout << a4 << endl;
}

//��ֵ����
void test02()
{
	string s1;
	string s2("aap");
	s1 = "abcdfdsf";
	cout << s1 << endl;
	s1 = s2;
	cout << s1 << endl;
	s1 = "a";
	cout << s1 << endl;

	//��Ա����
	s1.assign("jdk");
	cout << s1 << endl;
}
//ȡֵ����
void test03()
{
	string  s1 = "abcdefg";
	//����[]������
	for (int i = 0; i < s1.size(); i++)
	{
		cout << s1[i] << "";  //ʹ��[] ��������Ǳ�Խ���ֱ�ӳ���ֹͣ
	}
	cout << endl;
	//at ��Ա����
	for (int i = 0; i < s1.size(); i++)
	{
		cout << s1.at(i) << " "; //ʹ��at ��������Ǳ�Խ��� �׳��쳣 out of range
	}
	cout << endl;


}
//�ַ���ƴ��
void test04()
{
	string s = "adbcd";
	string s2 = "1111";
	s += "adbdfsf";
	s += s2;
	cout << s << endl;

	string s3 = "22222";

	s2.append(s3);
	
	cout << s2 << endl;

	string s4 = s2 + s3;
	cout << s4 << endl;

}

//���Ҳ���
void test05()
{
	string s = "adbdsfdsf";
	int pos = s.find("f");
	cout << "��һ�γ��ֵ�λ��pos  " << pos << endl;

	int pos2 = s.rfind("f");
	cout << "�� ���һ�γ��ֵ�λ��pos  " << pos2 << endl;
}

//�滻
void test06() {
	string s = "asdbdsfd";
	s.replace(0, 2, "111");
	cout << s << endl;
}
//string�Ƚ�
void test07()
{
	string s1 = "adbc";
	string s2 = "avg";
	if (s1.compare(s2) == 0)
	{
		cout << "�ַ������" << endl;
	}
	else {
		cout << "�ַ��������" << endl;
	}
}
//�Ӵ�
void test08()
{

	string str = "abcdefg";
	string subStr = str.substr(1, 3);
	cout << "subStr = " << subStr << endl;

	string email = "hello@sina.com";
	int pos = email.find("@");
	string username = email.substr(0, pos);
	cout << "username: " << username << endl;

}
//�ַ��������ɾ��
void test09()
{
	string str = "hello";
	str.insert(1, "111");
	cout << str << endl;

	str.erase(1, 3);  //��1��λ�ÿ�ʼ3���ַ� ,ɾ��
	cout << str << endl;
}
int main(void)
{
	test01();
	test02();
	test03();
	test04();
	test05();
	test06();
	test07();
	test08();
	test09();
}