//��ģ������Ԫ
# include <iostream>
using namespace std;
# include <string>

//ȫ�ֺ�������ʵ�� - ֱ��������������Ԫ����
//ȫ�ֺ�������ʵ�� - ��Ҫ��ǰ�ñ�����֪��ȫ�ֺ����Ĵ���

template <class T1, class T2>
class Person;

//����ʵ��
template<class T1, class T2>
void printPerson2(Person<T1, T2> p) {
	cout << "����ʵ�� -- ������" << p.m_Name << "  ����ʵ�� -- ����:" << p.m_Age << endl;
}


//ͨ��ȫ�ֺ��� ��ӡPerson��Ϣ

template<class T1, class T2>
class Person {

	//ȫ�ֺ��� ����ʵ��
	friend void printPerson(Person<T1,T2> p) {
		cout << "������" << p.m_Name << "  ����:" << p.m_Age << endl;
	}

	//ȫ�ֺ��� ����ʵ��
	//�ӿ�ģ������б�
	//���ȫ�ֺ��� ������ʵ�֣� ��Ҫ�ñ�������ǰ֪����������Ĵ���
	friend void printPerson2<>(Person<T1,T2> p);

public:
	Person(T1 name, T2 age) {
		m_Name = name;
		m_Age = age;
	}

private:
	T1 m_Name;
	T2 m_Age;
};

void test01() {

	Person<string, int>p("����", 18);
	//printPerson(p);
	printPerson2(p);
}

int main() {

	test01();

	system("pause");

	return 0;
}