#pragma once
# include <iostream>
# include "identity.h"
# include <vector>
# include "computerRoom.h"
# include "orderFile.h"
# include "globalFile.h"
using namespace std;

//学生类
class Student : public Identity {

public:

	//构造函数
	Student();

	//有参构造
	Student(int id, string name, string pwd);

	//菜单界面
	void operMenu();

	//申请预约
	void applyOrder();

	//查看我的预约
	void showMyOrder();

	//查看所有预约
	void showAllOrder();

	//取消预约
	void cancelOrder();

	//学生学号
	int m_Id;

	//机房容器
	vector<ComputerRoom>vCom;
};
