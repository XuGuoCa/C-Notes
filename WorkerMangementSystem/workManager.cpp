# include "workManger.h"

//���캯��
WorkManager::WorkManager() {

	//1.�ļ�������
	
	ifstream ifs;
	ifs.open(FILENAME, ios::in);  //���ļ�

	if (!ifs.is_open()) {
		//��ʼ������
		//��ʼ����¼������
		this->m_EmpNum = 0;
		//��ʼ������ָ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpyty = true;
		ifs.close();
		return;
	}
	//�ļ��Ѵ��ڣ� ����û�м�¼
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpyty = true;
		ifs.close();
		return;
	}

	//3.�ļ����ڣ� ���Ҽ�¼����
	int num = this->get_EmpNum();
	this->m_EmpNum = num;

	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//���ļ������ݣ� �浽������
	this->inti_Emp();
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
	cout << endl;
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("Pause");
	exit(0);
}

//���ְ������
void WorkManager::Add_Emp() {

	cout << "��������ӵ�ְ��������:" << endl;

	int addNum = 0;//�����û�����������
	cin >> addNum;

	if (addNum > 0) {
		//���
		//������ӵ��µĿռ��С
		int newSize = this->m_EmpNum + addNum; //�¿ռ����� = ԭ����¼���� + 
		//�����¿ռ�
		Worker ** newSpace = new Worker* [newSize];

		//��ԭ���ռ������ݣ� �������¿ռ���
		if (this->m_EmpNum != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {

				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//��������µ�����
		for (int i = 0; i < addNum; i++) {
			int id;//ְ�����
			string name;//ְ������
			int dSelect;//����ѡ��

			//�жϱ���Ƿ��ظ�
			int ID[100];
			bool flag = true;
			int num = 0;

			while (true) {
				cout << "�������" << i + 1 << "����ְ����ţ�" << endl;
				cin >> id;
				int ret = this->IsExist(id);

				//�ж�����ı���Ƿ��ظ�
				for (int j = 0; j < 100; j++) {
					if (ID[j] == id) {
						flag = false;
					}
				}

				if (ret == -1 && flag == true) {
					break;
				}
				else {
					cout << "����ְ������ظ�����������!" << endl;
					cout << endl;
					flag = true;
				}
			}

			//�ռ�����ı�����ж�
			ID[num] = id;
			num++;

			cout << "�������" << i + 1 << "����ְ��������" << endl;
			cin >> name;

			cout << "��ѡ���ְ���ĸ�λ:" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect) {
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			}
			//������ְ���� ���浽������
			newSpace[this->m_EmpNum + i] = worker;

		}

		//�ͷſռ�
		delete[] this->m_EmpArray;

		//�����¿ռ��ָ��
		this->m_EmpArray = newSpace;

		//�����µ�ְ������
		this->m_EmpNum = newSize;

		//����ְ����Ϊ�յı�־
		this->m_FileIsEmpyty = false;

		//��ʾ��ӳɹ�
		cout << "�ɹ����" << addNum << "��ְ��!" << endl;
		//���浽�ļ���
		this->save();
	}
	else {
		cout << "������������!" << endl;
	}

	//��������� �����ص��ϼ�Ŀ¼
	system("pause");
	system("cls");
}

//�������ݵ��ļ�
void WorkManager::save() {

	ofstream ofs;
	ofs.open(FILENAME, ios::out);  //������ķ�ʽ���ļ� --д�ļ�

	for (int i = 0; i < this->m_EmpNum; i++) {
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}

	ofs.close();
}

//��ȡ��¼ְ������
int WorkManager::get_EmpNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId) {
		//ͳ������
		num++;
	}
	ifs.close();

	return num;
}

//��ʼ��Ա��
void WorkManager::inti_Emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		Worker * worker = NULL;
		//���ݲ�ͬ�Ĳ���Id������ͬ����
		if (dId == 1) { // ��ͨԱ��
			worker = new Employee(id, name, dId);
		}else if (dId == 2) { //����
			worker = new Manager(id, name, dId);
		}
		else{ //�ܲ�
			worker = new Boss(id, name, dId);
		}
		//�����������
		this->m_EmpArray[index] = worker;
		index++;
	}

	ifs.close();
}

//��ʾְ��
void WorkManager::Show_Emp() {
	if (this->m_FileIsEmpyty) {
		cout << "�ļ������ڣ�" << endl;
	}else {

		for (int i = 0; i < this->m_EmpNum; i++) {
			//���ö�̬���ýӿ�
			this->m_EmpArray[i]->showInfo();
			cout << endl;
		}
	}
	if (this->m_EmpNum == 0) {
		cout << "�ļ�Ϊ��!" << endl;
	}

	system("Pause");
	system("cls");
}

//ɾ��ְ��
void WorkManager::Del_Emp() {
	if (this->m_FileIsEmpyty) {
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}else {
		//����ְ�����ɾ��ְ��
		cout << "��������Ҫɾ��ְ���ı��:" << endl;
		int id = 0;
		cin >> id;
		
		int index = this->IsExist(id);

		if (index != -1) {//ְ�����ڲ���Ҫɾ����indexλ���ϵ�ְ��
			for (int i = index; i < this->m_EmpNum - i; i++) {
				//����ǰ��
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;//���������м�¼��Ա����
			//����ͬ�����µ��ļ���
			this->save();
			 
			cout << "ɾ���ɹ���" << endl;
		}
		else {
			cout << "ɾ��ʧ�ܣ� Ϊ�ҵ���ְ��!" << endl;
		}
	}

	//�����������
	system("pause");
	system("cls");
}

//�޸�ְ��
void WorkManager::Mod_Emp() {
	if (this->m_FileIsEmpyty) {
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else {
		cout << "�������޸�ְ���ı��:" << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1) {
			//���ҵ����ְ��
			delete this->m_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int dselect = 0;

			cout << "�鵽" << id << "��ְ���� ��������ְ����:" << endl;
			cout << "����:";
			cin >> newId;

			cout << "�������µ�����:" << endl;
			cout << "����:";
			cin >> newName;

			cout << "�������λ:" << endl;
			cout << "1.��ְͨ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
			cout << "����:";
			cin >> dselect;

			Worker* worker = NULL;
			switch (dselect) {
			case 1:
				worker = new Employee(newId, newName, dselect);
				break;
			case 2:
				worker = new Manager(newId, newName, dselect);
				break;
			case 3:
				worker = new Boss(newId, newName, dselect);
				break;
			default:
				break;
			}

			//�������� ��������
			this->m_EmpArray[ret] = worker;

			cout << "�޸ĳɹ���" << this->m_EmpArray[ret]->m_DeptId << endl;

			//���浽�ļ���
			this->save();
		}
		else {
			cout << "�޸�ʧ�ܣ� ���޴���" << endl;
		}
	}
	system("pause");
	system("cls");
}

//����ְ������ж�ְ���Ƿ���ڣ� �����ڷ���ְ����������λ�ã� �����ڷ���-1
int WorkManager::IsExist(int id){
	int index = -1;

	for (int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArray[i]->m_Id == id) {
			//�ҵ�ְ��
			index = i;

			break;
		}
	}

	return index;
}

//����ְ��
void WorkManager::Find_Emp() {
	if (this->m_FileIsEmpyty) {
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else {
		cout << "��ѡ����ҵķ�ʽ:" << endl;
		cout << "1.����ְ����Ų���" << endl;
		cout << "2.����������" << endl;

		string select = "";
		cin >> select;

		if (select == "1") { //����ְ���Ų���
			int id;
			cout << "��������ҵ�ְ�����:" << endl;
			cout << "����:";
			cin >> id;

			int ret = this->IsExist(id);
			if (ret != -1) {
				cout << "���ҳɹ��� ְ�����Ϊ��" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else {
				cout << "����ʧ�ܣ� ���޴��ˣ�" << endl;
			}
		}
		else if (select == "2") { //������������
			string name;
			cout << "���������ְ��������:" << endl;
			cout << "����:";
			cin >> name;

			bool flag = false;//���ҵ��ı�־
			for (int i = 0; i < m_EmpNum; i++) {
				if (m_EmpArray[i]->m_Name == name) {
					cout << endl;
					cout << "���ҳɹ��� ְ�����Ϊ:"
						<< m_EmpArray[i]->m_Id
						<< "��ְ����Ϣ����:" << endl;

					flag = true;
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false) {
				//���޴���
				cout << "����ʧ�ܣ� ���޴���!" << endl;
			}
		}
		else {
			cout << "����ѡ������" << endl;
		}
	}
	
	system("pause");
	system("cls");
}

//����ְ��
void WorkManager::Sort_Emp() {

	if (this->m_FileIsEmpyty) {

		cout << "�ļ������ڻ��¼Ϊ��!" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "��ѡ������ʽ:" << endl;
		cout << "1.��ְ��������" << endl;
		cout << "2.��ְ���Ž���" << endl;

		string select = "";
		cin >> select;

		for (int i = 0; i < m_EmpNum; i++) {

			int minOrMax = i;//������Сֵ �� ���ֵ�±�
			for (int j = i + 1; j < m_EmpNum; j++) {

				if (select == "1") { //����

					if (m_EmpArray[minOrMax]->m_Id > m_EmpArray[j]->m_Id) {

						minOrMax = j;
					}
				}
				if (select == "2") {//����

					if (m_EmpArray[minOrMax]->m_Id < m_EmpArray[j]->m_Id) {
						minOrMax = j;
					}
				}
			}

			if (i != minOrMax) {
				Worker* temp = m_EmpArray[i];
				m_EmpArray[i] = m_EmpArray[minOrMax];
				m_EmpArray[minOrMax] = temp;
			}
		}

		//��ӡ
		if (select == "1" || select == "2") {
			cout << "����ɹ��� �����Ľ��Ϊ:" << endl;
			this->save();
			this->Show_Emp();
		}
		else {
			cout << "��������!" << endl;
			system("pause");
			system("cls");
		}
	}
}

//����ļ�
void WorkManager::Clean_File() {

	cout << "ȷ����գ�" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;

	string select = "0";
	cin >> select;

	if (select == "1") {
		//��ģʽ ios::trunc �������ɾ���ļ������´���
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < m_EmpNum; i++) {
				if (this->m_EmpArray[i] != NULL) {
					delete this->m_EmpArray[i];
				}
			}
			this->m_EmpNum = 0;
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpyty = true;
		}
		cout << "����ɹ���" << endl;
	}
	if (select != "1" && select != "2") {
		cout << "��������" << endl;
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