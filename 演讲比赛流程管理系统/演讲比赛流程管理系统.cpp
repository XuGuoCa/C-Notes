# include <iostream>
# include "speechManager.h"
using namespace std;

int main() {

	SpeechManager s;
	int choise; //�û���ѡ��

	//�˵�����
	while (true) {
		s.show_Menu();

		cout << "���������ѡ��" << endl;
		cin >> choise; //�����û���ѡ��

		switch (choise) {
		case 0:
			s.exitsYstem();
			break;
		case 1:
			s.startSpeech();
			break;
		case 2:
			s.showRecord();
			break;
		case 3:
			s.clearRecord();
			break;
		default:
			system("cls");
			break;
		}
	}


	system("pause");

	return 0;
}