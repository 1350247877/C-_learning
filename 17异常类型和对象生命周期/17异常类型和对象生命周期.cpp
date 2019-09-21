#include<iostream>

using namespace std;


void func() {
	throw 1;//�׳�int���͵��쳣
}
void func01() {
	throw "exception";
}

class MyException {
public :
	MyException(const  char *str) {
		error = new char[strlen(str) + 1];
		strcpy(error, str);
	}

	MyException(const MyException &ex) {
		this->error = new char[strlen(ex.error) + 1];
		strcpy(this->error, ex.error);
	}
	MyException & operator =(const MyException &ex) {
		if (this->error != NULL) {
			delete[] this->error;
			this->error = NULL;
		}
		this->error = new char[strlen(ex.error) + 1];
		strcpy(this->error, ex.error);
	}

	void what() {
		cout <<error<< endl;
	}
	~MyException() {
		if (error != NULL){
			delete[] error;
	}
	}
public:
	char * error;
};

void func02() {
	throw MyException("�Լ������exception");
}

void test01() {
	try {
		func();
	}
	catch (int e) {
		cout << "�׳��쳣 " << e << endl;
	}
}

void test02() {
	try {
		func01();
	}
	catch (char* e) {
		cout << "�׳��쳣 " << e << endl;
	}
}

void test03() {
	try {

		func02();
	}
	catch (MyException e) {
		e.what();
	}
}

int main() {
	

	test03();
	
}