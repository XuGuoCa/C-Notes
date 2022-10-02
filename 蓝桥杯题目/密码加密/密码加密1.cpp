# include <iostream>
# include <set>
# include <string>
using namespace std;

void Letter(set<string>& s);
int main() {

	set<string>s;
	Letter(s);
	string m_Name, tempName, Name = "";

	cin >> m_Name;

	for (int i = 0; i < m_Name.size(); i++) {

		string name;
		name = m_Name[i];

		set<string>::iterator  key = s.find(name);

		for (int j = 0; j < 4; j++) {

			*key++;
		}

		Name += *key;
	}
	cout << Name << endl;

	system("pause");

	return 0;
}

void Letter(set<string>& s) {

	string temp;
	int dir = 0, num = 0;


	for (int i = 0; i < 51; i++) {

		if (dir == 0) {

			temp = 65 + num;
			s.insert(temp);
			num++;

			if (num == 25) {

				dir = 1;
				num = 0;
			}
		}
		else {

			temp = 97 + num;
			s.insert(temp);
			num++;
		}
	}
}