# include <iostream>
using namespace std;
# include "workManger.h"
# include "worker.h"
# include "boss.h"
# include "manager.h"
# include "employee.h"
 
int main() {

	WorkManager wm;
	int choice; 
	while (true) {

	   //չʾ�˵�
		wm.Show_Menu();
		cout << endl;
		cout << "���������ѡ��:";
		cin >> choice;
		cout << endl;

		switch (choice) {
		case 0:   //�˳�ϵͳ
			wm.ExitSystem();
			break;
		case 1:  //���ְ��
			wm.Add_Emp();
			break;
		case 2:  //��ʾְ��
			break;
		case 3:  //ɾ��ְ��
			break;
		case 4:  //�޸�ְ��
			break;
		case 5:  //����ְ��
			break;
		case 6:  //���ձ������
			break;
		case 7:  //��������ĵ�
			break;
		}
	}

	system("pause");

	return 0;
}