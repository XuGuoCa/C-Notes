//list������
# include <iostream>
using namespace std;
# include <string>
# include <list>

class Person {

public:

	Person(string name, int age, int height) {
		this->m_Name = name;
		this->m_Age = age;
		this->m_Height = height;
	}

	string m_Name;
	int m_Age;
	int m_Height;
};

//���������
void createPer(list<Person>&L) {

	Person p1("����", 35, 165);
	Person p2("����", 35, 177);
	Person p3("�ڰ���", 16, 175);
	Person p4("С��", 18, 155);
	Person p5("��ͽ", 35, 176);

	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
}

//�������
bool comparePer(Person& p1, Person& p2) {

	//�������� ����
	if (p1.m_Age == p2.m_Age) {

		return p1.m_Height > p2.m_Height;
	}

	return p1.m_Age < p2.m_Age;
}

//��ʾ����
void showPer(const list<Person>&L) {

	for (list<Person>::const_iterator it = L.begin(); it != L.end(); it++) {

		cout << " ������" << (*it).m_Name << " \t���䣺" << (*it).m_Age << " \t��ߣ�" << (*it).m_Height << endl;
	}
}

int main() {

	//���������
	list<Person>L;
	createPer(L);
	cout << "����ǰ" << endl;
	showPer(L);

	cout << "------------------------------------------------------" << endl;
	//����
	L.sort(comparePer);
	cout << "�����" << endl;
	showPer(L);

	system("Pause");

	return 0;
}

