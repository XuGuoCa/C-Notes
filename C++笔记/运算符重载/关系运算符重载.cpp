//关系运算符号重载
# include <iostream>
using namespace std;
# include <string>

class Person {
	
public:

	Person(string name, int age) {

		m_Name = name;
		m_Age = age;
	}
	string m_Name;
	int m_Age;

	bool operator==(Person& p) {

		if (this->m_Age == p.m_Age && this->m_Name == p.m_Name) {

			return true;
		}

		else {
			return false;
		}
	}

	bool operator!=(Person & p) {

		if (this->m_Name != p.m_Name && this->m_Age != p.m_Age) {
			
			return true;
		}
		else {
			return false;
		}
	}
};

void test01() {

	Person p1("Tom", 18);

	Person p2("Jum", 19);

	if (p1 == p2) {

		cout << "p1和p2是相等的" << endl;
	}

	if (p1 != p2){

		cout << "p1和p2是不想等的" << endl;

	}
}
int main() {

	test01();

	system("pause");

	return 0;
}