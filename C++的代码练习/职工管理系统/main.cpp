# include <iostream>
using namespace std;
# include "workmanager.h"
# include "worker.h"
# include "employee.h"
# include "manager.h"
# include "boss.h"

int main() {

	WorkManager wm;
	int select = 0;
	while (true) {
		wm.Show_Menu();
		cout << endl;
		cout << "���������ѡ��:" << endl;
		cout << "����:";
		cin >> select;
		
		switch (select) {
		case 0: // �˳�ϵͳ
			wm.ExitSystem();
			break;
		case 1: // �����ϵ��
			wm.Add_Emp();
			break;
		case 2: // ��ʾ��ϵ��
			wm.Show_Emp();
			break; 
		case 3: // ɾ����ְԱ��
			wm.Del_Emp();
			break;
		case 4: // �޸�ְ��
			wm.Mod_Emp();
			break;
		case 5: //����ְ��
			wm.Find_Emp();
			break;
		case 6: // ���ձ������
			wm.Sort_Emp();
			break;
		case 7: // ��������ĵ�
			wm.Clean_File();
			break;
		}

	}

	system("pause");

	return 0;
}