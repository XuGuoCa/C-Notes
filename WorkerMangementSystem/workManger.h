//�����ļ�
#pragma once
# include <iostream>
using namespace std;
# include "worker.h"
# include <fstream>
# define FILENAME "empFile.txt"

class WorkManager {

public :
	//���캯��
	WorkManager();

	//չʾ�˵�
	void Show_Menu();

	//�˳�ϵͳ
	void ExitSystem();

	//��¼ְ������
	int m_EmpNum;

	//ְ������ָ��
	Worker** m_EmpArray;

	//���ְ������
	void Add_Emp();

	//�������ݵ��ļ�
	void save();

	//�ж��ļ��Ƿ�Ϊ�յı�־
	bool m_FileIsEmpyty;
	
	//��������
	~WorkManager();
};
