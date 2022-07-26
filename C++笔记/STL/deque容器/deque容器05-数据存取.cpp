//deque数据存取
# include <iostream>
using namespace std;
# include <deque>

/*
at(int idx);         //返回索引idx所指的数据
operator[];          //返回索引idx所指的数据
front();             //返回容器中第一个数据元素
back();              //返回容器中最后一个数据元素
*/

void test01() {

	deque<int>d;
	d.push_back(10);
	d.push_back(20);
	d.push_back(30);
	d.push_front(100);
	d.push_front(200);
	d.push_front(300);

	//通过[]方式访问元素       300 200 100 10 20 30
	for (int i = 0; i < d.size(); i++) {

		cout << d[i] << " ";
	}
	cout << endl;

	//通过at的方式访问元素     300 200 100 10 20 30
	for (int i = 0; i < d.size(); i++) {

		cout << d.at(i) << " ";
	}
	cout << endl;

	cout << "第一个元素为:" << d.front() << endl;     //300
	cout << "最后一个元素为:" << d.back() << endl;    //30
}

int main() {

	test01();

	system("pause");

	return 0;
}