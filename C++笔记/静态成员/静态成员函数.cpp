//��̬��Ա����
//1�����еĶ��󶼹���һ������
//2����̬��Ա����ֻ�ܷ��ʾ�̬��Ա����
# include <iostream>
using namespace std;

class Person {

public:
	//��̬�ĳ�Ա����
	static void func() {

		m_A = 100;
		m_B = 200;//��̬��Ա���������Է��ʷǾ�̬��Ա����
		cout << "static void func�ĵ���" << endl;
	}

	static int m_A;//��̬��Ա����
	int m_B; // �Ǿ�̬��Ա����
};

int Person::m_A = 0;


void test01() {

	//1,ͨ���������
	Person p;
	p.func();

	//ͨ����������
	Person::func();
}

void test02() {


}
int main() {

	test01();

	system("pause");

	return 0;
}