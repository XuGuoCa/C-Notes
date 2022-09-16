#pragma once
# include <iostream>
# include <vector>
# include <map>
# include <algorithm>
# include <ctime>
# include <deque>
# include <functional>
# include <numeric>
# include <string>
# include <fstream>
# define FILENAME "speech.csv"
# include "speaker.h"
using namespace std;

class SpeechManager {

public:
	//���캯��
	SpeechManager();

	//��������
	~SpeechManager();

	//չʾ�˵�
	void show_Menu();

	//�˳�����
	void exitsYstem();

	//��ʼ������
	void initSpeech();

	//����ѡ��
	void createSpeaker();

	//����ѡ������  12��
	vector<int>v1;

	//��һ�ֽ�������  6��
	vector<int>v2;

	//ʤ��ǰ��������  3��
	vector<int>v3;

	//��ű�� �Լ���Ӧ�� ����ѡ�� ����
	map<int, Speaker>m_Speaker;

	//��¼��������
	int m_Index;

	//��ʼ����
	void startSpeech();

	//��ǩ
	void speechDraw();

	//����
	void speechContest();

	//��ʾ����ѡ����Ϣ
	void showScore();

	//�������
	void saverScore();

	//��ȡ��¼����
	void loadRecord();

	//�ļ�Ϊ�ձ�־
	bool fileIsEmpty;

	//��������¼������
	map<int, vector<string>>m_Record;

	//�鿴�����¼
	void showRecord();

	//��ռ�¼����
	void clearRecord();
};