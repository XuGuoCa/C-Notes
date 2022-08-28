# include <iostream>
using namespace std;

//����ģ��
//�﷨��
//template<typename T>
//������������

//�����������ͺ���
void swapInt(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

//�������������ͺ���
void swapDou(double& a, double& b) {
	double temp = a;
	a = b;
	b = temp;
}

//��Ϊ�������鷳����������Ҫģ��
template<typename T> //��������һ��ģ�壬 ���߱�������������н����ŵ�T��Ҫ���� T��һ��ͨ�õ���������
void mySwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

void test() {

	int a = 10;
	int b = 20;
	//swapInt(a, b);
	//���ú���ģ�彻��
	//���ַ�ʽʹ�ú���ģ��
	//1.�Զ������Ƶ�
	//mySwap(a, b);
	//2.��ʾָ������
	mySwap<int>(a, b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	/*double c = 1.1;
	double d = 2.2;
	swapDou(c, d);
	cout << "c = " << c << endl;
	cout << "d = " << d << endl;*/
}

int main() {

	test();

	system("pause");
	
	return 0;
}

//�ܽ᣺
//     1.����ģ�����ùؼ���template
//     2.ʹ�ú���ģ�������ַ�ʽ�� �Զ������Ƶ��� ��ʾָ������
//     3.ģ���Ŀ����Ϊ����߸����ԣ� �����Ͳ�����