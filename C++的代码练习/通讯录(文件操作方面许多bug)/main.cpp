# include <iostream>
using namespace std;
# include "communication.h"

int main() {

	Communication ct;
	int select;
	while (true) {
		ct.ComMenu();
		cout << "���������ѡ��:" << endl;
		cout << "����:";
		cin >> select;

		switch (select) {
		case 0:
			break;
		case 1:
			ct.addComPer();
			break;
		case 2:
			ct.ShowPer();
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		}
	}

	system("pause");

	return 0;
}