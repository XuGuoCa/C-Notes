# include "communication.h"


//记录文件人数
int Communication::getPerNum() {
	ifstream ifs(FILENAME, ios::in);

	string name;
	string number;
	string address;

	int num = 0;
	//while (ifs >> name, ifs >> number, ifs >> address) {
	//	//统计人数
	//	num++;
	//}

	while (ifs >> (name, number, address)) {

		num++;
	}

	//测试代码
	cout << num << "个人" << endl;
	ifs.close();

	return num;
}

//将数据存入数组中
void Communication::initPer() {

	ifstream ifs(FILENAME, ios::in);

	string name;
	string number;
	string address;
	
	int index = 0;
	while (ifs >> name, ifs >> number >> address) {
		
		Person* person = NULL;
		cout << "存入数组!" << endl;
		person = new Person(name, number, address);

		//存放到数组中
		this->m_PerArray[index] = person;
		index++;
	}
	
	this->m_FinePer = false;
	ifs.close();
}

//将数据存入文件
void Communication::save() {
	ofstream ofs(FILENAME, ios::out);

	for (int i = 0; i < this->m_PerNum; i++) {

		ofs << this->m_PerArray[i]->m_Name << " "
		    << this->m_PerArray[i]->m_Number << " "
		    << this->m_PerArray[i]->m_Address << endl;
	}
	ofs.close();
}

//构造函数
Communication::Communication(){

	//文件不存在 或 文件已存在， 但文件记录为空
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

	//文件已存在， 也有数据
	//获取人数
	int num = this->getPerNum();
	this->m_PerNum = num;

	this->m_PerArray = new Person*[this->m_PerNum];

	//把文件数据存入数组中
	this->initPer();
}

//菜单界面
void Communication::ComMenu() {

	cout << "**************************************************" << endl;
	cout << "**************** 欢迎使用通讯录！**************" << endl;
	cout << "***************** 0.退出通讯录 ******************" << endl;
	cout << "***************** 1.增加联系人 ******************" << endl;
	cout << "***************** 2.显示联系人 ******************" << endl;
	cout << "***************** 3.查找联系人 ******************" << endl;
	cout << "***************** 4.删除联系人 ******************" << endl;
	cout << "***************** 5.修改联系人 ******************" << endl;
	cout << "***************** 6.清空联系人 ******************" << endl;
	cout << "**************************************************" << endl;
}

//添加联系人
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
	cout << "请输入联系人姓名:" << endl;
	cout << "输入:";
	cin >> name;

	cout << "请输入联系人电话号码:" << endl;
	cout << "输入:";
	cin >> number;

	cout << "请输入联系人地址:" << endl;
	cout << "输入:";
	cin >> address;

	Person* person = NULL;
	person = new Person(name, number, address);

	newSpace[this->m_PerNum] = person;

	delete[] this->m_PerArray;
	this->m_PerArray = newSpace;
	this->m_PerNum = newSize;

	this->m_FinePer = false;
	cout << "添加成功!" << endl;
	//把数据存入文件
	this->save();

	system("pause");
	system("cls");
}

//显示联系人
void Communication::ShowPer() {
	if (this->m_FinePer) {

		cout << "文件不存在！" << endl;
	}
	else {
	
		for (int i = 0; i < this->m_PerNum; i++) {

			this->m_PerArray[i]->ShowPer();
			cout << endl;
		}
	}
	if (this->m_PerNum == 0) {
		cout << "通讯录无联系人！" << endl;
	}
	system("pause");
	system("cls");
}

//析构函数
Communication::~Communication() {

	if (this->m_PerArray != NULL) {

		delete[] this->m_PerArray;
		this->m_PerArray = NULL;
	}
}