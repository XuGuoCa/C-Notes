# include <iostream>
# include "identity.h"
# include "student.h"
# include "teacher.h"
# include "manager.h"
# include "orderFile.h"
using namespace std;

//����Ա�˵�
void managerMenu(Identity*& manager);

//ѧ���˵�
void studentMenu(Identity*& student);

//��ʦ�˵�
void TeacherMenu(Identity*& teacher);

//��¼ģ��
void LoginIn(string fileName, int type) {

	Identity* person = NULL;

	ifstream ifs(fileName, ios::in);

	//�ļ�������
	if (!ifs.is_open()) {

		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	int id = 0;
	string name;
	string pwd;

	//ѧ����¼
	if (type == 1) {

		cout << "���������ѧ��ѧ��" << endl;
		cin >> id;
	}
	//��ʦ��¼
	else if (type == 2) {

		cout << "���������ְ����" << endl;
		cin >> id;
	}

	cout << "�������û���" << endl;
	cin >> name;

	cout << "����������" << endl;
	cin >> pwd;

	int fId;
	string fName;
	string fPwd;

	if (type == 1) {

		//ѧ����¼��֤
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {

			if (id == fId && name == fName && pwd == fPwd) {
				system("cls");
				cout << "\t\t ----------------------------------\n";
				cout << "\t\t|                                  |\n";
				cout << "\t\t|           ѧ����֤�ɹ���         |\n";
				cout << "\t\t|                                  |\n";
				cout << "\t\t ----------------------------------\n";
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2) {

		//��ʦ��¼��֤
		while (ifs >> fId && ifs >> fName && ifs >> fPwd) {


			if (id == fId && name == fName && pwd == fPwd) {

				system("cls");
				cout << "\t\t ----------------------------------\n";
				cout << "\t\t|                                  |\n";
				cout << "\t\t|           ��ʦ��֤�ɹ���         |\n";
				cout << "\t\t|                                  |\n";
				cout << "\t\t ----------------------------------\n";
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				TeacherMenu(person);
				return;
			}
		}
	}
	else if (type == 3) {

		//����Ա��¼��֤
		while (ifs >> fName && ifs >> fPwd) {

			if (name == fName && pwd == fPwd) {

				system("cls");
				cout << "\t\t ----------------------------------\n";
				cout << "\t\t|                                  |\n";
				cout << "\t\t|           ��¼��֤�ɹ���         |\n";
				cout << "\t\t|                                  |\n";
				cout << "\t\t ----------------------------------\n";
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				managerMenu(person);
				return;
			}
		}
	}

	cout << "��֤��¼ʧ��!" << endl;

	system("pause");
	system("cls");
	return;
}

//����Ա�˵�
void managerMenu(Identity*& manager) {

	while (true) {

		//����Ա�˵�
		manager->operMenu();

		Manager* man = (Manager*)manager;
		int select = 0;

		cin >> select;
		system("cls");

		//����˺�
		if (select == 1) {

			man->addPerson();
		}
		//�鿴�˺�
		else if (select == 2) {

			man->showPerson();
		}
		//�鿴����
		else if (select == 3) {

			cout << "�鿴����" << endl;
			man->showComputer();
		}
		//���ԤԼ
		else if (select == 4) {

			man->CleanFile();
		}
		else {
			delete manager;
			cout << "\t\t ----------------------------------\n";
			cout << "\t\t|                                  |\n";
			cout << "\t\t|            ע���ɹ���            |\n";
			cout << "\t\t|                                  |\n";
			cout << "\t\t ----------------------------------\n";
			system("pause");
			system("cls");
			return;
		}
	}
}

//ѧ���˵�
void studentMenu(Identity*& student) {

	while (true) {

		///ѧ���˵�
		student->operMenu();

		Student* stu = (Student*)student;
		int select;

		cin >> select;
		system("cls");

		if (select == 1) { //����ԤԼ

			stu->applyOrder();
		}
		else if (select == 2) { //�鿴Ŀ¼ԤԼ

			stu->showMyOrder();
		}
		else if (select == 3) { //�鿴����ԤԼ

			stu->showAllOrder();
		}
		else if (select == 4) { //ȡ��ԤԼ

			stu->cancelOrder();
		}
		else {
			delete student;
			system("cls");
			cout << "\t\t ----------------------------------\n";
			cout << "\t\t|                                  |\n";
			cout << "\t\t|            ע���ɹ���            |\n";
			cout << "\t\t|                                  |\n";
			cout << "\t\t ----------------------------------\n";
			system("pause");
			system("cls");
			return;
		}
	}
}

//��ʦ�˵�
void TeacherMenu(Identity*& teacher) {

	while (true) {

		//��ʦ�˵�
		teacher->operMenu();

		Teacher* tea = (Teacher*)teacher;
		int select;

		cout << "����:";
		cin >> select;

		if (select == 1) { //�鿴����ԤԼ

			tea->showAllOrder();
		}
		else if (select == 2) { //���ԤԼ

			tea->validOrder();
		}
		else {

			delete teacher;
			system("cls");
			cout << "\t\t ----------------------------------\n";
			cout << "\t\t|                                  |\n";
			cout << "\t\t|            ע���ɹ���            |\n";
			cout << "\t\t|                                  |\n";
			cout << "\t\t ----------------------------------\n";
			system("pause");
			system("cls");
			return;
		}
	}
}

int main() {


	int select;

	while (true) {

		cout << "================================= ��ӭ�������ǲ��ͻ���ԤԼϵͳ====================================" << endl;
		cout << endl << "������������:" << endl;
		cout << "\t\t-----------------------------------------------\n";
		cout << "\t\t|                                              |\n";
		cout << "\t\t|                1. ѧ������                   |\n";
		cout << "\t\t|                                              |\n";
		cout << "\t\t|                2. ��    ʦ                   |\n";
		cout << "\t\t|                                              |\n";
		cout << "\t\t|                3. �� �� Ա                   |\n";
		cout << "\t\t|                                              |\n";
		cout << "\t\t|                0. ��    ��                   |\n";
		cout << "\t\t|                                              |\n";
		cout << "\t\t|                                              |\n";
		cout << "\t\t-----------------------------------------------\n";
		cout << "���������ѡ��:";
		
		cin >> select;  //�����û�ѡ��

		switch (select) {

		case 1:  //ѧ�����
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:  //��ʦ���
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:  //����Ա���
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:  //�˳�����
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("Pause");
			system("cls");
			return 0;
			break;
		default:
			cout << "�����������������룡" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");

	return 0;
}