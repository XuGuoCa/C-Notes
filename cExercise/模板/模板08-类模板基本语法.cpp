//��ģ���﷨
# include <iostream>
using namespace std;
# include <string>

//��ģ������ã�����һ��ͨ���࣬ ���еĳ�Ա �������Ϳ��Բ������ƶ��� ��һ�����������������

//�﷨��
//template<typename T>
//��

//��ģ��
template<class NameType, class AgeType>
class Person {

public:
	Person(NameType name, AgeType age) {
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson() {
		cout << "name = " << this->m_Name << "  age = " << this->m_Age << endl;
	}

	NameType m_Name;
	AgeType m_Age;
};

void test01() {

	Person<string, int> p1("����", 18);
	p1.showPerson();
}

int main() {

	test01();

	system("pause");

	return 0;
}