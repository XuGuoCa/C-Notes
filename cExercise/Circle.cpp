# include <iostream>
using namespace std;

class Spot {

private:
	int X;
	int Y;
public:
	//设置点X
	void setX(int x) {
		X = x;
	}
	
	//提取点X
	int getY(void) {
		return X;
	}
	//设置点Y
	void setX(int y) {
		Y = y;
	}

	//提取点y
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