//thisָ�����;
# include <iostream>
using namespace std;

class Person {

public:
	int age;

	Person(int age) {
		this->age = age;
	}

	Person& PersonAddAge(Person &p) {

		this->age += p.age;

		return *this;
	}
};

void test01() {

	Person p(18);


	cout << "p������Ϊ:" << p.age << endl;
}

void test02() {

	Person p1(10);

	Person p2(10);

	p2.PersonAddAge(p1).PersonAddAge(p1).PersonAddAge(p1);

	cout << "p2������Ϊ��" << p2.age << endl;
}

int main() {

	//test01();
	test02();

	system("pause");

	return 0;
}