//���Һ���Դ�ļ�
# include "Seek.h"

void Seek(Person &Data) {

	string name, Choose;

	do {
		cout << "" << endl;
		cout << "��������Ҫ������ϵ�˵�����:";
		cin >> name;

		if (Judgement(Data, name) == -1) {
			cout << "" << endl;
			cout << "δ�鵽�������˵���" << endl;
			return;
		}
		else {
			cout << "" << endl;
			cout << "��ϵ��" << Data.Data[Judgement(Data, name)].name << "��Ϣ���£�" << endl;
			cout << "�绰����:" << Data.Data[Judgement(Data, name)].number << "    ��ַ:" << Data.Data[Judgement(Data, name)].Address << endl;
		}
		cout << "" << endl;
		cout << "�㻹Ҫ����������" << endl;
		cout << "����Y/N" << endl;
		cin >> Choose;
	} while (Choose == "Y" || Choose == "y" || Choose == "��");

	if (Choose == "N" || Choose == "n" || Choose =="��") {

		cout << "" << endl;
		cout << "�������˵���" << endl;
	}
}