# include <iostream>
using namespace std;

class Base {

public:

	Base() {
		cout << "Base �Ĺ��캯���ĵ���" << endl;
	}
	~Base() {

		cout << "Base ��������������" << endl;
	}
};

class Son : public Base {


public:

	Son() {

		cout << "Son �Ĺ��캯������" << endl;
	}

	~Son() {

		cout << "Son ��������������" << endl;
	}
};

void test01() {

	Son p1;
}

int main() {

	test01();
	/********************************************
	_____________________________________________
	vs ���Ϊ��
	Base �Ĺ��캯���ĵ���
    Son �Ĺ��캯������
    Son ��������������
    Base ��������������
	_____________________________________________
	**********************************************/

	//�̳��еĹ��������˳�����£�
	//�ȹ��츸�࣬�ٹ������࣬ ������˳���빹�캯��˳���෴

	system("pause");

	return 0;
}