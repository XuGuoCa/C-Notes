//vector���캯��
# include <iostream>
using namespace std;
# include <vector>

//���ܣ�vector���ݽṹ������ǳ����ƣ� Ҳ��Ϊ��������

//vector����ͨ�������𣺲�֮ͬ�����������Ǿ�̬�ռ䣬 ��vector���Զ�̬��չ

//��̬��չ����������ԭ�ռ�֮�������¿ռ䣬 �����Ҹ�����ڴ�ռ䣬 Ȼ��ԭ���ݿ������¿ռ䣬 �ͷſռ�

//vector�����ĵ�������֧��������ʵĵ�����

//��������������vector����

//����ԭ�ͣ�
//        1.vector<T> v;                    ����ģ��ʵ����ʵ�֣� Ĭ�Ϲ��캯��
//        2.vector(v.begin(), v.end());     ��v[begin(), end())�����е�Ԫ�ؿ���������
//        3.vector(n, elem);                ���캯����n��elem��������
//        4.vector(const vector &vec);      �������캯��

void printVector(vector<int>& v) {

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void test01() {

	//Ĭ�Ϲ��캯��
	vector<int> v1;
	
	for (int i = 0; i < 10; i++) {

		v1.push_back(i);
	}
	printVector(v1);

	//v[begin(), end())�����е�Ԫ�ؿ���������
	vector<int> v2(v1.begin(), v1.end());
	printVector(v2);

	//��n��elem��������
	vector<int> v3(10, 100);
	printVector(v3);

	//�������캯��
	vector<int> v4(v3);
	printVector(v4);
}

int main() {

	test01();

	system("pause");

	return 0;
}

//�ܽ᣺vector�Ķ��ֹ��췽ʽû�пɱ��ԣ� ������ü���