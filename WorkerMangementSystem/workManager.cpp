//�����ļ�
# include "workManger.h"
# include "employee.h"
# include "boss.h"
# include "manager.h"

//���캯��
WorkManager::WorkManager() {

	//1.�ļ�������
	
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open()) {
		cout << "�ļ�������" << endl;
		cout << endl;
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

			cout << "�������" << i + 1 << "����ְ����ţ�" << endl;
			cin >> id;

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
			//������ְ��ְ�� ���浽������
			newSpace[this->m_EmpNum + i] = worker;

		}

		//�ͷſռ�
		delete[] this->m_EmpArray;

		//�����¿ռ��ָ��
		this->m_EmpArray = newSpace;

		//�����µ�ְ������
		this->m_EmpNum = newSize;

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

//��������
WorkManager::~WorkManager() {
	if (this->m_EmpArray != NULL) {

		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}