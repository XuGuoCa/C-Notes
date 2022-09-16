# include "speechManager.h"

//���캯��
SpeechManager::SpeechManager() {

	//��ʼ������
	this->initSpeech();

	//����ѡ��
	this->createSpeaker();

	//��ȡ�����¼
	this->loadRecord();
}

//��������
SpeechManager::~SpeechManager() {


}

//�˵�����
void SpeechManager::show_Menu() {

	cout << "****************************************************************" << endl;
	cout << "*************************��ӭ�μ��ݽ�����***********************" << endl;
	cout << "*************************1. ��ʼ�ݽ�����***********************" << endl;
	cout << "*************************2. �鿴�����¼************************" << endl;
	cout << "*************************3. ��ձ�����¼************************" << endl;
	cout << "*************************0. �˳���������************************" << endl;
	cout << "****************************************************************" << endl;
}

//�˳�����
void SpeechManager::exitsYstem(){

	cout << "��ӭ�´�ʹ��!" << endl;

	system("pause");
	exit(0);
}

//��ʼ������
void SpeechManager::initSpeech() {

	//������֤Ϊ��
	this->v1.clear();
	this->v2.clear();
	this->v3.clear();
	this->m_Speaker.clear();
	//��ʼ����������
	this->m_Index = 1;

	 //����¼������ Ҳ���
	this->m_Record.clear();
}

//����ѡ��
void SpeechManager::createSpeaker() {

	string nameSpace = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSpace.size(); i++) {

		string name = "ѡ��";
		name += nameSpace[i];

		Speaker sp;
		sp.m_Name = name;

		for (int j = 0; j < 2; j++) {
			sp.m_Score[j] = 0;
		}

		//12��ѡ�ֱ��
		this->v1.push_back(i + 1000);

		//ѡ�ֱ�� �Լ���Ӧѡ�� ��ŵ�map������
		this->m_Speaker.insert(make_pair(i + 1000, sp));
	}
}

//��ʼ����
void SpeechManager::startSpeech() {

	//��һ�ֱ���
	//1. ��ǩ
	this->speechDraw();

	//2. ����
	speechContest();

	//3. ��ʾ�������
	showScore();

	//�ڶ��ֱ���
	this->m_Index++;

	//1. ��ǩ
	this->speechDraw();

	//2. ����
	speechContest();

	//3. ��ʾ���ս��
	showScore();

	//4. �������
	saverScore();

	cout << "���������ϣ�" << endl;
	system("pause");
	system("cls");
	//��ʼ������������
	this->initSpeech();

	//����ѡ��
	this->createSpeaker();

	//���������¼
	this->loadRecord();
}

//��ǩ
void SpeechManager::speechDraw() {

	srand((unsigned int)time(NULL));
	cout << "�� <<" << this->m_Index << ">> �ֱ���ѡ�����ڳ�ǩ" << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << "��ǩ���ݽ�˳������:" << endl;
	if (this->m_Index == 1) {
		random_shuffle(v1.begin(), v1.end());
		for (vector<int>::iterator it = this->v1.begin(); it != this->v1.end(); it++) {

			cout << *it << " ";
		}
		cout << endl;
	}
	else {
		random_shuffle(v2.begin(), v2.end());
		for (vector<int>::iterator it = this->v2.begin(); it != this->v2.end(); it++) {

			cout << *it << " ";
		}
		cout << endl;
	}
	cout << "-------------------------------------------------------" << endl;
	system("pause");
}

//����
void SpeechManager::speechContest() {

	cout << "--------��" << this->m_Index << "�ֱ�����ʽ��ʼ--------" << endl;

	//׼����ʱ���� ���С��ɼ�
	multimap<double, int, greater<double>>groupScore;

	int num = 0; //��¼��Ա����

	vector<int>v_Src; //����ѡ������
	if (this->m_Index == 1) {

		v_Src = v1;
	}
	else {

		v_Src = v2;
	}

	//��������ѡ�ֽ��б���
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++) {

		num++;

		//��ί���
		deque<double>d;
		for (int i = 0; i < 10; i++) {

			double score = (rand() % 401 + 600) / 10.f; //600 ~ 1000
			d.push_back(score);
		}

		sort(d.begin(), d.end(), greater<double>()); //����

		d.pop_front(); //ȥ����߷�
		d.pop_back();  //ȥ����ͷ�

		double sum = accumulate(d.begin(), d.end(), 0.0f); //�ܷ�
		double avg = sum / (double)d.size(); //ƽ����

		//��ƽ���ַŵ� map��������
		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;

		//��������� ���뵽��ʱС��������
		groupScore.insert(make_pair(avg, *it));  //key�ǵ÷֣� value�Ǿ���ѡ�ֱ��

		//ÿ6��ȡǰ����
		if (num % 6 == 0) {

			cout << "��" << num / 6 << "С���������:" << endl;
			for (multimap<double, int, greater<double>>::iterator pos1 = groupScore.begin(); pos1 != groupScore.end(); pos1++) {

				cout << "���:" << pos1->second << " ����:" << this->m_Speaker[pos1->second].m_Name << " ����:" << this->m_Speaker[pos1->second].m_Score[this->m_Index - 1] << endl;
			}

			//ȡ��ǰ���� 
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator pos2 = groupScore.begin(); pos2 != groupScore.end() && count < 3; pos2++, count++) {

				if (this->m_Index == 1) {
					v2.push_back((*pos2).second);
				}
				else {
					v3.push_back((*pos2).second);
				}
			}

			groupScore.clear(); //С���������
			cout << endl;
		}
	}

	cout << "--------��" << this->m_Index << "�ֱ������--------" << endl;
	system("pause");
}

//��ʾ����ѡ����Ϣ
void SpeechManager::showScore() {

	cout << "--------��" << this->m_Index << "�ֽ���ѡ����Ϣ���£�--------" << endl;
	vector<int>v;
	if (this->m_Index == 1) {

		v = v2;
	}
	else {
		v = v3;
	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {

		cout << "ѡ�ֱ�ţ�" << *it << "  ������" << this->m_Speaker[*it].m_Name << "  �÷֣�" << this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");
	cout << endl;
}

//�������
void SpeechManager::saverScore() {

	ofstream ofs(FILENAME, ios::out | ios::app);  //������ķ�ʽ���ļ� -- д�ļ�

	//��ÿ������д�뵽�ļ���
	for (vector<int>::iterator it = v3.begin(); it != v3.end(); it++) {

		ofs << *it << ',' << this->m_Speaker[*it].m_Score[1] << ',';
	}
	ofs << endl;

	//�ر��ļ�
	ofs.close();

	cout << "��¼�Ѿ�����" << endl;
	this->fileIsEmpty = false;
	cout << endl;
	system("pause");
	system("cls");
}

//��ȡ��¼����
void SpeechManager::loadRecord() {

	ifstream ifs(FILENAME, ios::in);

	{
		if (!ifs.is_open()) {

			this->fileIsEmpty = true;
			ifs.close();
			return;
		}
		
		//�ļ�������
		char ch;
		ifs >> ch;
		if (ifs.eof()) {

			this->fileIsEmpty = true;
			ifs.close();
			return;
		}

		//�ļ���Ϊ��
		this->fileIsEmpty = false;

		ifs.putback(ch);

		string data;
		int index = 0;  //��ʾ�ڼ���

		while (ifs >> data) {


			vector<string>v;  //���6��string�ַ���

			int pos = -1; //�鵽","λ�õı���
			int start = 0;

			while (true) {
				pos = data.find(',', start);  //�ҵ�"��"��λ��

				if (pos == -1) {
					//û���ҵ����
					break;
				}
				string temp = data.substr(start, pos - start);

				v.push_back(temp);

				start = pos + 1;
			}

			this->m_Record.insert(make_pair(index, v));
			index++;
		}
	}
	ifs.close();
}

//�鿴�����¼
void SpeechManager::showRecord() {

	loadRecord();

	if (this->fileIsEmpty) {
		cout << "�����޼�¼!" << endl;
	}
	else{

	for (int i = 0; i < this->m_Record.size(); i++) {

		cout << "��" << i + 1 << "��" <<
			"�ھ����:" << this->m_Record[i][0] << " �÷�:" << this->m_Record[i][1] << "  "
			"�Ǿ����:" << this->m_Record[i][2] << " �÷�:" << this->m_Record[i][3] << "  "
			"�������:" << this->m_Record[i][4] << " �÷�:" << this->m_Record[i][5] << " "
			<< endl;
	}
	}
	cout << endl;

	system("pause");
	system("cls");
}

//��ռ�¼����
void SpeechManager::clearRecord() {

	cout << "ȷ����գ�" << endl;
	cout << "1. ȷ��" << endl;
	cout << "2. ����" << endl;

	int choise;
	cin >> choise;

	if (choise == 1) {

		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		this->initSpeech();

		this->createSpeaker();

		this->loadRecord();

		this->fileIsEmpty = true;

		cout << "��ճɹ�!" << endl;
		system("pause");
		system("cls");
	}
}