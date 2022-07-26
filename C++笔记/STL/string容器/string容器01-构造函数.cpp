//string 容器01-构造函数
# include <iostream>
using namespace std;

/*
string 基本概念
    本质：
        string是C++风格的字符串, 而string本质上是一个类

	string 和 char*区别：
	    char* 是一个指针
		string 是一个类， 类内部封装了char* ， 管理这个字符， 是一个char* 型的容器

	特点：
	    string 类内部封装了很多成员方法
		例如：查找find， 拷贝copy， 删除delete 替换replace， 插入insert
		string 管理 char* 所分配的内存， 不用担心复制越界和取值等， 由类内部进行负责

string 构造函数原型：
          string();                              创建一个空的字符串 例如：string str
		  string(const char* s);                 使用字符串s初始化
		  string(const string str);              使用一个string对象初始化另一个string对象
		  string(int n, char c);                 使用n个字符c初始化
	*/

void test01() {

	string s1;  //默认构造

	const char* str = "hello world";
	string s2(str);

	cout << "s2 = " << s2 << endl;

	string s3(s2);

	cout << "s3 = " << s3 << endl;

	string s4(10, 'a');

	cout << "s4 = " << s4 << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}

//总结：string 的多种构造方式没有可比性， 灵活使用即可