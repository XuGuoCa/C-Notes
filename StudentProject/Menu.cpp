# include "Menu.h"

void Menu() {

	Science Data;
	int Choose;

	cout << "" << endl;
	cout << "��ӭ������ʦ��ѧ������ϵͳ!" << endl;

	while (true) {

		cout << "" << endl;
		cout << "��ѡ����Ĺ��ܣ�" << endl;
		cout << "___________________" << endl;
		cout << "|1.  ���ѧ������  |" << endl;
		cout << "|2.  ���ѧ���ɼ�  |" << endl;
		cout << "|3.  ����ѧ������  |" << endl;
		cout << "|4. ѧ���ܳɼ����� |" << endl;
		cout << "|5.ѧ�����Ƴɼ�����|" << endl;
		cout << "|0.    �˳�����    |" << endl;
		cout << "|__________________|" << endl;

		cout << "" << endl;
		cout << "��ѡ��";
		cin >> Choose;

		if (Choose == 0) {

			return;
		}
		Function(Data, Choose);
	}
}
