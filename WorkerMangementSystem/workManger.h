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

	//��ȡ��¼ְ������
	int get_EmpNum();

	//��ʼ��Ա��
	void inti_Emp();

	//��ʾְ��
	void Show_Emp();

	//ɾ��ְ��
	void Del_Emp();

	//����ְ������ж�ְ���Ƿ���ڣ� �����ڷ���ְ����������λ�ã� �����ڷ���-1
	int IsExist(int id);

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
