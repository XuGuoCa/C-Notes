# include <iostream>
using namespace std;

class Base {
public:

	//���麯��
	//ֻҪ��һ�����麯���� ������Ϊ������
	//�������ص㣺
	//1.�޷�ʵ��������
	//2.�����������  ������д�����еĴ��麯���� ����Ҳ���ڳ�����
	virtual void func() = 0;
};

class Son : public Base {
public:
	void func() {     //��д�����еĴ��麯��

		cout << "��д�����еĴ��麯��" << endl;

	}
};

void test() {

	//Base s;// wrong �������޷�ʵ��������
	//new Base;//wrong �������޷�ʵ��������

	//Son s;//wrong ����������¸����еĴ��麯���� �����޷�ʵ��������

	Base* base = new Son;
	base->func();
}

int main() {

	test();

	system("pause");

	return 0;
}