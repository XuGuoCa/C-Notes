//�����������������
# include <iostream>
using namespace std;
# include <string>

class Person {

public:

	void operator()(string text) {  //��Ϊ�º����ǳ����

		cout << text << endl;
	}
};

class MyAdd {

public:
	int operator()(int a, int b){

		return a + b;
	}
};

void test01() {

	Person test; 
	test("���!");
}

void test02() {

	MyAdd myadd;
	int ret = myadd(100, 100);
	cout << "ret = " << ret << endl;

	//������������
	cout << MyAdd()(100, 100) << endl;
}

int main() {

	//test01();
	test02();

	system("pause");

	return 0;
}