#pragma once
# include <iostream>
using namespace std;
# include <fstream>
# define FILENAME "empFile.txt"
# include "worker.h"
# include "employee.h"
# include "manager.h"
# include "boss.h"

class WorkManager {
public :

	//记录职工人数
	int m_EmpNum;

	//职工数组指针
	Worker** m_EmpArray;

	//判断文件是否为空的标志
	bool m_FileIsEmpyty;

	//记录文件人数
	int get_EmpNum();

	//初始化员工
		void inti_Emp();

	//构造函数
	WorkManager();

	//按照职工编号判断职工是否存在， 若存在返回职工在数组中位置， 不存在返回-1
	int IsExist(int id);

	//储存文件
	void save();

	//展示菜单
	void Show_Menu();

	//退出系统
	void ExitSystem();

	//添加职工函数
	void Add_Emp();

	//显示职工
	void Show_Emp();

	//删除职工
	void Del_Emp();

	//修改职工
	void Mod_Emp();

	//查找职工
	void Find_Emp();

	//排序职工
	void Sort_Emp();

	//清空文件
	void Clean_File();

	//析构函数
	~WorkManager();
};
