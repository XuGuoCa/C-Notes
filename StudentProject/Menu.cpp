# include "Menu.h"

void Menu() {

	Science Data;
	int Choose;

	cout << "" << endl;
	cout << "欢迎来到教师版学生管理系统!" << endl;

	while (true) {

		cout << "" << endl;
		cout << "请选择你的功能：" << endl;
		cout << "___________________" << endl;
		cout << "|1.  添加学生资料  |" << endl;
		cout << "|2.  添加学生成绩  |" << endl;
		cout << "|3.  查找学生资料  |" << endl;
		cout << "|4. 学生总成绩排名 |" << endl;
		cout << "|5.学生各科成绩排名|" << endl;
		cout << "|0.    退出程序    |" << endl;
		cout << "|__________________|" << endl;

		cout << "" << endl;
		cout << "请选择：";
		cin >> Choose;

		if (Choose == 0) {

			return;
		}
		Function(Data, Choose);
	}
}
