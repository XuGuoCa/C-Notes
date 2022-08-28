//���ص��������
# include <iostream>
using namespace std;

//�Զ�������
class MyInteger {

	//��Ԫ��
	friend ostream& operator<<(ostream& cout, MyInteger& myint);

public:

	MyInteger() {

		m_Num = 0;
	}


	//����ǰ��++�����  ��������Ϊ��һֱ��һ�����ݽ��в���
	MyInteger & operator++() {

		//�Ƚ���++����
		m_Num++;
		
		//�ٽ�����������
		return *this;
	}

	//���غ���++�����
	MyInteger operator++(int) {  //int ��ռλ������ ������������ǰ�úͺ��õ���

		//�� ��¼��ʱ���
		MyInteger temp = *this;
		//�� ����
		m_Num++;
		//��󽫼�¼�������
		return temp;
	}

private:
	int m_Num;
};

//����<<�����
ostream& operator<<(ostream &cout, MyInteger &myint) {

	cout << myint.m_Num;

	return cout;
}

void test01() {

	MyInteger myint;

	cout << ++myint << endl;
	cout << myint << endl;
}

void test02() {

	MyInteger myint;

	cout << myint++ << endl;
	cout << myint << endl;
}

int main() {

//test01();
	test02();

	system("pause");

	return 0;
}