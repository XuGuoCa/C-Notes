# include <iostream>
using namespace std;
# include <vector>
# include <deque>
# include <string>
# include <ctime>
# include <algorithm>

//ѡ����
class Person {

public:
	Person(string name, int score) {

		this->m_Name = name;
		this->m_Score = score;
	}

	string m_Name;  //����
	int m_Score;  //ƽ����
};

//1.��������ѡ��
void creatPerson(vector<Person>& v) {

	string nameSend = "ABCDE";
	for (int i = 0; i < 5; i++) {
		string name;
		name += nameSend[i];

		int score = 0;

		Person p(name, score);

		v.push_back(p);
	}
}

//2.������ѡ�ִ��
void setScore(vector<Person>& v) {

	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {

		deque<int>d;
		for (int j = 0; j < 10; j++) {

			d.push_back(rand() % 41 + 60);
		}

		//С��������
		sort(d.begin(), d.end());


		//ȥ����ͷֺ���߷�
		d.pop_back();
		d.pop_front();

		//ȡƽ����
		int sum = 0;
		for (deque<int>::iterator div = d.begin(); div != d.end(); div++) {

			sum += *div;
		}
		int avg = sum / d.size();
		it->m_Score = avg;
	}
}

//3.��ʾ���÷�
void showScore(vector<Person>& v) {

	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++) {

		cout << "������ ѡ��" << (*it).m_Name << " ƽ����:" << (*it).m_Score << endl;
	}
}

int main() {

	//���������
	srand((unsigned int)time(NULL));

	//1.��������ѡ��
	vector<Person>v;
	creatPerson(v);

	//2.������ѡ�ִ��
	setScore(v);

	//3.��ʾ���÷�
	showScore(v);

	system("pause");

	return 0;
}