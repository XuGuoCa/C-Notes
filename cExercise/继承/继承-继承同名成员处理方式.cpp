//�̳�ͬ����Ա����ʽ
# include <iostream>
using namespace std;

class Base {

public:
	int m_A;

	Base() {

		m_A = 100;
	}

	void func() {

		cout << "Base  - func()�ĵ���" << endl;
	}

	void func(int a) {

		cout << "Base  - func(ina a)�ĵ���" << endl;
	}

};

class Son : public Base {

public:
	int m_A;

	Son() {

		m_A = 200;
	}

	void func() {

		cout << "Son - func() �ĵ���" << endl;
	}
};

//ͬ����Ա���Դ���
void test01() {

	Son p1;
	
	cout << "m_A = " << p1.m_A << endl;
	//���ͨ��������� ���ʵ�������ͬ����Ա�� ��Ҫ��������
	cout << "m_A = " << p1.Base::m_A << endl;

	//p1.func(100);// wrong
	//��������г��ָ���ͬ���ĳ�Ա������ ����ͬ����Ա�����ص�����������ͬ����Ա����
	//�������ʵ������ⱻ���ص�ͬ����Ա������ ��Ҫ��������

	p1.Base::func(100);
}

//ͬ����Ա��������
void test02() {

	Son p1;

	p1.func(); //ֱ�ӵ��� �����������е�ͬ����Ա

	//��ε��õ������е�ͬ����Ա��
	p1.Base::func();

}

int main() {

	
	test01();
	//test02();

	system("pause");

		return 0;
}