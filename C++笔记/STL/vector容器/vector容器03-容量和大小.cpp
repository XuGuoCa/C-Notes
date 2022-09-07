//vector�����ʹ�С
# include <iostream>
using namespace std;
# include <vector>

//������������vector�����������ʹ�С����

//����ԭ�ͣ�
//         1.empty();                    �ж������Ƿ�Ϊ��
//         2.capacity();                 ����������
//         3.size();                     ����������Ԫ�صĸ���
//         4.resize(int num);            ����ָ�������ĳ���Ϊnum�� ���������ȱ䳤�� ����Ĭ��ֵ�����λ��
//                                       ���������̣� ��ĩβ�����������ȵ�Ԫ��ɾ��
//         5.resize(int num, elem);      ����ָ�������ĳ���Ϊnum�� ���������ȱ䳤�� ����elemֵ�����λ��
//                                       ���������̣� ��ĩβ�����������ȵ�Ԫ�ر�ɾ

void printVector(vector<int>& v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {

		cout << *it << " ";
	}
	cout << endl;
}

void test01() {

	vector<int>v1;
	for (int i = 0; i < 10; i++) {

		v1.push_back(i);
	}
	printVector(v1);
	cout << "v1������Ϊ��" << v1.capacity() << endl;
	cout << "v1�Ĵ�СΪ��" << v1.size() << endl;

	//����ָ����С
	v1.resize(15, 100); //�������ذ汾�� ����ָ��Ĭ�����ֵ�� ����2
	printVector(v1);  //�������ָ���ı�ԭ�����ˣ� Ĭ����0�����λ��

	v1.resize(5);
	printVector(v1);  //�������ָ���ı�ԭ�����ˣ� �������ֻ�ɾ����
}

int main() {

	test01();

	system("pause");

	return 0;
}

//�ܽ᣺
//      1.�ж��Ƿ�Ϊ�� -- empty
//      2.����Ԫ�ظ��� -- size
//      3.��������     -- capacity
//      4.����ָ����С -- resize