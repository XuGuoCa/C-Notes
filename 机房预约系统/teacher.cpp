# include "teacher.h"

//���캯��
Teacher::Teacher() {


}

//�вι��캯��
Teacher::Teacher(int empid, string name, string pwd) {

	this->m_EmpId = empid;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

//�˵�����
void Teacher::operMenu() {

	system("cls");
	cout << "��ӭ��ʦ��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.���ԤԼ              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

//�鿴����ԤԼ
void Teacher::showAllOrder() {

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

	system("cls");
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

//���ԤԼ
void Teacher::validOrder() {

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

	system("cls");
	cout << "����˼�¼����:" << endl;

	vector<int>v;
	int index = 0;

	cout << "\t\t -----------------------------------------------------------------\n";
	cout << "\t\t|                                                                 |\n";
	for (int i = 0; i < of.m_Size; i++) {

		if (of.m_orderDate[i]["���״̬"] == "1") {

			v.push_back(i);
			cout << "\t\t|  " << ++index << " ";
			cout << "ԤԼ�����ڣ� ��" << of.m_orderDate[i]["ʱ��"];
			cout << "  ʱ��Σ�" << (of.m_orderDate[i]["ʱ���"] == "1" ? "����" : "����");
			cout << "  ������ţ�" << of.m_orderDate[i]["�������"];
			string status = "  ״̬��";
			if (of.m_orderDate[i]["���״̬"] == "1") {

				status += "����� ";
			}

			cout << status << "   |\n";
			cout << "\t\t|                                                                 |\n";
		}
	}

	cout << "\t\t -----------------------------------------------------------------\n";
	cout << "��������˵�ԤԼ��¼��0������" << endl;
	int select;
	int ret;
	while (true) {

		cout << "����:";
		cin >> select;
		if (select > 0 && select <= of.m_Size) {


			if (select == 0) {

				break;
			}
			else {
				system("cls");
				cout << "\t\t ----------------------------------\n";
				cout << "\t\t|                                  |\n";
				cout << "\t\t|             1.ͨ  ��             |\n";
				cout << "\t\t|                                  |\n";
				cout << "\t\t|             2.�� ͨ  ��          |\n";
				cout << "\t\t|                                  |\n";
				cout << "\t\t ----------------------------------\n";
				cout << "��������˽��:";
				cin >> ret;

				if (ret == 1) {

					of.m_orderDate[v[select - 1]]["���״̬"] = "2";
				}
				else {

					of.m_orderDate[v[select - 1]]["���״̬"] = "-1";
				}

				of.updateOrder();
				system("cls");
				cout << "\t\t ----------------------------------\n";
				cout << "\t\t|                                  |\n";
				cout << "\t\t|            �����ϣ�            |\n";
				cout << "\t\t|                                  |\n";
				cout << "\t\t ----------------------------------\n";
				system("pause");
				system("cls");
				break;
			}
		}
			cout << "������������������" << endl;
	}
}