//老板类
# include "boss.h"

//构造函数
Boss::Boss(int id, string name, int dId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

//显示个人信息
void Boss::ShowInfo() {
	cout << "编号:  " << this->m_Id
		<< "\t姓名:" << this->m_Name
		<< "\t岗位:" << this->getDeptName()
		<< "\t岗位职责: 管理公司所有事务" << endl;
}

//获取岗位名称
string Boss::getDeptName() {
	return string("老板");
}