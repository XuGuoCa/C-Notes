# include "workmanager.h"


//���캯��
WorkManager::WorkManager() {

	ifstream ifs(FILENAME, ios::in);
	//�ļ������� �� �ļ��Ѵ��ڣ���û�м�¼
	char ch;
	ifs >> ch;
	if (!ifs.is_open() || ifs.eof()) {

		//��ʼ��
		//��ʼ������
		this->m_EmpNum = 0;
		//��ʼ������ָ��
		this->m_EmpArray = NULL;

		//��ʼ���ļ�Ϊ��
		this->m_FileIsEmpyty = true;

		ifs.close();
		return;
	}
	//�ļ��Ѵ��ڣ� Ҳ�м�¼
	int num = this->get_EmpNum();
	this->m_EmpNum = num;
	//�����¿ռ�
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//�ļ���¼��������
	this->inti_Emp();
}

//��¼�ļ�����
int WorkManager::get_EmpNum() {
	ifstream ifs(FILENAME, ios::in);
	int num = 0; //����
	int id;
	string name;
	int dId;

	while (ifs >> id, ifs >> name, ifs >> dId) {
		//ͳ������
		num++;
	}
	ifs.close();
	return num;
}

//��ʼ��Ա��
void WorkManager::inti_Emp() {
	ifstream ifs(FILENAME, ios::in);
	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {

		Worker* worker = NULL;
		if (dId == 1) {
			worker =new Employee(id, name, dId);
		}
		else if (dId == 2) {
			worker = new Manager(id, name, dId);
		}
		else {
			worker = new Boss(id, name, dId);
		}
		
		//��ŵ�������
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}

//����ְ������ж�ְ���Ƿ���ڣ� �����ڷ���ְ����������λ�ã� �����ڷ���-1
int WorkManager::IsExist(int id) {
	for (int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArray[i]->m_Id == id) {
			return i;
		}
	}
	return -1;
}

//�����ļ�
void WorkManager::save() {

	ofstream ofs(FILENAME, ios::out);

	for (int i = 0; i < this->m_EmpNum; i++) {
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}

	ofs.close();
}

//չʾ�˵�
void WorkManager::Show_Menu() {
	cout << "**************************************************" << endl;
	cout << "**************��ӭʹ��ְ������ϵͳ��**************" << endl;
	cout << "**************** 0.�˳�����ϵͳ ******************" << endl;
	cout << "**************** 1.����ְ����Ϣ ******************" << endl;
	cout << "**************** 2.��ʾְ����Ϣ ******************" << endl;
	cout << "**************** 3.ɾ����ְְ�� ******************" << endl;
	cout << "**************** 4.�޸�ְ����Ϣ ******************" << endl;
	cout << "**************** 5.����ְ����Ϣ ******************" << endl;
	cout << "**************** 6.���ձ������ ******************" << endl;
	cout << "**************** 7.��������ĵ� ******************" << endl;
	cout << "**************************************************" << endl;
}

//�˳�ϵͳ
void WorkManager::ExitSystem() {
	cout << "��ӭ�ٴ�ʹ�ã�" << endl;
	system("pause");
	system("cls");
	exit(0);
}

//���ְ������
void WorkManager::Add_Emp() {

	//���ְ������
	int addNum = 0;
	cout << "���������ְ��������:" << endl;
	cin >> addNum;

	if (addNum > 0) {

		int newSize = this->m_EmpNum + addNum;
		Worker** newSpace = new Worker * [newSize];

		//����ְ������
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		int id;
		string name;
		int dId;
		Worker* worker = NULL;

		//�жϱ���Ƿ��ظ�
		int num[100];
		int index = 0;
		bool flag = true;

		//��ʼ����
		for (int i = 0; i < addNum; i++) {

			while (true) {
				cout << "�������" << i + 1 << "��ְ���ı��:" << endl;
				cout << "����:";
				cin >> id;
				int ret = this->IsExist(id);
				for (int j = 0; j < 100; j++) {
					if (num[j] == id) {
						flag = false;
						break;
					}
				}
				if (ret == -1 && flag) {
					break;
				}
				else {
					cout << "�������ظ����������룡" << endl;
					flag = true;
				}
			}
			num[index] = id;
			index++;

			cout << "�������" << i + 1 << "��ְ��������:" << endl;
			cin >> name;

			cout << "��ѡ��ְ����ְλ:" << endl;
			cout << "1.Ա��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;

			int select;
			cin >> select;
			if (select == 1) {
				worker = new Employee(id, name, 1);
			}
			else if (select == 2) {
				worker = new Manager(id, name, 2);
			}
			else {
				worker = new Boss(id, name, 3);
			}
			newSpace[this->m_EmpNum + i] = worker;
		}

		//�ͷſռ�
		delete[] this->m_EmpArray;

		//��������ָ��
		this->m_EmpArray = newSpace;

		//����ְ������
		this->m_EmpNum = newSize;

		this->m_FileIsEmpyty = false;

		//��ӳɹ���ʾ
		cout << "��ӳɹ�" << addNum << "��ְ��!" << endl;

		//�����ݴ����ļ���
		this->save();

		system("pause");
		system("cls");
	}
	else {
		cout << "��������!" << endl;
		system("pause");
		system("cls");
	}
}

//��ʾְ��
void WorkManager::Show_Emp() {

	if (this->m_FileIsEmpyty) {
		cout << "�ļ�������" << endl;
	}
	else {
		for (int i = 0; i < this->m_EmpNum; i++) {

			this->m_EmpArray[i]->ShowInfo();
			cout << endl;
		}
	}
	if (this->m_EmpNum == 0) {
		cout << "�ļ�Ϊ�գ�" << endl;
	}

	system("pause");
	system("cls");
}

//ɾ��ְ��
void WorkManager::Del_Emp() {

	if (this->m_FileIsEmpyty) {
		cout << "�ļ������ڻ��ļ�Ϊ��!" << endl;
	}
	else {
		cout << "��������ְְ����ְ�����:" << endl;
		int id;
		cout << "����:";
		cin >> id;
		if (this->IsExist(id) != -1) {

			int index = this->IsExist(id);
			for (int i = index; i < this->m_EmpNum - i; i++) {

				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			this->save();
			cout << "ɾ���ɹ���" << endl;
			system("Pause");
			system("cls");
		}
		else {
			cout << "���޴��ˣ�" << endl;
		}
	}
	system("pause");
	system("cls");
}

//�޸�ְ��
void WorkManager::Mod_Emp() {
	if (this->m_FileIsEmpyty) {
		cout << "�ļ������ڻ��ļ�Ϊ��!" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "������ְ�����:" << endl;
		int id;
		cout << "����:" << endl;
		cin >> id;

		if (this->IsExist(id) != -1) {
			
			int index = this->IsExist(id);
			delete this->m_EmpArray[index];

			int newId;
			string newName;
			int dselect;

			cout << "����" << id << "��ְ��, ��������ְ����:" << endl;
			//��ֹ�������ظ�
			while (true) {
				cout << "����:";
				cin >> newId;
				if (this->IsExist(newId) == -1) {
					break;
				}
				else {
					cout << "����ְ�����ظ�!" << endl;
				}
			}

			cout << "�������µ�����:" << endl;
			cout << "����:";
			cin >> newName;

			cout << "��ѡ���µĸ�λ:" << endl;
			cout << "1.Ա��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cout << "����:";
			cin >> dselect;

			Worker* worker = NULL;
			if (dselect == 1) {
				worker = new Employee(newId, newName, dselect);
			}
			else if (dselect == 2) {
				worker = new Manager(newId, newName, dselect);
			}
			else {
				worker = new Boss(newId, newName, dselect);
			}

			//�����ݱ�����������
			this->m_EmpArray[index] = worker;
			this->save();
			cout << "�޸ĳɹ���" << endl;
			system("pause");
			system("cls");
		}
		else {
			cout << "���޴��ˣ�" << endl;
			system("pause");
			system("cls");
		}
	}
}

//����ְ��
void WorkManager::Find_Emp() {

	if (this->m_FileIsEmpyty) {
		cout << "�ļ������ڻ��ļ�Ϊ��!" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "��������ҷ���:" << endl;
		cout << "1.���ձ�Ų���" << endl;
		cout << "2.������������" << endl;
		string select;
		cout << "����:";
		cin >> select;

		if (select == "1") {
			cout << "��������:" << endl;
			int id;
			cout << "����:";
			cin >> id;
			int ret = this->IsExist(id);

			//�ж��Ƿ��ҵ�
			if (ret == -1) {
				cout << "���޴���!" << endl;
			}
			else {
				this->m_EmpArray[ret]->ShowInfo();
			}
	  }
		else if (select == "2") {
			cout << "����������:" << endl;
			string name;
			cin >> name;
			bool flag = false;
			int index;

			//�ж��Ƿ����
			for (int i = 0; i < this->m_EmpNum; i++) {
				if (this->m_EmpArray[i]->m_Name == name) {
					flag = true;
					index = i;
				}
			}
			if (flag) {
				this->m_EmpArray[index]->ShowInfo();
			}
			else {
				cout << "���޴���!" << endl;
			}
		}
		else {
			cout << "��������" << endl;
		}
		system("pause");
		system("cls");
   }
}

//����ְ��
void WorkManager::Sort_Emp() {
	if (this->m_FileIsEmpyty) {
		cout << "�ļ������ڻ�Ϊ��!" << endl;
	}
	else {
		cout << "ѡ������ʽ:" << endl;
		cout << "1.��������" << endl;
		cout << "2.��������" << endl;
		string select;
		cout << "����:";
		cin >> select;

		int mainOrMax;
		for (int i = 0; i < this->m_EmpNum; i++) {

			mainOrMax = i;
			for (int j = i + 1; j < this->m_EmpNum; j++) {

				if (select == "1") {
					if (this->m_EmpArray[mainOrMax]->m_Id > this->m_EmpArray[j]->m_Id) {// ����
						mainOrMax = j;
					}
				}
				if (select == "2") {
					if (this->m_EmpArray[mainOrMax]->m_Id < this->m_EmpArray[j]->m_Id) {// ����
						mainOrMax = j;
					}
				}

				if (mainOrMax != i) {
					Worker* temp = this->m_EmpArray[mainOrMax];
					this->m_EmpArray[mainOrMax] = this->m_EmpArray[i];
					this->m_EmpArray[i] = temp;
				}
			}
		}
		if (select != "1" && select != "2") {
			cout << "��������!" << endl;
			system("pause");
			system("cls");
			return;
		}
		cout << "�������ʾ����:" << endl;
		for (int i = 0; i < this->m_EmpNum; i++) {
			this->m_EmpArray[i]->ShowInfo();
			cout << endl;
			this->save();
		}
	}
	system("pause");
	system("cls");
}

//����ļ�
void WorkManager::Clean_File() {

	cout << "ȷ����գ�" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;
	string select;
	cout << "����:";
	cin >> select;

	if (select == "1") {

		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL) {

			for (int i = 0; i < this->m_EmpNum; i++) {
				if (this->m_EmpArray[i] != NULL) {
					delete this->m_EmpArray[i];
				}
			}
			this->m_EmpNum = 0;
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpyty = true;
			cout << "����ɹ�!" << endl;
		}
	}
	system("pause");
	system("cls");
}

//��������
WorkManager::~WorkManager() {
	if (this->m_EmpArray != NULL) {

		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}
