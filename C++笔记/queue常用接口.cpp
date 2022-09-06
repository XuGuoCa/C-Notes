//queue���ýӿ�
# include <iostream>
using namespace std;
# include <queue>
# include <string>

class Person {

public:

	Person(string name, int age) {
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;
};

//���� Queue
void test01() {

	//��������
	queue<Person>q;

	//׼������
	Person p1("��ɮ", 30);
	Person p2("�����", 999);
	Person p3("��˽�", 99);
	Person p4("ɳ����", 287);

	//���
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);

	//�ж�ֻҪ���в�Ϊ�գ� �鿴��ͷ�� �鿴��β�� ����
	cout << "���д�СΪ:" << q.size() << endl;
	while (!q.empty()) {
		
		//�鿴��ͷ
		cout << "��ͷԪ��----����" << q.front().m_Name << " ����:" << q.front().m_Age << endl;

		//�鿴��β
		cout << "��βԪ��----����" << q.back().m_Name << " ����:" << q.back().m_Age << endl;

		//����
		q.pop();
	}
	cout << "���д�СΪ:" << q.size() << endl;


}

int main() {

	test01();

	system("pause");

	return 0;
}