# include <iostream>
using namespace std;

//����ĳ�ʼ��������
//1.���캯�� ���г�ʼ������

class Person {
public:
	//1.���캯��û�з���ֵ ����дvoid
	//��������������ͬ
	//���캯�������в����� ���Է�������
	//���������ʱ�� ���캯�����Զ����ã�����ֻ����һ��
	Person() {
		cout << "Person ���캯���ĵ���" << endl;
	}
	~Person() {

		cout << "Person ���������ĵ���" << endl;
	}
};

//2.���캯�� �����������

void test01() {

	//Person p; //��ջ�ϵ����� ��test01������ �ͷ��������
}

int main() {

	//test01();
	Person p;

	system("pause");

	return 0;
}