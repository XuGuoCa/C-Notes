//��ͨ�����ͺ���ģ��ĵ��ù���
# include <iostream>
using namespace std;

//1.�������ģ�����ͨ���������Ե��ã� ���ȵ�����ͨ����
//2.����ͨ����ģ������б� ǿ�Ƶ��� ����ģ��
//3.����ģ����Է�����������
//4.�������ģ����Բ������õ�ƥ�䣬 ���ȵ��ú���ģ��

void myPrint(int a, int b) {
	cout << "��ͨ�����ĵ���" << endl;
}

template<class T>
void myPrint(T a, T b) {
	cout << "����ģ��ĵ���" << endl;
}

template<class T>
void myPrint(T a, T b, T c) {
	cout << "����ģ�����صĵ���" << endl;
}

void test01() {

	int a = 10;
	int b = 20;

	//�������ģ�����ͨ���������Ե��ã� ���ȵ�����ͨ����
	myPrint(a, b);

	//����ͨ����ģ������б� ǿ�Ƶ��� ����ģ��
	myPrint<>(a, b);

	//����ģ����Է�����������
	myPrint(a, b, 100);

	//�������ģ����Բ������õ�ƥ�䣬 ���ȵ��ú���ģ��
	char c = 'c';
	char d = 'd';
	myPrint(c, d);
}

int main() {

	test01();

	system("Pause");

	return 0;
}