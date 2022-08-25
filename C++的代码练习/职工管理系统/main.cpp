# include <iostream>
using namespace std;
# include "workmanager.h"
# include "worker.h"
# include "employee.h"
# include "manager.h"
# include "boss.h"

int main() {

	WorkManager wm;
	int select = 0;
	while (true) {
		wm.Show_Menu();
		cout << endl;
		cout << "请输入你的选择:" << endl;
		cout << "输入:";
		cin >> select;
		
		switch (select) {
		case 0: // 退出系统
			wm.ExitSystem();
			break;
		case 1: // 添加联系人
			wm.Add_Emp();
			break;
		case 2: // 显示联系人
			wm.Show_Emp();
			break; 
		case 3: // 删除离职员工
			wm.Del_Emp();
			break;
		case 4: // 修改职工
			wm.Mod_Emp();
			break;
		case 5: //查找职工
			wm.Find_Emp();
			break;
		case 6: // 按照编号排序
			wm.Sort_Emp();
			break;
		case 7: // 清空所有文档
			wm.Clean_File();
			break;
		}

	}

	system("pause");

	return 0;
}