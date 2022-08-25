#pragma once
# include <iostream>
using namespace std;
# include "person.h"
# define FILENAME "person.txt"
# include <fstream>

class Communication {

public:

	//联系人资料
	Person** m_PerArray;

	//联系人数量
	int m_PerNum;

	//判断文件是否为空
	bool m_FinePer;

	//记录文件人数
	int getPerNum();

	//将数据存入数组中
	void initPer();

	//构造函数
	Communication();

	//菜单界面
	void ComMenu();

	//添加联系人
	void addComPer();

	//将数据存入文件
	void save();

	//显示联系人
	void ShowPer();

	//析构函数
	~Communication();

};
