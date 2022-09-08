# include <iostream>
using namespace std;
# include <string>
# include <vector>
# include <ctime>
# include <map>
# define CEHUA 1
# define MEISHU 2
# define YANFA 3

class Staff {

public:
	Staff(string name, int wage) {
		
		this->m_Name = name;
		this->m_Wage = wage;
	}
	string m_Name;  //����
	int m_Wage;  //����
};

//����10��Ա��
void createSta(vector<Staff>&v) {

	for (int i = 0; i < 10; i++) {
		string namesend = "ABCDEFGHIJ";
		string name;

		name += namesend[i];
		int wage = rand() % 10000 + 10000;

		Staff s(name, wage);

		v.push_back(s);
	}
}

//�������
void Digr(vector<Staff>& v, multimap<int, Staff>&m) {

	for (vector<Staff>::iterator it = v.begin(); it != v.end(); it++) {

		int key = rand() % 3 + 1;
		
		m.insert(make_pair(key, *it));
	}
}

//��ʾ
void showStaff(multimap<int, Staff>& m) {

	multimap<int, Staff>::iterator pos = m.find(CEHUA);
	int count = m.count(CEHUA);
	cout << "�߻����ţ�    "  << count  << "��" << endl;
	int index = 0;
	for (; pos != m.end() && index < count; pos++, index++) {

		cout << "������" << pos->second.m_Name << " ���ʣ�" << pos->second.m_Wage << endl;
	}

	cout << "-----------------------------------------" << endl;

    pos = m.find(MEISHU);
	count = m.count(MEISHU);
	cout << "�������ţ�   " << count  << "��" << endl;
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++) {

		cout << "������" << pos->second.m_Name << " ���ʣ�" << pos->second.m_Wage << endl;
	}

	cout << "-----------------------------------------" << endl;

	pos = m.find(YANFA);
	count = m.count(YANFA);
	cout << "�з����ţ�   " << count  << "��" << endl;
	index = 0;
	for (; pos != m.end() && index < count; pos++, index++) {

		cout << "������" << pos->second.m_Name << " ���ʣ�" << pos->second.m_Wage << endl;
	}
}

int main() {

	//����10��Ա��
	vector<Staff>v;
	createSta(v);

	srand((unsigned int)time(NULL));

	//����vector���� �������
	multimap<int, Staff>m;
	Digr(v, m);

	//��ʾ������Ϣ
	showStaff(m);

	system("pause");

	return 0;
}