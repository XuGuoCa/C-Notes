//��ϵ�����������
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

		cout << "p1��p2����ȵ�" << endl;
	}

	if (p1 != p2){

		cout << "p1��p2�ǲ���ȵ�" << endl;

	}
}
int main() {

	test01();

	system("pause");

	return 0;
}