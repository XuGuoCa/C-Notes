# include "manager.h"

//Ĭ�Ϲ���
Manager::Manager() {


}

//�вι���
Manager::Manager(string name, string pwd) {

	this->m_Name = name;
	this->m_Pwd = pwd;
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
	cout << "\t\t|          2.�鿴��ʦ            |\n";
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

//�鿴�˺�
void Manager::showPerson() {


}

//�鿴������Ϣ
void Manager::showComputer() {


}

//���ԤԼ��¼
void Manager::CleanFile() {


}

//��ʼ������
void Manager::initVector() {

	//��ȡѧ���ļ��е���Ϣ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {

		cout << "�ļ���ȡʧ��" << endl;
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

		cout << "�ļ���ȡʧ��" << endl;
		return;
	}

	Teacher t;
	while(ifs >> t.m_EmpId && ifs >> s.m_Name && ifs >> s.m_Pwd) {

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