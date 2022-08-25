# include "workmanager.h"


//构造函数
WorkManager::WorkManager() {

	ifstream ifs(FILENAME, ios::in);
	//文件不存在 和 文件已存在，但没有记录
	char ch;
	ifs >> ch;
	if (!ifs.is_open() || ifs.eof()) {

		//初始化
		//初始化人数
		this->m_EmpNum = 0;
		//初始化数组指针
		this->m_EmpArray = NULL;

		//初始化文件为空
		this->m_FileIsEmpyty = true;

		ifs.close();
		return;
	}
	//文件已存在， 也有记录
	int num = this->get_EmpNum();
	this->m_EmpNum = num;
	//开辟新空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//文件记录到数组中
	this->inti_Emp();
}

//记录文件人数
int WorkManager::get_EmpNum() {
	ifstream ifs(FILENAME, ios::in);
	int num = 0; //人数
	int id;
	string name;
	int dId;

	while (ifs >> id, ifs >> name, ifs >> dId) {
		//统计人数
		num++;
	}
	ifs.close();
	return num;
}

//初始化员工
void WorkManager::inti_Emp() {
	ifstream ifs(FILENAME, ios::in);
	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {

		Worker* worker = NULL;
		if (dId == 1) {
			worker =new Employee(id, name, dId);
		}
		else if (dId == 2) {
			worker = new Manager(id, name, dId);
		}
		else {
			worker = new Boss(id, name, dId);
		}
		
		//存放到数组中
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}

//按照职工编号判断职工是否存在， 若存在返回职工在数组中位置， 不存在返回-1
int WorkManager::IsExist(int id) {
	for (int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArray[i]->m_Id == id) {
			return i;
		}
	}
	return -1;
}

//储存文件
void WorkManager::save() {

	ofstream ofs(FILENAME, ios::out);

	for (int i = 0; i < this->m_EmpNum; i++) {
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}

	ofs.close();
}

//展示菜单
void WorkManager::Show_Menu() {
	cout << "**************************************************" << endl;
	cout << "**************欢迎使用职工管理系统！**************" << endl;
	cout << "**************** 0.退出管理系统 ******************" << endl;
	cout << "**************** 1.增加职工信息 ******************" << endl;
	cout << "**************** 2.显示职工信息 ******************" << endl;
	cout << "**************** 3.删除离职职工 ******************" << endl;
	cout << "**************** 4.修改职工信息 ******************" << endl;
	cout << "**************** 5.查找职工信息 ******************" << endl;
	cout << "**************** 6.按照编号排序 ******************" << endl;
	cout << "**************** 7.清空所有文档 ******************" << endl;
	cout << "**************************************************" << endl;
}

//退出系统
void WorkManager::ExitSystem() {
	cout << "欢迎再次使用！" << endl;
	system("pause");
	system("cls");
	exit(0);
}

//添加职工函数
void WorkManager::Add_Emp() {

	//添加职工数量
	int addNum = 0;
	cout << "请输入添加职工的数量:" << endl;
	cin >> addNum;

	if (addNum > 0) {

		int newSize = this->m_EmpNum + addNum;
		Worker** newSpace = new Worker * [newSize];

		//更新职工数据
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		int id;
		string name;
		int dId;
		Worker* worker = NULL;

		//判断编号是否重复
		int num[100];
		int index = 0;
		bool flag = true;

		//开始输入
		for (int i = 0; i < addNum; i++) {

			while (true) {
				cout << "请输入第" << i + 1 << "个职工的编号:" << endl;
				cout << "输入:";
				cin >> id;
				int ret = this->IsExist(id);
				for (int j = 0; j < 100; j++) {
					if (num[j] == id) {
						flag = false;
						break;
					}
				}
				if (ret == -1 && flag) {
					break;
				}
				else {
					cout << "输入编号重复请重新输入！" << endl;
					flag = true;
				}
			}
			num[index] = id;
			index++;

			cout << "请输入第" << i + 1 << "个职工的姓名:" << endl;
			cin >> name;

			cout << "请选择职工的职位:" << endl;
			cout << "1.员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;

			int select;
			cin >> select;
			if (select == 1) {
				worker = new Employee(id, name, 1);
			}
			else if (select == 2) {
				worker = new Manager(id, name, 2);
			}
			else {
				worker = new Boss(id, name, 3);
			}
			newSpace[this->m_EmpNum + i] = worker;
		}

		//释放空间
		delete[] this->m_EmpArray;

		//数组重新指向
		this->m_EmpArray = newSpace;

		//更新职工数量
		this->m_EmpNum = newSize;

		this->m_FileIsEmpyty = false;

		//添加成功提示
		cout << "添加成功" << addNum << "名职工!" << endl;

		//把数据存入文件中
		this->save();

		system("pause");
		system("cls");
	}
	else {
		cout << "输入有误!" << endl;
		system("pause");
		system("cls");
	}
}

//显示职工
void WorkManager::Show_Emp() {

	if (this->m_FileIsEmpyty) {
		cout << "文件不存在" << endl;
	}
	else {
		for (int i = 0; i < this->m_EmpNum; i++) {

			this->m_EmpArray[i]->ShowInfo();
			cout << endl;
		}
	}
	if (this->m_EmpNum == 0) {
		cout << "文件为空！" << endl;
	}

	system("pause");
	system("cls");
}

//删除职工
void WorkManager::Del_Emp() {

	if (this->m_FileIsEmpyty) {
		cout << "文件不存在或文件为空!" << endl;
	}
	else {
		cout << "请输入离职职工的职工编号:" << endl;
		int id;
		cout << "输入:";
		cin >> id;
		if (this->IsExist(id) != -1) {

			int index = this->IsExist(id);
			for (int i = index; i < this->m_EmpNum - i; i++) {

				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			this->save();
			cout << "删除成功！" << endl;
			system("Pause");
			system("cls");
		}
		else {
			cout << "查无此人！" << endl;
		}
	}
	system("pause");
	system("cls");
}

//修改职工
void WorkManager::Mod_Emp() {
	if (this->m_FileIsEmpyty) {
		cout << "文件不存在或文件为空!" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "请输入职工编号:" << endl;
		int id;
		cout << "输入:" << endl;
		cin >> id;

		if (this->IsExist(id) != -1) {
			
			int index = this->IsExist(id);
			delete this->m_EmpArray[index];

			int newId;
			string newName;
			int dselect;

			cout << "查找" << id << "号职工, 请输入新职工号:" << endl;
			//防止输入编号重复
			while (true) {
				cout << "输入:";
				cin >> newId;
				if (this->IsExist(newId) == -1) {
					break;
				}
				else {
					cout << "输入职工号重复!" << endl;
				}
			}

			cout << "请输入新的姓名:" << endl;
			cout << "输入:";
			cin >> newName;

			cout << "请选择新的岗位:" << endl;
			cout << "1.员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cout << "输入:";
			cin >> dselect;

			Worker* worker = NULL;
			if (dselect == 1) {
				worker = new Employee(newId, newName, dselect);
			}
			else if (dselect == 2) {
				worker = new Manager(newId, newName, dselect);
			}
			else {
				worker = new Boss(newId, newName, dselect);
			}

			//将数据保存在数组中
			this->m_EmpArray[index] = worker;
			this->save();
			cout << "修改成功！" << endl;
			system("pause");
			system("cls");
		}
		else {
			cout << "查无此人！" << endl;
			system("pause");
			system("cls");
		}
	}
}

//查找职工
void WorkManager::Find_Emp() {

	if (this->m_FileIsEmpyty) {
		cout << "文件不存在或文件为空!" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "请输入查找方法:" << endl;
		cout << "1.按照编号查找" << endl;
		cout << "2.按照姓名查找" << endl;
		string select;
		cout << "输入:";
		cin >> select;

		if (select == "1") {
			cout << "请输入编号:" << endl;
			int id;
			cout << "输入:";
			cin >> id;
			int ret = this->IsExist(id);

			//判断是否找到
			if (ret == -1) {
				cout << "查无此人!" << endl;
			}
			else {
				this->m_EmpArray[ret]->ShowInfo();
			}
	  }
		else if (select == "2") {
			cout << "请输入姓名:" << endl;
			string name;
			cin >> name;
			bool flag = false;
			int index;

			//判断是否存在
			for (int i = 0; i < this->m_EmpNum; i++) {
				if (this->m_EmpArray[i]->m_Name == name) {
					flag = true;
					index = i;
				}
			}
			if (flag) {
				this->m_EmpArray[index]->ShowInfo();
			}
			else {
				cout << "查无此人!" << endl;
			}
		}
		else {
			cout << "输入有误！" << endl;
		}
		system("pause");
		system("cls");
   }
}

//排序职工
void WorkManager::Sort_Emp() {
	if (this->m_FileIsEmpyty) {
		cout << "文件不存在或为空!" << endl;
	}
	else {
		cout << "选择排序方式:" << endl;
		cout << "1.升序排序" << endl;
		cout << "2.降序排序" << endl;
		string select;
		cout << "输入:";
		cin >> select;

		int mainOrMax;
		for (int i = 0; i < this->m_EmpNum; i++) {

			mainOrMax = i;
			for (int j = i + 1; j < this->m_EmpNum; j++) {

				if (select == "1") {
					if (this->m_EmpArray[mainOrMax]->m_Id > this->m_EmpArray[j]->m_Id) {// 升序
						mainOrMax = j;
					}
				}
				if (select == "2") {
					if (this->m_EmpArray[mainOrMax]->m_Id < this->m_EmpArray[j]->m_Id) {// 降序
						mainOrMax = j;
					}
				}

				if (mainOrMax != i) {
					Worker* temp = this->m_EmpArray[mainOrMax];
					this->m_EmpArray[mainOrMax] = this->m_EmpArray[i];
					this->m_EmpArray[i] = temp;
				}
			}
		}
		if (select != "1" && select != "2") {
			cout << "输入有误!" << endl;
			system("pause");
			system("cls");
			return;
		}
		cout << "排序后显示如下:" << endl;
		for (int i = 0; i < this->m_EmpNum; i++) {
			this->m_EmpArray[i]->ShowInfo();
			cout << endl;
			this->save();
		}
	}
	system("pause");
	system("cls");
}

//清空文件
void WorkManager::Clean_File() {

	cout << "确认清空？" << endl;
	cout << "1.确定" << endl;
	cout << "2.返回" << endl;
	string select;
	cout << "输入:";
	cin >> select;

	if (select == "1") {

		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL) {

			for (int i = 0; i < this->m_EmpNum; i++) {
				if (this->m_EmpArray[i] != NULL) {
					delete this->m_EmpArray[i];
				}
			}
			this->m_EmpNum = 0;
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpyty = true;
			cout << "清除成功!" << endl;
		}
	}
	system("pause");
	system("cls");
}

//析构函数
WorkManager::~WorkManager() {
	if (this->m_EmpArray != NULL) {

		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}
