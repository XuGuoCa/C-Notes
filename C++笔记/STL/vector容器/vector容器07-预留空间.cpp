//vector预留空间
# include <iostream>
using namespace std;
# include <vector>

//功能描述:减少vector在动态扩展容量的扩展次数

//函数原型:
//         reserve(int len);   容器预留len个元素长度， 预留位置不初始化， 元素不可访问

void test01() {

	vector<int>v;

	//利用reserve预留空间
	v.reserve(100000);

	int num = 0;  //统计开辟次数
	int* p = NULL;
	for (int i = 0; i < 100000; i++) {

		v.push_back(i);
		if (p != &v[0]) {
			p = &v[0];
			num++;
		}

	}
	cout << "num = " << num << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}

//总结:如果你的数据量比较大， 可以一开始利用reserve预留空间