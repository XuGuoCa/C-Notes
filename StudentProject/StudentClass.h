# include <iostream>
using namespace std;
# include <string>

# ifndef HERO_H
# define HERO_H


class StudentData {

	friend class Science;
	friend void Add(Science& Data);

private:
	string name; //����
	string StuNum; //ѧ��
	int MarkYuWen; //���ĳɼ�
	int MarkShuXue; //��ѧ�ɼ�
	int MarkYingYu; //Ӣ��ɼ�
	int MarkWuLi;  //����ɼ�
	int MarkShengWu;  //����ɼ�
	int MarkHuaXue; //��ѧ�ɼ�
};

class Science {

public:
	StudentData Data[1000]; //��������Ϻͳɼ�
	int Thnumber = 0;  //���������
};

# endif
