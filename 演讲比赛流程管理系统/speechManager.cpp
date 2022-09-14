# include "speechManager.h"

//���캯��
SpeechManager::SpeechManager() {

	//��ʼ������
	this->initSpeech();

	//����ѡ��
	this->createSpeaker();
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

	//�ڶ��ֱ���

	//1. ��ǩ

	//2. ����

	//3. ��ʾ���ս��

	//4. �������
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
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++) {

				cout << "���:" << it->second << " ����:" << this->m_Speaker[it->second].m_Name << " ����:" << this->m_Speaker[it->second].m_Score << endl;
			}

			//ȡ��ǰ���� 
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++, count++) {

				if (this->m_Index == 1) {
					v2.push_back((*it).second);
				}
				else {
					
				}
			}

			groupScore.clear();
		}
	}
}