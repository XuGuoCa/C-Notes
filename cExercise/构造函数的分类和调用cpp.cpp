# include <iostream>
using namespace std;

class Person {

public:
		//���캯��
		Person() {
		cout << "Person ���޲ι��캯������" << endl;
	}
	Person(int a) {

		age = a;
		cout << "Person ���вι��캯������" << endl;
	}
	//�������캯��
	Person(const Person& p) {
		//������������ϵ��������ԣ�������������
		age = p.age;
		cout << "Person �������캯���ĵ���" << endl;
	}

	~Person() {

		cout << "�������캯���ĵ���" << endl;
	}
	int age;
};

//����
void test01() {

	//1.���ŷ�
	Person p1; //�޲κ����Ĺ���
	Person p2(10); //�вκ����Ĺ��캯��
	Person p3(p2);//�������캯��

	//cout << "p2������Ϊ��" << p2.age << endl;
	//cout << "p3������Ϊ��" << p2.age << endl;
	//2.��ʾ��
	
	//3.��ʽת����
}
int main() {

	test01();

	system("Pause");

	return 0;
}