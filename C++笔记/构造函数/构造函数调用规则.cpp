//���캯�����ù���
#include <iostream>
using namespace std;

//1������һ���࣬ c++���������ÿ�����������3������
	//Ĭ�Ϲ��� ����ʵ�֣�
	//�������� ����ʵ�֣�
	//�������� ��ֵ������
class Person {

public:
	Person() {
		cout << "Person Ĭ�Ϻ����ĵ���" << endl;
	}

	Person(int a) {
		cout << "Person �вκ����ĵ���" << endl;
		m_age = a;
	}

	//Person(const Person & p) {

	//	m_age = p.m_age;
	//	cout << "Person ���������ĵ���" << endl;
	//}
	~Person() {
		cout << "Person ���������ĵ���" << endl;
	}

	int m_age;
};

void test01() {

	Person p;

	p.m_age = 18;

	Person p2(p);
	cout << "p2������Ϊ��" << p2.m_age << endl; //���û��21~25�д������仹����18����Ϊ��û�п�������ʱ������������һ����������ֵ����
}

int main() {

	test01();

	system("pause");

	return 0;
}