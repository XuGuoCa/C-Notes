#pragma once
# include <iostream>
# include <map>
# include "globalFile.h"
using namespace std;

class OrderFile {

public :

	//���캯��
	OrderFile();

	//����ԤԼ��¼
	void updateOrder();

	//��¼���� key -- ��¼������ value �����¼�ļ�ֵ����Ϣ
	map<int, map<string, string>>m_orderDate;

	//ԤԼ��¼����
	int m_Size;
};