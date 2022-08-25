# include "communication.h"


//��¼�ļ�����
int Communication::getPerNum() {
	ifstream ifs(FILENAME, ios::in);

	string name;
	string number;
	string address;

	int num = 0;
	//while (ifs >> name, ifs >> number, ifs >> address) {
	//	//ͳ������
	//	num++;
	//}

	while (ifs >> (name, number, address)) {

		num++;
	}

	//���Դ���
	cout << num << "����" << endl;
	ifs.close();

	return num;
}

//�����ݴ���������
void Communication::initPer() {

	ifstream ifs(FILENAME, ios::in);

	string name;
	string number;
	string address;
	
	int index = 0;
	while (ifs >> name, ifs >> number >> address) {
		
		Person* person = NULL;
		cout << "��������!" << endl;
		person = new Person(name, number, address);

		//��ŵ�������
		this->m_PerArray[index] = person;
		index++;
	}
	
	this->m_FinePer = false;
	ifs.close();
}

//�����ݴ����ļ�
void Communication::save() {
	ofstream ofs(FILENAME, ios::out);

	for (int i = 0; i < this->m_PerNum; i++) {

		ofs << this->m_PerArray[i]->m_Name << " "
		    << this->m_PerArray[i]->m_Number << " "
		    << this->m_PerArray[i]->m_Address << endl;
	}
	ofs.close();
}

//���캯��
Communication::Communication(){

	//�ļ������� �� �ļ��Ѵ��ڣ� ���ļ���¼Ϊ��
	ifstream ifs(FILENAME, ios::in);
	char ch;
	ifs >> ch;

	if (!ifs.is_open() || ifs.eof()) {

		this->m_PerArray = NULL;
		this->m_PerNum = 0;
		this->m_FinePer = true;

		ifs.close();
		return;
	}

	//�ļ��Ѵ��ڣ� Ҳ������
	//��ȡ����
	int num = this->getPerNum();
	this->m_PerNum = num;

	this->m_PerArray = new Person*[this->m_PerNum];

	//���ļ����ݴ���������
	this->initPer();
}

//�˵�����
void Communication::ComMenu() {

	cout << "**************************************************" << endl;
	cout << "**************** ��ӭʹ��ͨѶ¼��**************" << endl;
	cout << "***************** 0.�˳�ͨѶ¼ ******************" << endl;
	cout << "***************** 1.������ϵ�� ******************" << endl;
	cout << "***************** 2.��ʾ��ϵ�� ******************" << endl;
	cout << "***************** 3.������ϵ�� ******************" << endl;
	cout << "***************** 4.ɾ����ϵ�� ******************" << endl;
	cout << "***************** 5.�޸���ϵ�� ******************" << endl;
	cout << "***************** 6.�����ϵ�� ******************" << endl;
	cout << "**************************************************" << endl;
}

//�����ϵ��
void Communication::addComPer() {

	int newSize = this->m_PerNum + 1;
	Person** newSpace = new Person*[newSize];

	if (this->m_PerArray != NULL) {

		for (int i = 0; i < this->m_PerNum; i++) {
			newSpace[i] = this->m_PerArray[i];
		}
	}

	string name;
	string number;
	string address;
	cout << "��������ϵ������:" << endl;
	cout << "����:";
	cin >> name;

	cout << "��������ϵ�˵绰����:" << endl;
	cout << "����:";
	cin >> number;

	cout << "��������ϵ�˵�ַ:" << endl;
	cout << "����:";
	cin >> address;

	Person* person = NULL;
	person = new Person(name, number, address);

	newSpace[this->m_PerNum] = person;

	delete[] this->m_PerArray;
	this->m_PerArray = newSpace;
	this->m_PerNum = newSize;

	this->m_FinePer = false;
	cout << "��ӳɹ�!" << endl;
	//�����ݴ����ļ�
	this->save();

	system("pause");
	system("cls");
}

//��ʾ��ϵ��
void Communication::ShowPer() {
	if (this->m_FinePer) {

		cout << "�ļ������ڣ�" << endl;
	}
	else {
	
		for (int i = 0; i < this->m_PerNum; i++) {

			this->m_PerArray[i]->ShowPer();
			cout << endl;
		}
	}
	if (this->m_PerNum == 0) {
		cout << "ͨѶ¼����ϵ�ˣ�" << endl;
	}
	system("pause");
	system("cls");
}

//��������
Communication::~Communication() {

	if (this->m_PerArray != NULL) {

		delete[] this->m_PerArray;
		this->m_PerArray = NULL;
	}
}