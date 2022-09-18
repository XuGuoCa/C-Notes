#pragma once
# include <iostream>
# include <vector>
# include <fstream>
# include <algorithm>
# include "student.h"
# include "teacher.h"
# include "identity.h"
# include "globalFile.h"
# include "computerRoom.h"
using namespace std;

class Manager : public Identity {

public:

	//Ĭ�Ϲ���
	Manager();

	//�вι���
	Manager(string name, string pwd);

	//ѡ��˵�
	void operMenu();

	//����˺�
	void addPerson();

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showComputer();

	//���ԤԼ��¼
	void CleanFile();

	//��ʼ������
	void initVector();

	//ѧ������
	vector<Student>vStu;

	//��ʦ����
	vector<Teacher>vTea;

	//ȥ�غ�����װ
	bool checkRepeat(int id, int type);

	//��������
	vector<ComputerRoom>vCom;
};