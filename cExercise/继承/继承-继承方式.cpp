# include <iostream>
using namespace std;
 
//�����̳�
class Base1 {

public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son1 : public Base1 {

public:
	void func() {

		m_A = 100;
		m_B = 100;
		//m_C = 100; //wrong ������˽�г�Ա������ʲ����� ���������ּ̳з�ʽ���඼�̳в���
	}
};

void test01() {

	Son1 s1;
	s1.m_A = 1000;
	//s1.m_B = 1000; // ���� ����Son1�� m_B�Ǳ���Ȩ�� ������ʲ���
}

//�����̳�
class Base2 {

public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son2 : protected Base2 {

public:
	void func() {

		m_A = 100; //�����й�����Ա�� �������б�Ϊ����Ȩ��
		m_B = 100; //�����б�����Ա�� �������б�Ϊ����Ȩ��
		//m_C = 100; //wrong ������˽�г�Ա������ʲ����� ���������ּ̳з�ʽ���඼�̳в���
	}
};

void test02() {

	Son2 s1;
	//s1.m_A = 1000; //wrong ��Song2�� m_A��Ϊ����Ȩ�ޣ� ���������ʲ���
	//s1.m_B = 1000;  //wrong ��Song2�� m_A��Ϊ����Ȩ�ޣ� ���������ʲ���
}

//˽�м̳�
class Base3 {

public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son3 : private Base3 {

	void func() {

		m_A = 100;  //�����й�����Ա�� �������б�Ϊ˽��Ȩ��
		m_B = 100;  //�����б�����Ա�� �������б�Ϊ˽��Ȩ��
	}
};
void test() {

	//m_A = 1000; //wrong ��Song3�� m_A��Ϊ˽��Ȩ�ޣ� ���������ʲ���
	//m_B = 1000; //wrong ��Song3�� m_A��Ϊ˽��Ȩ�ޣ� ���������ʲ���
}

class Grand3 : public Son3 {

	//m_A = 100; //��Ϊ����Son3��˽��Ȩ�ޣ� ��������Grand3���ʲ���
	//m_B = 1000;
};

int main() {

	system("pause");

	return 0;
}