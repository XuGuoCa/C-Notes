# include "Interface.h"

void Interface(Person &Contact) {

	switch (true) {
		cout << "************" << endl;
		cout << "1.�����ϵ��" << endl;
		cout << "2.�鿴��ϵ��" << endl;
		cout << "3.������ϵ��" << endl;
		cout << "4.ɾ����ϵ��" << endl;
		cout << "5.�޸���ϵ��" << endl;
		cout << "0.�˳��ó���" << endl;
		cout << "************" << endl;

		int Choose;
		cout << "" << endl;
		cout << "ѡ������ʹ�õĹ��ܣ�";
		cin >> Choose;

		//���ܽ���
		Function(Choose, Contact);

		if (Choose == 0) {

			cout << "" << endl;
			cout << "�˳�����!" << endl;

			return;
		}
	}
}
