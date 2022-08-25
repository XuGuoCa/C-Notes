#pragma once
# include <iostream>
using namespace std;
# include <string>

class Worker {
public:

	//显示个人信息
	virtual void ShowInfo() = 0;
	//获取岗位名称
	virtual string getDeptName() = 0;


	//个人编号
	int m_Id;
	//职工姓名
	string m_Name;
	//职工所在部门的名称编号
	int m_DeptId;
};