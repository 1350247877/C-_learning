#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
template<class T>
class Person {
public :
	Person() {
		this->mAge = 0;
	}
private :
	T mAge;
};
//Ϊʲô,�̳г����ʱ����Ҫ�����ڴ棬������Ҫָ�� ����<int>
//�������������������ǲ�����Ҫ��������ڴ�
class SubPerson :public Person<int> {

};
int main()
{
	return 0;
}