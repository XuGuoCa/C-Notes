# include "Show.h"

void Show(Person& Data) {

	cout << "��ϵ����Ϣ���£�" << endl;

	for (int i = 0; i < Data.Quantity; i++) {
		cout << "" << endl;
		cout << "���֣�" << Data.Data[i].name << "    �绰���룺" << Data.Data[i].number << "    ��ַ��" << Data.Data[i].Address << endl;
	}
}