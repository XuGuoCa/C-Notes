# include "Add.h"

int j = 0, num;

void Add(Science& Data) {

	int i;
	string s;

		cout << "" << endl;
		cout << "你要添加多少位学生？" << endl;
		cout << "输入:";
		cin >> s;

		/*stringstream iss(s);
		iss >> i;*/

			stringstream iss(s);
			iss >> i;
	i += num;
	cout << "" << endl;
	cout << "请添加学生的资料:" << endl;
	for (j; j < i; j++) 
	{
		Data.Thnumber++;
		cout << "" << endl;
		cout << "请输入第" << j + 1 << "位同学的资料" << endl;
		cout << "名字：";
		cin >> Data.Data[j].name;
		cout << "学号";
		cin >> Data.Data[j].StuNum;
	}
	    num += j;
     	cout << "" << endl;
    	cout << "添加成功！" << endl;
    	cout << "" << endl;
    	cout << "返回主菜单！" << endl;
    	return;
      
	cout << "" << endl;
	cout << "输入有误 请重新输入!" << endl;
	cout << "" << endl;
	cout << "返回主菜单！" << endl;
}