//set���Һ�ͳ��
# include <iostream>
using namespace std;
# include <set>

/*
- find(key);         //����key�Ƿ���ڣ������ڣ����ظü���Ԫ�صĵ��������������ڣ�����set.end();
- count(key);        //ͳ��keyԪ�ظ���
*/

void test01() {

	//����
	set<int>s1;

	//��������
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);

	set<int>::iterator pos = s1.find(30);

	if (pos != s1.end()) {

		cout << "�ҵ�Ԫ��" << endl;
		cout << "s1 = " << *pos << endl;
	}
	else {
		cout << "δ�ҵ�" << endl;
	}
}

//ͳ��
void test02() {

	set<int>s1;

	//��������
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);

	//ͳ��30�ĸ���
	int num = s1.count(30);

	//����set���ԣ�ͳ�ƽ��Ҫô��0��Ҫô��1
	cout << "30��" << num << "��" << endl;
}

int main() {

	//test01();
	test02();

	system("pause");

	return 0;
}