//list��ת������
# include <iostream>
using namespace std;
# include <list>

/*
reverse();   //��ת����
sort();      //��������
*/

void printList(const list<int>& L) {

	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {

		cout << *it << " ";
	}
	cout << endl;
}

void test01() {

	//��ת
	list<int>L;
	L.push_back(20);
	L.push_back(10);
	L.push_back(90);
	L.push_back(40);
	L.push_back(60);
	L.push_back(30);

	cout << "��תǰ" << endl;
	printList(L);

	//��ת
	L.reverse();
	cout << "��ת��" << endl;
	printList(L);

	cout << "--------------" << endl;

	//���в�֧��������ʵ��������������������ñ�׼�㷨
	//��֧��������ʵ��������������ڲ����ṩ��ӦһЩ�㷨
	//sort(L.begin(), L.end());

	//����
	cout << "����ǰ " << endl;
	printList(L);
	L.sort();
	cout << "�����" << endl;
	printList(L);

}

int main() {

	test01();

	system("pause");

	return 0;
}