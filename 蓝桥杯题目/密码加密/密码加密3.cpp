# include <iostream>
# include <string>

using namespace std;

int main()
{
	string s;
	getline(cin, s);
	for (char& a : s)
	{
		a = a + 4;
	}

	cout << s << endl;
}