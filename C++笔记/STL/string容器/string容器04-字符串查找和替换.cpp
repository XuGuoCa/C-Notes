//string���Һ��滻
# include <iostream>
using namespace std;
# include <string>

//����������
//���ң�����ָ���ַ����Ƿ����
//�滻����ָ����λ���滻�ַ���

/*
����ԭ�ͣ�
         1.int find(const string& str, int pos = 0) const;             ����str��һ�γ���λ�ã� ��pos��ʼ����
		 2.int find(const cahr* s, int pos = 0) const;                 ����s��һ�γ���λ�ã� ��pos��ʼ����
		 3.int find(const char* s, int pos, int n) const;              ��posλ�ò���s��ǰn���ַ���һ��λ��
		 4.int find(const char c, int pos = 0) const;                  �����ַ�c��һ�γ���λ��
		 5.int rfind(const string& str, int pos = npos) comst;         ����str���һ�γ���λ�ã� ��pos��ʼ����
		 6.int rfind(const char* s, int pos = npos) const;             ����s���һ�γ���λ�ã� ��pos��ʼ����
		 7.int rfind(const char* s, int pos, int n) const;             ��pos����s��ǰm���ַ����һ��λ��
		 8.int rfind(const char c, int pos = 0) const;                 �����ַ�c���һ�γ��ֵ�λ��
		 9.string& replace(int pos, int n, const string& str);         �滻��pos��ʼn���ַ�Ϊ�ַ���str
		 10.string& replace(int pos, int n, const cahr* s);            �滻��pos��ʼ��n���ַ�Ϊ�ַ���s
		 */

//1. ����
void test01() {

	string str1 = "abcdefgde";
	int pos = str1.find("de");  //����str��һ�γ���λ�ã� ��pos��ʼ����

	if (pos == -1) {

		cout << "δ�ҵ��ַ���" << endl;
	}
	else {

		cout << "�ҵ��ַ���" << endl;
		cout << "pos = " << pos << endl;
	}

	//rfind �� find����
	//rfind���������  find�������Ҳ���

	//rfind
	pos = str1.rfind("de");

	cout << "pos = " << pos << endl;
}

//2. �滻
void test02() {

	string str1 = "abcdefg";

	str1.replace(1, 3, "1111");

	cout << "str1 = " << str1 << endl;
}

int main() {

	//test01();
	test02();

	system("pause");

	return 0;
}

//�ܽ᣺ find���Ҵ������ң� rfind��������
//       find�ҵ��ַ��󷵻ز��ҵĵ�һ���ַ�λ�ã� �Ҳ�������-1
//       replace���滻ʱ�� Ҫָ�����ĸ�λ���� ���ٸ��ַ��� �滻��ʲô���ӵ��ַ���