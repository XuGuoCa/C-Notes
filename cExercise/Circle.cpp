# include <iostream>
using namespace std;

//��
class Spot {

private:
	int X;
	int Y;

public:
	//X
	void  setX(int x) {

		X = x;
	  }
	int gitX() {
		return X;
	}

	//Y
	void setY(int y) {

		Y = y;
	}
	int gitY() {

		return Y;
	}
};

//Բ
class Circle {

private:
	int R;
	Spot H;

public:
	void setR(int r) {

		R = r;
	}
	int gitR() {

		return R;
	}
	void setHeat(Spot h) {

		H = h;
	}

	Spot gitHeat() {

		return H;
	}
};

//�жϵ��Բ�Ĺ�ϵ
void Judgement(Circle C, Spot P) {

	int i =
		(C.gitHeat().gitX() - P.gitX()) * (C.gitHeat().gitX() - P.gitX()) +
		(C.gitHeat().gitY() - P.gitY()) * (C.gitHeat().gitY() - P.gitY());

	int r = C.gitR() * C.gitR();

	if (i = r) {
		cout << "����Բ��" << endl;
	}
	else if (i < r) {

		cout << "����Բ��" << endl;
	}
	else {
		cout << "����Բ��" << endl;
	}
}

int main() {

	Circle C;
	Spot p;
	int a, b, r, x, y;

	cout << "������Բ��ֵ��" << endl;
	cout << "�뾶��";
	cin >> r;
	cout << "Բ��a:";
	cin >> a;
	cout << "Բ��b:";
	cin >> b;

	C.setR(r);
	p.setX(a);
	p.setY(b);
	C.setHeat(p);

	cout << "��������ֵ:" << endl;

		cout << "��X:";
	    cin >> x;
	    cout << "��Y:";
	    cin >> y;

		Spot P;
		P.setX(x);
		P.setY(y);

		Judgement(C, P);

	system("pause");

	return 0;
}