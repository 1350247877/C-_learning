#include<iostream>

using namespace std;

int  func(int a, int b)
{
	cout << "func(int a, int b) " << endl;
	return 0;
}

int  func(int a, int b,int c )
{
	cout << "func(int a, int b,int c ) " << endl;
	return 0;
}

//1 ������һ�ֺ�������
typedef int(MY_FUNC)(int, int);

//2. ����һ��ָ�� �������͵�ָ������
typedef int(*MY_FUNC_P)(int, int);

int main2(void)
{
	//1.
	MY_FUNC *fp = NULL;
	fp = func;
	fp(10, 20);
	(*fp)(10, 20);

	//2. ����MY_FUNC_P����Ϊ ָ���ˣ����Բ���Ҫ ��*
	//����ָ����һ�������ָ�룬����fp1++,
	MY_FUNC_P fp1 = NULL;
	fp1 = func;
	fp1(10, 20);

	//3. ����
	int(*fp3)(int, int) = NULL;
	fp3 = func;
	fp3(10, 10);



	//4.
	fp3 = func;//fp3 -->func(int,int)
	
	fp3(10, 30);
	//fp3(10, 20, 30);//����

	//5.����ָ�룬ʵ�������ں���ָ�븳ֵ��ʱ���ǻᷢ����������ƥ�䣬
	//     �ڵ��ú���ָ���ʱ�������õĺ������Ѿ��̶��ˡ�
	int(*fp4)(int, int, int) = NULL;//fp4 -->func(int,int,int)
	fp4 = func;
	fp4(10, 20, 30);

	
	return 0;
}