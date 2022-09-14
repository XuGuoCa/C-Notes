# include "speechManager.h"

//构造函数
SpeechManager::SpeechManager() {

	//初始化属性
	this->initSpeech();

	//创建选手
	this->createSpeaker();
}

//析构函数
SpeechManager::~SpeechManager() {


}

//菜单功能
void SpeechManager::show_Menu() {

	cout << "****************************************************************" << endl;
	cout << "*************************欢迎参加演讲比赛***********************" << endl;
	cout << "*************************1. 开始演讲比赛***********************" << endl;
	cout << "*************************2. 查看往届记录************************" << endl;
	cout << "*************************3. 清空比赛记录************************" << endl;
	cout << "*************************0. 退出比赛程序************************" << endl;
	cout << "****************************************************************" << endl;
}

//退出功能
void SpeechManager::exitsYstem(){

	cout << "欢迎下次使用!" << endl;
	system("pause");
	exit(0);
}

//初始化属性
void SpeechManager::initSpeech() {

	//容器保证为空
	this->v1.clear();
	this->v2.clear();
	this->v3.clear();
	this->m_Speaker.clear();
	//初始化比赛轮数
	this->m_Index = 1;
}

//创建选手
void SpeechManager::createSpeaker() {

	string nameSpace = "ABCDEFGHIJKL";
	for (int i = 0; i < nameSpace.size(); i++) {

		string name = "选手";
		name += nameSpace[i];

		Speaker sp;
		sp.m_Name = name;

		for (int j = 0; j < 2; j++) {
			sp.m_Score[j] = 0;
		}

		//12名选手编号
		this->v1.push_back(i + 1000);

		//选手编号 以及对应选手 存放到map容器中
		this->m_Speaker.insert(make_pair(i + 1000, sp));
	}
}

//开始比赛
void SpeechManager::startSpeech() {

	//第一轮比赛
	//1. 抽签
	this->speechDraw();

	//2. 比赛
	speechContest();

	//3. 显示晋级结果

	//第二轮比赛

	//1. 抽签

	//2. 比赛

	//3. 显示最终结果

	//4. 保存分数
}

//抽签
void SpeechManager::speechDraw() {

	srand((unsigned int)time(NULL));
	cout << "第 <<" << this->m_Index << ">> 轮比赛选手正在抽签" << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << "抽签后演讲顺序如下:" << endl;
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

//比赛
void SpeechManager::speechContest() {

	cout << "--------第" << this->m_Index << "轮比赛正式开始--------" << endl;

	//准备临时容器 存放小组成绩
	multimap<double, int, greater<double>>groupScore;

	int num = 0; //记录人员个数

	vector<int>v_Src; //比赛选手容器
	if (this->m_Index == 1) {

		v_Src = v1;
	}
	else {

		v_Src = v2;
	}

	//遍历所有选手进行比赛
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++) {

		num++;

		//评委打分
		deque<double>d;
		for (int i = 0; i < 10; i++) {

			double score = (rand() % 401 + 600) / 10.f; //600 ~ 1000
			d.push_back(score);
		}

		sort(d.begin(), d.end(), greater<double>()); //排序

		d.pop_front(); //去除最高分
		d.pop_back();  //去除最低分

		double sum = accumulate(d.begin(), d.end(), 0.0f); //总分
		double avg = sum / (double)d.size(); //平均分

		//将平均分放到 map容器里面
		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;

		//将打分数据 放入到临时小组容器中
		groupScore.insert(make_pair(avg, *it));  //key是得分， value是具体选手编号

		//每6人取前三名
		if (num % 6 == 0) {

			cout << "第" << num / 6 << "小组比赛名次:" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++) {

				cout << "编号:" << it->second << " 姓名:" << this->m_Speaker[it->second].m_Name << " 年龄:" << this->m_Speaker[it->second].m_Score << endl;
			}

			//取走前三名 
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