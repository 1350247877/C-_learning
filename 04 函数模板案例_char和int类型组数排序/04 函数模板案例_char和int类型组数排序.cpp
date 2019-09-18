#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;
//��char���ͺ�int���������������

template<class T>
void PrintArray(T* arr, int len)
{
	for (int i = 0; i < len; i++) 
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}


//�Ӵ�С����
template<class T>
void MySort(T *arr, int len) {
	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			if (arr[i] < arr[j]) {
				T temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}


int main()
{
	//����
	int arr[] = { 2,5,2,1,5,1 };
	int len = sizeof(arr) / sizeof(int);
	//���鳤��
	cout << "Before sorting" << endl;
	PrintArray(arr, len);
	MySort(arr, len);
	cout << "After sorting" << endl;
	PrintArray(arr, len);

	cout << " ---------------------" << endl;
	char arr2[] = { 'f','u','k','b','s','m' };
	int len2 = sizeof(arr2) / sizeof(char);
	cout << "Before sorting" << endl;
	PrintArray(arr2, len2);
	MySort(arr2, len2);
	cout << "After sorting" << endl;
	PrintArray(arr2, len2);

	
	return 0;


}
