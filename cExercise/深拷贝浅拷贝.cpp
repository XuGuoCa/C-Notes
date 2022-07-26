//�����ǳ����
# include <iostream>
using namespace std;

class Person {

public:
	int m_Age;
	int *m_Height;

	Person() {

		cout << "Person Ĭ�Ϲ��캯���ĵ���" << endl;
	}

	Person(int age, int height) {

		cout << "Person �вι��캯���ĵ���" << endl;
		m_Age = age;
		m_Height = new int(height);
	}

	Person(const Person& p) {

		cout << "Person �������캯���ĵ���" << endl;
		m_Age = p.m_Age;
		//m_Height = p.m_Height;//������Ĭ��ʵ�ֵľ������д���

		m_Height = new int(*p.m_Height);
	}

	~Person() {

		cout << "Person ���������ĵ���" << endl;

		if (m_Height != NULL) {

			delete m_Height;
			m_Height = NULL;
		}
	}
};

void test01() {

	Person p1(18, 160);

	cout << "p1������Ϊ��" << p1.m_Age << "  p1�����Ϊ��" << *p1.m_Height << endl;
	
	Person p2(p1);

	cout << "p2������Ϊ��" << p2.m_Age << "  p2�����Ϊ��" << *p2.m_Height << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}