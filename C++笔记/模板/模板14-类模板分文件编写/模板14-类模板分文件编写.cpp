//��ģ����ļ���д
# include <iostream>
using namespace std;

//��һ�ֽ����ʽ�� ֱ�Ӱ��� Դ�ļ�
//# include "Person.cpp"

//�ڶ��ֽ����ʽ�� ��.h��.cpp�е�����д��һ�� ����׺����Ϊ.hpp�ļ�
# include "Person.hpp"

void test01() {

	Person<string, int>p("����", 18);
	p.showPerson();
}

int main() {

	test01();

	system("pause");

	return 0;
}

//�ܽ᣺�����Ľ����ʽ�ǵڶ��֣� ����ģ���Ա����д��һ�� ������׺����Ϊ.hpp