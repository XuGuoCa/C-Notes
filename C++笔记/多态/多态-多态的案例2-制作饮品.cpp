# include <iostream>
using namespace std;

class MakeDrinking {
public:
	void Boilwater() {   //��ˮ

		cout << "��ˮ" << endl;
	}
	virtual void Brewing() = 0;  //����

	void PourIn() {  //���뱭��

		cout << "���뱭��" << endl;
	}

	virtual void Seasonings() = 0;    //�Ӹ���
};

class Coffee : public MakeDrinking {

public:

	void Brewing() {
		
		cout << "���ݿ���" << endl;
	}

	void Seasonings() {

		cout << "���Ǻ�ţ��" << endl;
	}
};

class Tea : public MakeDrinking {

public:
	void Brewing() {

		cout << "���ݲ�Ҷ" << endl;
	}

	void Seasonings() {

		cout << "������" << endl;
	}
};

void Drinking(MakeDrinking * makedrinking) {

	makedrinking->Boilwater();
	makedrinking->Brewing();
	makedrinking->PourIn();
	makedrinking->Seasonings();
}

void test() {

	Drinking(new Tea);

	cout << "___________________" << endl;

	Drinking(new Coffee);

}

int main() {

	test();

	system("pause");

	return 0;
}