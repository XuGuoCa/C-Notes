# include "CutOut.h"

void CutOut(Person& Data) {

	string name, Choose;

	do {
		cout << "" << endl;
		cout << "��������Ҫɾ������ϵ�˵����֣�" << endl;
		cin >> name;

		if (Judgement(Data, name) == -1) {

			cout << "" << endl;
			cout << "δ�鵽����ϵ��!" << endl;
		}
		else {

			int i = Judgement(Data, name);
			for (i; i < Data.Quantity + 1; i++) {

				Data.Data[i] = Data.Data[i + 1];

			}
			cout << "" << endl;
			cout << "ɾ���ɹ���" << endl;
			Data.Quantity--;
		}
	
		cout << "" << endl;
		cout << "�㻹Ҫ����ɾ����" << endl;
		cout << "����Y/N" << endl;
		cin >> Choose;
	} while (Choose == "Y" || Choose == "y" || Choose == "��");

	if (Choose == "N" || Choose == "n" || Choose == "��") {

		cout << "" << endl;
		cout << "�������˵���" << endl;
	}
}