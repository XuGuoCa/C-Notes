# include "Add.h"

void Add(Person& Data) {

	int i = 0;

	string Choose;

	do {
		cout << "" << endl;
		cout << "�������ϵ�˵����ϣ�" << endl;
		cout << "����";
		cin >> Data.Data[i].name;
		cout << "�绰���룺";
		cin >> Data.Data[i].number;
		cout << "��ַ��";
		cin >> Data.Data[i].Address;
		i++;
		cout << "" << endl;
		cout << "�㻹Ҫ���������?" << endl;
		cout << "����Y/N" << endl;
		cin >> Choose;


	} while (Choose == "Y" || Choose == "y" || Choose == "��");

	if (Choose == "N" || Choose == "n" || Choose == "��") {

		cout << "" << endl;
		cout << "�������˵�!" << endl;
	}
}