#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;
//�㷨������ͳ��ĳ��Ԫ�صĸ���
int myCount(int * start, int *end ,int val) {
	int num = 0;
	while (start != end) {
		if (*start == val) {
			num++;
		}
		start++;
	}
	return num;
}

int main(void)
{
	//���� ������
	int arr[] = { 0,5,1,4,5 };
	int * pBegin = arr; //��һ��λ��
	int *pEnd = &(arr[sizeof(arr) / sizeof(int)]);
	int num = myCount(pBegin, pEnd, 1);
	cout <<" num : "<< num << endl;
	return 0;

}