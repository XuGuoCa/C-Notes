//�޸���ϵ��Դ�ļ�
# include"Alter.h"

void Alter(Person& Data) {

	string name, Choose;
	int Choose_1;

	do {
		cout << "" << endl;
		cout << "��������Ҫ�޸ĵ���ϵ�˵����֣�" << endl;
		cin >> name;

		if (Judgement(Data, name) == -1) {

			cout << "" << endl;
			cout << "δ�鵽����ϵ��!" << endl;
		}
		else {

			int i = Judgement(Data, name);
			
			cout << "" << endl;
			cout << "��ѡ�������޸ĵĲ��֣�" << endl;
			cout << "****************" << endl;
			cout << "1.��ϵ��ȫ������" << endl;
			cout << "2.  ��ϵ������  " << endl;
			cout << "3.��ϵ�˵绰����" << endl;
			cout << "4.  ��ϵ�˵�ַ  " << endl;
			cout << "****************" << endl;

			cout << "��ѡ����Ĺ���";
			cin >> Choose_1;

			switch (Choose_1) {
          case 1:
			  cout << "" << endl;
			  cout << "���֣�";
			  cin >> Data.Data[i].name;
			  cout << "�绰���룺";
			  cin >> Data.Data[i].number;
			  cout << "��ַ��";
			  cin >> Data.Data[i].Address;
			  cout << "" << endl;
			  cout << "�޸ĳɹ���" << endl;
	          break;
		  case 2:
			  cout << "" << endl;
			  cout << "���֣�";
			  cin >> Data.Data[i].name;
			  cout << "" << endl;
			  cout << "�޸ĳɹ���" << endl;
			  break;
		  case 3:
			  cout << "" << endl;
			  cout << "�绰���룺";
			  cin >> Data.Data[i].number;
			  break;
		  case 4:
			  cout << "" << endl;
			  cout << "��ַ��" << endl;
			  cin >> Data.Data[i].Address;
			  cout << "" << endl;
			  cout << "�޸ĳɹ���" << endl;
			  break;
		  default:
			  break;
			}
		}

		cout << "" << endl;
		cout << "�㻹Ҫ�����޸���" << endl;
		cout << "����Y/N" << endl;
		cin >> Choose;
	} while (Choose == "Y" || Choose == "y" || Choose == "��");

	if (Choose == "N" || Choose == "n" || Choose == "��") {

		cout << "" << endl;
		cout << "�������˵���" << endl;
	}
}
