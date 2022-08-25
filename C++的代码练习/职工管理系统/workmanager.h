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

	//��¼ְ������
	int m_EmpNum;

	//ְ������ָ��
	Worker** m_EmpArray;

	//�ж��ļ��Ƿ�Ϊ�յı�־
	bool m_FileIsEmpyty;

	//��¼�ļ�����
	int get_EmpNum();

	//��ʼ��Ա��
		void inti_Emp();

	//���캯��
	WorkManager();

	//����ְ������ж�ְ���Ƿ���ڣ� �����ڷ���ְ����������λ�ã� �����ڷ���-1
	int IsExist(int id);

	//�����ļ�
	void save();

	//չʾ�˵�
	void Show_Menu();

	//�˳�ϵͳ
	void ExitSystem();

	//���ְ������
	void Add_Emp();

	//��ʾְ��
	void Show_Emp();

	//ɾ��ְ��
	void Del_Emp();

	//�޸�ְ��
	void Mod_Emp();

	//����ְ��
	void Find_Emp();

	//����ְ��
	void Sort_Emp();

	//����ļ�
	void Clean_File();

	//��������
	~WorkManager();
};
