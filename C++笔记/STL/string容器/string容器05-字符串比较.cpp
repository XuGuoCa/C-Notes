//string 字符串比较
# include <iostream>
using namespace std;

//功能描述：字符串之间的比较

//比较方式：
//     =返回 0
//     >返回 1
//     <返回 -1

//函数原型：
//      int compare(const string &s) const;  与字符串s比较
//      int compare(const char* s) const;    与字符串s比较

void test01() {

	string str1 = "hello";
	string str2 = "hello";

	if (str1.compare(str2) == 0) {
		cout << "str1等于str2" << endl;
	}
	else if (str1.compare(str2) > 0) {
		cout << "str1 大于 str2" << endl;
	}
	else {
		cout << "str1 小于 str2" << endl;
	}
}

int main() {

	test01();

	system("pause");

	return 0;
}

//总结：字符串对比主要是用于比较两个字符串是否相等， 判断谁大谁小的意义并不是很大