# include <iostream>
# include <string>
using namespace std;

int main() {

	string Name, newName = "";

	cin >> Name;

	for (int i = 0; i < Name.size(); i++) {

		newName += Name[i] + 4;
	}

	cout << newName << endl;

	system("pause");

	return 0;
}