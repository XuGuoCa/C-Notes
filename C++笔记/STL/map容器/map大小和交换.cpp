//map��С�ͽ���
# include <iostream>
using namespace std;
# include <map>

/*
- size();        //����������Ԫ�ص���Ŀ
- empty();       //�ж������Ƿ�Ϊ��
- swap(st);      //�����������ϵ�����
*/

void printMap(map<int, int>& m) {

	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {

		cout << "key = " << it->first << "  value = " << it->second << endl;
	}
	cout << endl;
}

void test01() {

	map<int, int>m;

	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));

	//�ж�
	if (m.empty()) {

		cout << "mΪ��" << endl;
	}
	else {

		cout << "m��Ϊ��" << endl;

		//��С
		cout << "m�Ĵ�СΪ��" << m.size() << endl;
	}

	//����
	map<int, int>m2;

	m2.insert(pair<int, int>(10, 100));
	m2.insert(pair<int, int>(20, 200));
	m2.insert(pair<int, int>(30, 300));
	m2.insert(pair<int, int>(40, 400));

	cout << "����ǰ:" << endl;
	printMap(m);
	printMap(m2);

	cout << "-------------------" << endl;
	cout << "������" << endl;
	m2.swap(m);
	printMap(m);
	printMap(m2);
}

int main() {

	test01();

	system("pause");

	return 0;
}