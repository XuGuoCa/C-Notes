//map构造和赋值
# include <iostream>
using namespace std;
# include <map>

/*
构造：
- map<T1, T2>mp;      //map默认构造函数
- map(const map &mp)  //拷贝构造函数

赋值：
- map& operator=(const map &mp);     //重载等号操作符
*/

void printMap(map<int, int>& m) {
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {

		cout << "key =  " << (*it).first << " value = " << (*it).second << endl;
	}
}

void test01() {

	//创建map容器
	map<int, int>m;

	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	m.insert(pair<int, int>(4, 40));

	printMap(m);

	cout << "--------------------" << endl;
	//拷贝构造
	map<int, int>m2(m);

	printMap(m2);

	cout << "--------------------" << endl;
	//赋值
	map<int, int>m3;
	m3 = m2;

	printMap(m3);
}

int main() {

	test01();

	system("pause");

	return 0;
}