//pair���鴴��
# include <iostream>
using namespace std;
# include <string>

/*
���ַ�����
- pair<type, type> p (value1, value2);
- pair<type, type> p = make_pair(value1, value2);
*/

void test01() {

	//��һ�ַ�ʽ
	pair<string, int>p("����", 18);

	cout << "������" << p.first << "  ����:" << p.second << endl;

	//�ڶ��ַ�ʽ
	pair<string, int>p2 = make_pair("����", 18);
	cout << "������" << p.first << "  ����:" << p.second << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}