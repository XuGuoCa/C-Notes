//string ����02-��ֵ����
# include <iostream>
using namespace std;
# include <string>

/*
������������string �ַ������и�ֵ

��ֵ����ԭ�ͣ�
          1.string& operator=(const cahr* s);                   char*�����ַ��� ��ֵ����ǰ���ַ���
		  2.string& operator=(const string &s);                 ���ַ���s������ǰ���ַ���
		  3.string& operator=(char c);                          �ַ���ֵ����ǰ���ַ���
		  4.string& assign(const char *s);                      ���ַ���s������ǰ�ַ���
		  5.string& assign(const char *s, int n);               ���ַ���s��ǰn���ַ�������ǰ�ַ���
		  6.string& assign(const string &s);                    ���ַ���s������ǰ�ַ���
		  7.string& assign(int n, char c);                      ��n���ַ�c������ǰ�ַ���
		  */

void test01() {

	string str1;
	str1 = "hello world";

	cout << "str1 = " << str1 << endl;

	string str2;
	str2 = str1;

	cout << "str2 = " << str2 << endl;

	string str3;
	str3 = 'a';

	cout << "str3 = " << str3 << endl;

	string str4;
	str4.assign("hello C++");

	cout << "str4 = " << str4 << endl;

	string str5;
	str5.assign("hello C++", 5);

	cout << "str5 = " << str5 << endl;

	string str6;
	str6.assign(str5);

	cout << "str6 = " << str6 << endl;

	string str7;
	str7.assign(10, 'w');

	cout << "str7 = " << str7 << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}

//�ܽ᣺string �ĸ�ֵ��ʽ�ܶ࣬ operator= ���ַ�ʽ�ǱȽ�ʵ�õ�