# include <iostream>
using namespace std;
# include <string>

# ifndef HERO_H
# define HERO_H

class StudentData {

private:
	string name;
	string StuNum;
	int MarkYuWen;
	int MarkShuXue;
	int MarkYingYu;
	int MarkWuLi;
	int MarkShengWu;
	int MarkHuaXue;

};

class Science {

private:
	StudentData Data[1000];
};

# endif
