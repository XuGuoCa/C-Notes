# include "Add.h"

int j = 0, num;

void Add(Science& Data) {

	int i;
	string s;

		cout << "" << endl;
		cout << "��Ҫ��Ӷ���λѧ����" << endl;
		cout << "����:";
		cin >> s;

		/*stringstream iss(s);
		iss >> i;*/

			stringstream iss(s);
			iss >> i;
	i += num;
	cout << "" << endl;
	cout << "�����ѧ��������:" << endl;
	for (j; j < i; j++) 
	{
		Data.Thnumber++;
		cout << "" << endl;
		cout << "�������" << j + 1 << "λͬѧ������" << endl;
		cout << "���֣�";
		cin >> Data.Data[j].name;
		cout << "ѧ��";
		cin >> Data.Data[j].StuNum;
	}
	    num += j;
     	cout << "" << endl;
    	cout << "��ӳɹ���" << endl;
    	cout << "" << endl;
    	cout << "�������˵���" << endl;
    	return;
      
	cout << "" << endl;
	cout << "�������� ����������!" << endl;
	cout << "" << endl;
	cout << "�������˵���" << endl;
}