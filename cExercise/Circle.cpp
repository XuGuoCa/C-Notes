# include <iostream>
using namespace std;

class Spot {

private:
	int X;
	int Y;
public:
	//���õ�X
	void setX(int x) {
		X = x;
	}
	
	//��ȡ��X
	int getY(void) {
		return X;
	}
	//���õ�Y
	void setX(int y) {
		Y = y;
	}

	//��ȡ��y
	int getY(void) {
		return Y;
	}
};
class Circle {

private:
	int R;
	Spot Heat;
};

int main() {

	system("pause");

	return 0;
}