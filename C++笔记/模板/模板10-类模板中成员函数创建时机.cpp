//��ģ���г�Ա��������ʱ��
# include <iostream>
using namespace std;

//��ģ���г�Ա�����ڵ���ʱ��ȥ����

class Person1 {
	
public:
	void showPerson1() {
		cout << "Person1 show" << endl;
	}
};

class Person2 {

public:
	void showPerson2() {
		cout << "Person2 show" << endl;
	}
};

template<class T>
class MyClass {

public:
	T obj;

	//��ģ���еĳ�Ա����
	void func1() {
		obj.showPerson1();
	}

	void func2() {
		obj.showPerson2();
	}
};

void test01() {

	MyClass<Person1> p1;
	p1.func1();
}

void test02() {

	MyClass<Person2> p2;
	p2.func2();
}

int main() {

	test01();
	test02();

	system("pause");

	return 0;
}

//�ܽ᣺��ģ���еĳ�Ա����������һ��ʼ�ʹ����ģ� �ڵ���ʱ��ȥ����