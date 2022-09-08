//map����͸�ֵ
# include <iostream>
using namespace std;
# include <map>

/*
���죺
- map<T1, T2>mp;      //mapĬ�Ϲ��캯��
- map(const map &mp)  //�������캯��

��ֵ��
- map& operator=(const map &mp);     //���صȺŲ�����
*/

void printMap(map<int, int>& m) {
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {

		cout << "key =  " << (*it).first << " value = " << (*it).second << endl;
	}
}

void test01() {

	//����map����
	map<int, int>m;

	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));

	printMap(m);

	cout << "--------------------" << endl;
	//��������
	map<int, int>m2(m);

	printMap(m2);

	cout << "--------------------" << endl;
	//��ֵ
	map<int, int>m3;
	m3 = m2;

	printMap(m3);
}

int main() {

	test01();

	system("pause");

	return 0;
}