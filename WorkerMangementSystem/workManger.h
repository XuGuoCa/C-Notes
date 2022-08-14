//管理文件
#pragma once
# include <iostream>
using namespace std;
# include "worker.h"
# include <fstream>
# define FILENAME "empFile.txt"

class WorkManager {

public :
	//构造函数
	WorkManager();

	//展示菜单
	void Show_Menu();

	//退出系统
	void ExitSystem();

	//记录职工人数
	int m_EmpNum;

	//职工数组指针
	Worker** m_EmpArray;

	//添加职工函数
	void Add_Emp();

	//保存数据到文件
	void save();

	//判断文件是否为空的标志
	bool m_FileIsEmpyty;
	
	//析构函数
	~WorkManager();
};
