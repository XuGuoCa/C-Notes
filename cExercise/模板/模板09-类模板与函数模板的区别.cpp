//��ģ���뺯��ģ�������
# include <iostream>
using namespace std;

//��ģ���뺯��ģ��������Ҫ�����㣺
//1.��ģ��û���Զ������Ƶ���ʹ�÷���
//2.��ģ����ģ������б������Ĭ�ϲ���

template<class NameType, class AgeType = int>
class Person {
public :
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

//1.��ģ��û���Զ������Ƶ���ʹ�÷���
void test01() {

	//Person p1("����", 18); //���� �޷�ʹ���Զ������Ƶ�
	Person<string, int> p1("����", 18);  //��ȷ�� ֻ������ʾָ������
	p1.showPerson();
}

//2.��ģ����ģ������б������Ĭ�ϲ���
void test02() {
	Person<string> p2("����", 18);
	p2.showPerson();
}

int main() {

	test01();
	test02();

	system("pause");

	return 0;
}

//�ܽ᣺
//     ��ģ��ʹ��ֻ������ʾָ�����ͷ�ʽ
//     ��ģ���е�ģ������б������Ĭ�ϲ���