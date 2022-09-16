# include "manager.h"

//默认构造
Manager::Manager() {


}

//有参构造
Manager::Manager(string name, string pwd) {

	this->m_Name = name;
	this->m_Pwd = pwd;
}

//选择菜单
void Manager::operMenu() {

	cout << "欢迎管理员：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看机房            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.清空预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

//添加账号
void Manager::addPerson() {

	cout << "请输入添加账号类型" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加学生            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看教师            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";

	string fileName;
	string tip;
	ofstream ofs;

	int select;
	cout << "输入:";
	cin >> select;
	string errorTip;  //重复错误提示
	int type;

	system("cls");

	if (select == 1) {

		fileName = STUDENT_FILE;
		tip =  "请输入学号：";
		errorTip = "学号重复， 请重新输入!";
		type = 1;
	}
	else if (select == 2) {

		fileName = TEACHER_FILE;
		tip = "请输入职工编号：";
		errorTip = "职工号重复， 请重新输入！";
		type = 2;
	}
	else {

		cout << "输入错误！返回管理员菜单" << endl;
		system("pause");
		system("cls");
	}

	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	while (true) {
		cout << tip << endl;
		cin >> id;
		if (checkRepeat(id, type)) {

			break;
		}
		cout << errorTip << endl;
		system("pause");
		system("cls");
	}

	cout << "请输入姓名:" << endl;
	cin >> name;

	cout << "请输入密码:" << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功" << endl;

	system("pause");
	system("cls");

	ofs.close();
}

//查看账号
void Manager::showPerson() {


}

//查看机房信息
void Manager::showComputer() {


}

//清空预约记录
void Manager::CleanFile() {


}

//初始化容器
void Manager::initVector() {

	//读取学生文件中的信息
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open()) {

		cout << "文件读取失败" << endl;
		return;
	}

	this->vStu.clear();
	this->vTea.clear();

	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd) {

		this->vStu.push_back(s);
	}
	//cout << "当前学生数量为：" << this->vStu.size() << "人" << endl;
	ifs.close();

	//读取教师文件信息
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open()) {

		cout << "文件读取失败" << endl;
		return;
	}

	Teacher t;
	while(ifs >> t.m_EmpId && ifs >> s.m_Name && ifs >> s.m_Pwd) {

		this->vTea.push_back(t);
	}
	//cout << "当前教师数量为：" << this->vStu.size() << "人" << endl;
	ifs.close();
}

//去重函数封装
bool Manager::checkRepeat(int id, int type) {

	initVector();

	if (type == 1) {

		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++) {

			if (id == it->m_Id) {
				return false;
			}
		}
	}
	else {
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++) {

			if (id == it->m_EmpId) {
				return false;
			}
		}
	}
	return true;
}