# include <iostream>
using namespace std;

int main() {

	int n;
	int a[55] = { 0, 1 , 2, 3 };
	for (int i = 4; i < 55; i++) {

		a[i] = a[i - 1] + a[i - 3];
	}
	while (cin >> n && n != 0) {

		cout << a[n] << endl;
	}

	system("pause");

	return 0;
}