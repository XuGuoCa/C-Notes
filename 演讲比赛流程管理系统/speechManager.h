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

	//ʤ��ǰ��������  3�ˡ�
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
};