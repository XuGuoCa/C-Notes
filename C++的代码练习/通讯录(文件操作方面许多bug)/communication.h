#pragma once
# include <iostream>
using namespace std;
# include "person.h"
# define FILENAME "person.txt"
# include <fstream>

class Communication {

public:

	//��ϵ������
	Person** m_PerArray;

	//��ϵ������
	int m_PerNum;

	//�ж��ļ��Ƿ�Ϊ��
	bool m_FinePer;

	//��¼�ļ�����
	int getPerNum();

	//�����ݴ���������
	void initPer();

	//���캯��
	Communication();

	//�˵�����
	void ComMenu();

	//�����ϵ��
	void addComPer();

	//�����ݴ����ļ�
	void save();

	//��ʾ��ϵ��
	void ShowPer();

	//��������
	~Communication();

};
