//Ա����
#pragma once
# include <iostream>
using namespace std;
# include "worker.h"

class Manager : public Worker {

public:

	//���캯��
	Manager(int Id, string name, int dId);

	//��ʾ������Ϣ
	virtual void showInfo();

	//��ȡ��λ����
	virtual string getDeptName();


};