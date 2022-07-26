//list大小操作
# include <iostream>
using namespace std;
# include <list>

/*
size();                     //返回容器中元素的个数
empty();                    //判断容量是否为空
resize(num);                //重新指向容器的长度为num， 若容器长度变长， 则以默认值填充新位置
							//如果容器变短， 则末尾超出容器长度的元素删除
resize(num, elem);          //重新指定容器的长度为num， 若容器长度变长， 则以elem值填充新位置
							//如果容器变短， 则末尾超出容器长度的元素被删
*/

void printList(const list<int>& L) {

	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {
		
		cout << *it << " ";
	}
	cout << endl;
}

void test01() {

	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	printList(L1);

	if (L1.empty()) {

		cout << "L1 为空" << endl;
	}
	else {

		cout << "L1不为空" << endl;
		cout << "L1的元素个数是多少:" << L1.size() << endl;
	}

	//重新指定大小
	L1.resize(10, 10000);
	printList(L1);

	L1.resize(2);
	printList(L1);
}

int main() {

	test01();

	system("pause");

	return 0;
}