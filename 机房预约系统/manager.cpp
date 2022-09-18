# include "manager.h"

//Ĭ�Ϲ���
Manager::Manager() {


}

//�вι���
Manager::Manager(string name, string pwd) {

	this->m_Name = name;
	this->m_Pwd = pwd;

	//��ȡ������Ϣ
	ifstream ifs(COMPUTER_FILE, ios::in);

	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum) {

		vCom.push_back(c);
	}

	ifs.close();
}

//ѡ��˵�
void Manager::operMenu() {

	cout << "��ӭ����Ա��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴����            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.���ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

//����˺�
void Manager::addPerson() {

	cout << "����������˺�����" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.���ѧ��            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.��ӽ�ʦ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";

	string fileName;
	string tip;
	ofstream ofs;

	int select;
	cout << "����:";
	cin >> select;
	string errorTip;  //�ظ�������ʾ
	int type;

	system("cls");

	if (select == 1) {

		fileName = STUDENT_FILE;
		tip =  "������ѧ�ţ�";
		errorTip = "ѧ���ظ��� ����������!";
		type = 1;
	}
	else if (select == 2) {

		fileName = TEACHER_FILE;
		tip = "������ְ����ţ�";
		errorTip = "ְ�����ظ��� ���������룡";
		type = 2;
	}
	else {

		cout << "������󣡷��ع���Ա�˵�" << endl;
		system("pause");
		system("cls");
	}

	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	while (true) {
		cout << tip << endl;
		cin >> id;
		if (checkRepeat(id, type)) {

			break;
		}
		cout << errorTip << endl;
		system("pause");
		system("cls");
	}

	cout << "����������:" << endl;
	cin >> name;

	cout << "����������:" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ�" << endl;

	system("pause");
	system("cls");

	ofs.close();
}

void printStudent(Student& s) {

	cout << "\t\t|   ѧ��:" << s.m_Id << "\t����:" << s.m_Name << "\t����:" << s.m_Pwd << " \n";
}

void printTeacher(Teacher& t) {

	cout << "\t\t|   ְ����:" << t.m_EmpId << " \t����:" << t.m_Name << "\t����:" << t.m_Pwd << "\n";
}

//�鿴�˺�
void Manager::showPerson() {

	initVector();
	cout << "��ѡ��鿴������:" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|      1.�鿴����ѧ��            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|      2.�鿴������ʦ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";

	int select;

	cout << "���룺" << endl;
	cin >> select;

	if (select == 1) {

		system("cls");
		cout << "����ѧ����Ϣ����:" << endl;
		cout << "\t\t -------------------------------------------------\n";
		cout << "\t\t|                                            \n";
		for_each(vStu.begin(), vStu.end(), printStudent);
		cout << "\t\t|                                            \n";
		cout << "\t\t -------------------------------------------------\n";
	}
	else {

		system("cls");
		cout << "������ʦ��Ϣ����:" << endl;
		cout << "\t\t --------------------------------------------\n";
		cout << "\t\t|                                            \n";
		for_each(vTea.begin(), vTea.end(), printTeacher);
		cout << "\t\t|                                            \n";
		cout << "\t\t --------------------------------------------\n";
	}

	system("pause");
	system("cls");
}

//�鿴������Ϣ
void Manager::showComputer() {

	system("cls");
	cout << "������Ϣ����:" << endl;
	    cout << "\t\t ------------------------------------\n";
	    cout << "\t\t|                                \n";
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++) {

		cout << "\t\t|   �������:" << it->m_ComId << "\t�����������:" << it->m_MaxNum << "  \n";
		cout << "\t\t|                                \n";
	}
	cout << "\t\t ------------------------------------\n";
	system("pause");
	system("cls");
}

//���ԤԼ��¼
void Manager::CleanFile() {

	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	system("cls");

	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|            ��ճɹ���            |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	system("pause");
	system("cls");
}

//��ʼ������
void Manager::initVector() {

	//��ȡѧ���ļ��е���Ϣ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {

		return;
	}

	this->vStu.clear();
	this->vTea.clear();

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd) {

		this->vStu.push_back(s);
	}
	//cout << "��ǰѧ������Ϊ��" << this->vStu.size() << "��" << endl;
	ifs.close();

	//��ȡ��ʦ�ļ���Ϣ
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open()) {

		return;
	}

	Teacher t;
	while(ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd) {

		this->vTea.push_back(t);
	}
	//cout << "��ǰ��ʦ����Ϊ��" << this->vStu.size() << "��" << endl;
	ifs.close();
}

//ȥ�غ�����װ
bool Manager::checkRepeat(int id, int type) {

	initVector();

	if (type == 1) {

		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++) {

			if (id == it->m_Id) {
				return false;
			}
		}
	}
	else {
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++) {

			if (id == it->m_EmpId) {
				return false;
			}
		}
	}
	return true;
}