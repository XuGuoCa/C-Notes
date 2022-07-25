# include <iostream>
using namespace std;

class Person {

public:
		//构造函数
		Person() {
		cout << "Person 的无参构造函数调用" << endl;
	}
	Person(int a) {

		age = a;
		cout << "Person 的有参构造函数调用" << endl;
	}
	//拷贝构造函数
	Person(const Person& p) {
		//将传入的人身上的所以属性，拷贝到我身上
		age = p.age;
		cout << "Person 拷贝构造函数的调用" << endl;
	}

	~Person() {

		cout << "析构构造函数的调用" << endl;
	}
	int age;
};

//调用
void test01() {

	//1.括号法
	Person p1; //无参函数的构造
	Person p2(10); //有参函数的构造函数
	Person p3(p2);//拷贝构造函数

	//cout << "p2的年龄为：" << p2.age << endl;
	//cout << "p3的年龄为：" << p2.age << endl;
	//2.显示法
	
	//3.隐式转换法
}
int main() {

	test01();

	system("Pause");

	return 0;
}