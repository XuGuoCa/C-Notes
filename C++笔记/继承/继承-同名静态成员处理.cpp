//ͬ����̬��Ա����
# include <iostream>
using namespace std;

class Base {

public:
	static int m_A;

	static void func() {

		cout << "Base- static void func()�ĵ���" << endl;
	}
};
int Base::m_A = 100;

class Son : public Base{

public: 
	static int m_A;

	static void func() {

		cout << "Son - static void func()�ĵ���" << endl;
	}
};
int Son::m_A = 200;

//ͬ����̬������Ա����
void test01() {

	//1.ͨ���������
	Son p;
	cout << "ͨ��������ʣ�" << endl;
	cout << "Son �� m_A = " << p.m_A << endl;
	cout << "Base �� m_A = " << p.Base::m_A << endl;

	//2.ͨ����������
	cout << "ͨ��������ʣ�" << endl;
	cout << "Son �� m_A = " << Son::m_A << endl;
	cout << "Base �� m_A = " << Son::Base::m_A << endl;

	/*
	-----------------------------------------------------
	*****************************************************
	vs�����

	 ͨ��������ʣ�
     Son �� m_A = 200
     Base �� m_A = 100
     ͨ��������ʣ�
     Son �� m_A = 200
     Base �� m_A = 100
     �밴���������. . .
	 ****************************************************
	 ____________________________________________________*/

}

//ͬ����̬��Ա����
void test02() {

	Son s;

	//1.ͨ��������ʵ�
	cout << "ͨ���������:" << endl;
	s.func();
	s.Base::func();

	//2.ͨ����������
	cout << "ͨ����������:" << endl;
	Son::func();
	Base::func(); //73�� Base::func(); �к� 74��Son::Base::func(); �е�����һ�� �ȼ�
	Son::Base::func();
}
/*
����������������������������������������������������������������----------
**************************************************************************
vs�����

ͨ���������:
Son - static void func()�ĵ���
Base- static void func()�ĵ���
ͨ����������:
Son - static void func()�ĵ���
Base- static void func()�ĵ���
Base- static void func()�ĵ���
�밴���������. . .
****************************************************************************
����������������������������������������������������������������������������*/

int main() {

	//test01();
	test02();

	system("pause");

	return 0;
}