//map���Һ�ͳ��
# include <iostream>
using namespace std;
# include <map>

/*
- find(key);          //����key�Ƿ���������ڣ����ظü���Ԫ�صĵ��������������ڣ�����set.end();
- count(key)��        //ͳ��key��Ԫ�ظ���
*/

void test01() {

	//����
	map<int, int>m;

	//��������
	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(4, 40));
	m.insert(make_pair(3, 50));

	map<int, int>::iterator pos = m.find(3);

	if (pos != m.end()) {
		cout << "���Ҹ�Ԫ�� key = " << pos->first << " value = " << pos->second << endl;
	}
	else {

		cout << "Ԫ��δ�ҵ�" << endl;
	}

	//ͳ��
	int num = m.count(3);
	cout << "num = " << num << endl;  //map����������ظ���key��countͳ�ƶ��ԽṹҪô��0Ҫô��1
	//multimap��ͳ�ƿ��ܴ���1
}

int main() {

	test01();

	system("pause");

	return 0;
}