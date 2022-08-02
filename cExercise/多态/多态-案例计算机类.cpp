# include <iostream>
using namespace std;

//��̬�ô���
//1.��֯�ṹ����
//2.�ɶ���ǿ
//3.����ǰ�ںͺ�����չ��ά��

//ʵ�ּ����������
class AbstractCalculator {
public:

	virtual int getResut() {

		return 0;
	}

	int m_Num1;
	int m_Num2;
};

//�ӷ��������
class AddCalculator : public AbstractCalculator {

public:
	int getResut() {
		return m_Num1 + m_Num2;
	}
};

//�����������
class SubCalculator : public AbstractCalculator {

public:
	int getResut() {
		return m_Num1 - m_Num2;
	}
};

//�˷��������
class MulCalculat : public AbstractCalculator {

public:
	int getResut() {
		return m_Num1 * m_Num2;
	}
};

void test() {

	//��̬��ʹ������
	//����ָ�������ָ���������

	//�ӷ�����
	AbstractCalculator* abc = new AddCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;

	cout << abc->m_Num1 << "+" << abc->m_Num2 << "=" << abc->getResut() << endl;

	delete abc; //�����ǵ�����

	//��������
	abc = new SubCalculator;
	abc->m_Num1 = 100;
	abc->m_Num2 = 10;

	cout << abc->m_Num1 << "-" << abc->m_Num2 << "=" << abc->getResut() << endl;

	delete abc;

	//�˷�����
	abc = new MulCalculat;
	abc->m_Num1 = 100;
	abc->m_Num2 = 10;

	cout << abc->m_Num1 << "*" << abc->m_Num2 << "=" << abc->getResut() << endl;

	delete abc;
}

int main() {

	test();

	system("pause");

	return 0;
}