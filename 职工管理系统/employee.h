//Ա����
#pragma once
# include <iostream>
using namespace std;
# include "worker.h"

class Employee : public Worker {

public:

	//���캯��
	Employee(int Id, string name, int dId);

	//��ʾ������Ϣ
	virtual void showInfo();

	//��ȡ��λ����
	virtual string getDeptName();


};