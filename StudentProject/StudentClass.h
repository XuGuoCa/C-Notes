# include <iostream>
using namespace std;
# include <string>

# ifndef HERO_H
# define HERO_H


class StudentData {

	friend class Science;
	friend void Add(Science& Data);

private:
	string name; //名字
	string StuNum; //学号
	int MarkYuWen; //语文成绩
	int MarkShuXue; //数学成绩
	int MarkYingYu; //英语成绩
	int MarkWuLi;  //物理成绩
	int MarkShengWu;  //生物成绩
	int MarkHuaXue; //化学成绩
};

class Science {

public:
	StudentData Data[1000]; //理科生资料和成绩
	int Thnumber = 0;  //理科生个数
};

# endif
