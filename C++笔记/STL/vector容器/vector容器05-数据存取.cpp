//vector���ݴ�ȡ
# include <iostream>
using namespace std;
# include <vector>

//������������vector�е����ݵĴ�ȡ����

/*
����ԭ�ͣ�
       at(int idx);      ��������idx��ָ������
	   operator[];       ��������idx��ָ������
	   front();          ���������е�һ������Ԫ��
	   back();           �������������һ��Ԫ������
*/

void test01() {

	vector<int> v;

	for (int i = 0; i < 10; i++) {
		v.push_back(i);
	}

	//����operator[]��ʽ����Ԫ��
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << endl;

	//����at��ʽ����Ԫ��
	for (int i = 0; i < v.size(); i++) {
		cout << v.at(i) << " ";
	}
	cout << endl;

	//��ȡ��һ��Ԫ��
	cout << "��һ��Ԫ��Ϊ��" << v.front() << endl;

	//��ȡ���һ��Ԫ��
	cout << "���һ��Ԫ��Ϊ��" << v.back() << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}

//�ܽ᣺�����õ�������ȡvector������Ԫ�أ�[]��atҲ����
//      front����������һ��Ԫ��
//      back�����������һ��Ԫ��