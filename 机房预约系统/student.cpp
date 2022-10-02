# include "student.h"

//���캯��
Student::Student() {

}

//�вι���
Student::Student(int id, string name, string pwd) {

	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	ifstream ifs(COMPUTER_FILE, ios::in);
	
	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum) {

		this->vCom.push_back(c);
	}

	ifs.close();
}

//�˵�����
void Student::operMenu() {

	cout << "��ӭѧ������" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.����ԤԼ              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.�鿴�ҵ�ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          3.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          4.ȡ��ԤԼ              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� ";
}

//����ԤԼ
void Student::applyOrder() {

	    int date;
		int interval;
		int room;

	while (true) {
		cout << "��������ʱ��Ϊ��һ������!" << endl;
		cout << "\t\t ----------------------------------\n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t|            1.��  һ              |\n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t|            2.��  ��              |\n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t|            3.��  ��              |\n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t|            4.��  ��              |\n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t|            5.��  ��              |\n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t ----------------------------------\n";
		cout << "����������ԤԼ��ʱ��: ";


			cin >> date;
			if (date >= 1 && date <= 5) {

				break;
				system("cls");
			}

			cout << "������������������" << endl;
			system("pause");
			system("cls");
	}

	while (true) {

		system("cls");
		cout << "����������ԤԼʱ���:" << endl;
		cout << "\t\t ----------------------------------\n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t|            1.��  ��              |\n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t|            2.��  ��              |\n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t ----------------------------------\n";

		cout << "����:";
		cin >> interval;
		if (interval >= 1 && interval <= 2) {

			break;
		}

		cout << "�����������������" << endl;
		system("pause");
	}

	system("cls");
	while (true) {
		cout << "��ѡ�����:" << endl;
		cout << "\t\t ----------------------------------\n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t|      1�Ż�����������" << this->vCom[0].m_MaxNum << "           | \n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t|      2�Ż�����������" << this->vCom[1].m_MaxNum << "           | \n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t|      3�Ż�����������" << this->vCom[2].m_MaxNum << "           | \n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t ----------------------------------\n";

		cout << "����:";
		cin >> room;

		if (room >= 1 && room <= 3) {

			break;
			system("cls");
		}

		cout << "������������������" << endl;
		system("pause");
		system("cls");

	}

	system("cls");
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|        ԤԼ�ɹ��������          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";

	ofstream ofs(ORDER_FILE, ios::app);
	ofs << "ʱ��:" << date << " ";
	ofs << "ʱ���:" << interval << " ";
	ofs << "ѧ�����:" << this->m_Id << " ";
	ofs << "ѧ������:" << this->m_Name << " ";
	ofs << "�������:" << room << " ";
	ofs << "���״̬:" << 1 << endl;

	ofs.close();

	system("pause");
	system("cls");
}

//�鿴�ҵ�ԤԼ
void Student::showMyOrder() {

	OrderFile of;
	if (of.m_Size == 0) {

		cout << "\t\t ----------------------------------\n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t|            ��ԤԼ��¼!           |\n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t ----------------------------------\n";
		system("pause");
		system("cls");
		return;
	}

	cout << "\t\t ----------------------------------------------------\n";
	cout << "\t\t|                                                    |\n";
	for (int i = 0; i < of.m_Size; i++) {

		if (atoi(of.m_orderDate[i]["ѧ�����"].c_str()) == this->m_Id) {

			cout << "\t\t| ԤԼ���ڣ���" << of.m_orderDate[i]["ʱ��"];
			cout << "  ʱ�Σ�" << (of.m_orderDate[i]["ʱ���"] == "1" ? "����" : "����");
			cout << "  ������" << of.m_orderDate[i]["�������"];
			string status = "  ״̬��";       //0ȡ��ԤԼ  1�����  2��ԤԼ  -1ԤԼʧ��
			if (of.m_orderDate[i]["���״̬"] == "1") {

				status += "�����  ";
			}
			else if (of.m_orderDate[i]["���״̬"] == "2") {

				status += "ԤԼ�ɹ�";
			}
			else if (of.m_orderDate[i]["���״̬"] == "-1") {

				status += "ԤԼʧ��";
			}
			else {

				status += "ԤԼȡ��";
			}
			cout << status;
			cout << " |\n";
			cout << "\t\t|                                                    |\n";
		}
	}
	cout << "\t\t ----------------------------------------------------\n";
	system("pause");
	system("cls");
}

//�鿴����ԤԼ
void Student::showAllOrder() {

	OrderFile of;
	if (of.m_Size == 0) {

		system("cls");
		cout << "\t\t ----------------------------------\n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t|            ��ԤԼ��¼            |\n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t ----------------------------------\n";
		system("pause");
		system("cls");
		return;
	}

	cout << "\t\t --------------------------------------------------------------------\n";
	cout << "\t\t|                                                                    |\n";
	for (int i = 0; i < of.m_Size; i++) {

		cout << "\t\t| " << i + 1 << " ";

		cout << "  ԤԼ���ڣ���" << of.m_orderDate[i]["ʱ��"];
		cout << "  ʱ�Σ�" << (of.m_orderDate[i]["ʱ���"] == "1" ? "����" : "����");
		cout << "  ������" << of.m_orderDate[i]["ѧ������"];
		cout << "  ������" << of.m_orderDate[i]["�������"];
		string status = "  ״̬��";       //0ȡ��ԤԼ  1�����  2��ԤԼ  -1ԤԼʧ��
		if (of.m_orderDate[i]["���״̬"] == "1") {

			status += "�����  ";
		}
		else if (of.m_orderDate[i]["���״̬"] == "2") {

			status += "ԤԼ�ɹ�";
		}
		else if (of.m_orderDate[i]["���״̬"] == "-1") {

			status += "ԤԼʧ��";
		}
		else {

			status += "ԤԼȡ��";
		}
		cout << status;
		cout << " |\n";
		cout << "\t\t|                                                                    |\n";
	}
	cout << "\t\t --------------------------------------------------------------------\n";
	system("pause");
	system("cls");
}

//ȡ��ԤԼ
void Student::cancelOrder() {

	OrderFile of;
	if (of.m_Size == 0) {

		system("cls");
		cout << "\t\t ----------------------------------\n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t|            ��ԤԼ��¼            |\n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t ----------------------------------\n";
		system("pause");
		system("cls");
		return;
	}

	cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼" << endl;
	vector<int>v; //�����������е��±���
	int index = 1;

	cout << "\t\t -----------------------------------------------------------------\n";
	cout << "\t\t|                                                                 |\n";
	for (int i = 0; i < of.m_Size; i++) {

		//���ж�������ѧ��
		if (this->m_Id == atoi(of.m_orderDate[i]["ѧ�����"].c_str())) {  //atio()�Ѷ�ȡ��strigѧ�����ת��Ϊint ����

			//��ɸѡ״̬  ����л�ԤԼ�ɹ�
			if (of.m_orderDate[i]["���״̬"] == "1" || of.m_orderDate[i]["���״̬"] == "2") {

				v.push_back(i);
				cout << "\t\t|  " << index++ << " ";
				cout << "ԤԼ�����ڣ� ��" << of.m_orderDate[i]["ʱ��"];
				cout << "  ʱ��Σ�" << (of.m_orderDate[i]["ʱ���"] == "1" ? "����" : "����");
				cout << "  ������ţ�" << of.m_orderDate[i]["�������"];
				string status = "  ״̬��";
				if (of.m_orderDate[i]["���״̬"] == "1") {

					status += "����� ";
				}
				else if (of.m_orderDate[i]["���״̬"] == "2") {

					status += "ԤԼ�ɹ�";
				}

				cout << status << "   |\n";
				cout << "\t\t|                                                                 |\n";
			}
		}
	}
	cout << "\t\t -----------------------------------------------------------------\n";

	cout << "������ȡ���ļ�¼��0������" << endl;
	int select = 0;

	while (true) {

		cout << "����:";
		cin >> select;

		if (select >= 0 && select <= of.m_Size) {

			if (select == 0) {

				break;
			}
			else {

				of.m_orderDate[v[select - 1]]["���״̬"] = "0";

				of.updateOrder();

				cout << "\t\t ----------------------------------\n";
				cout << "\t\t|                                  |\n";
				cout << "\t\t|            ��ȡ��ԤԼ��          |\n";
				cout << "\t\t|                                  |\n";
				cout << "\t\t ----------------------------------\n";
				break;
			}
		}

		cout << "��������! ����������" << endl;
	}

	system("pause");
	system("cls");
}