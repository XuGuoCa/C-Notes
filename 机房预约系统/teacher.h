#pragma once
# include <iostream>
# include "identity.h"
using namespace std;

class Teacher : public Identity {

public:

	//���캯��
	Teacher();

	//�вι��캯��
	Teacher(int empid, string name, string pwd);

	//�˵�����
	virtual void operMenu();

	//�鿴����ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validOrder();

	//��ʦ���
	int m_EmpId;
};