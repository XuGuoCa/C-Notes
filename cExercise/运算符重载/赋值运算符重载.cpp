//��ֵ���������
# include <iostream>
using namespace std;

class Person {
	friend void test01();

public:
	Person(int age) {
		m_Age = new int(age);
	}

	Person & operator=(Person& p) {

		//���������ṩǳ����
		//m_Age = p.m_Age;

		//Ӧ�����ж��Ƿ��������ڶ����� ��������ͷŸɾ��� Ȼ�������
		if (m_Age != NULL) {

			delete m_Age;
			m_Age = NULL;
		}
		//���
		m_Age = new int(*p.m_Age);

		return *this;
	}

	~Person() { //�������������ͷ��ڴ�ʱ����ر���  ��ʱ������Ҫ��������ǳ��������������

		if (m_Age != NULL) {

			delete m_Age;
			m_Age = NULL;
		}
	}


private:
	int *m_Age;
};


void test01() {

	Person p1(18);

	Person p2(20);

	Person p3(10);

	//p2 = p1;

	p3 = p2 = p1; //������������ʱ��ֵ�������Ҫ����һ��p2��ֵ



	cout << "p1 = " << *p1.m_Age << endl;
	cout << "p2 = " << *p2.m_Age << endl;
	cout << "p3 = " << *p3.m_Age << endl;

}

int main() {

	test01();

	system("pause");

	return 0;
}