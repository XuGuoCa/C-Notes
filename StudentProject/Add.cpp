# include "Add.h"

void Add(Science& Data) {

	int i;

	cout << "" << endl;
	cout << "��Ҫ��Ӷ���λѧ����" << endl;
	cout << "����:";
	cin >> i;
	
	cout << "" << endl;
	cout << "�����ѧ��������:" << endl;
	for (int j = 0; j < i; j++) {
		Data.Thnumber++;
		cout << "���֣�";
		cin >> Data.Data[j].name;
		cout << "ѧ��";
		cin >> Data.Data[j].StuNum;
	}
}