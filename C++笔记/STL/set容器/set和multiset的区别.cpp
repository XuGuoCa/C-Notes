//set和multiset的区别
# include <iostream>
using namespace std;
# include <set>

void test01() {

	set<int>s1;

	pair<set<int>::iterator, bool> ret = s1.insert(10);

	if (ret.second) {
		cout << "第一次插入成功" << endl;
	}
	else {

		cout << "第一个插入失败" << endl;
	}

	ret = s1.insert(10);

	if (ret.second) {

		cout << "第一次插入成功" << endl;
	}
	else {

		cout << "第一个插入失败" << endl;
	}

	multiset<int>ms;
	//允许插入重复的值
	ms.insert(10);
	ms.insert(10);
	ms.insert(10);
	ms.insert(10);

	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++) {

		cout << *it << " ";
	}
	cout << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}