//��ͨ�����ͺ���ģ�������
# include <iostream>
using namespace std;

//1.��ͨ�������ÿ��Է�����ʽ����ת��
//2.����ģ�� ���Զ������Ƶ��� �����Է�����ʽ����ת��
//3.����ģ�� ����ʾָ�����ͣ� ���Է�����ʽ����ת��

//��ͨ����
int myAdd01(int a, int b) {
	return a + b;
}

//����ģ��
template<class T>
T myAdd02(T a, T b) {
	return a + b;
}

void test01() {

	int a = 10;
	int b = 20;
	char c = 'c';  //a - 97, c - 99
	cout << myAdd01(a, c) << endl;  //��ͨ�������Է�����ʽת��
	
	//�Զ������Ƶ�
	//cout << myAdd02(a, c) << endl;  //�����Զ������Ƶ�����ģ�岻���Է�����ʽת��

	//��ʾָ������
	cout << myAdd02<int>(a, c) << endl; //��ʾָ�����ͺ���ģ����Է�����ʽת��
}

int main() {

	test01();

	system("Pause");

	return 0;
}