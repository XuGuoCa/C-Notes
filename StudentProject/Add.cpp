# include "Add.h"

void Add(Science& Data) {

	int i;

	cout << "" << endl;
	cout << "你要添加多少位学生？" << endl;
	cout << "输入:";
	cin >> i;
	
	cout << "" << endl;
	cout << "请添加学生的资料:" << endl;
	for (int j = 0; j < i; j++) {
		Data.Thnumber++;
		cout << "名字：";
		cin >> Data.Data[j].name;
		cout << "学号";
		cin >> Data.Data[j].StuNum;
	}
}