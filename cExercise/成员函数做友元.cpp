# include <iostream>
using namespace std;
# include <string> 

class Buliding;//���ǰ������

class goodGay {

public:
	goodGay();

	void visit();

	Buliding *buliding;

};

class Buliding {


	friend void goodGay::visit(); //��Ա��������Ԫ

public:
	Buliding();

	string m_SittingRoom;

private:
	string m_RedRoom;
};

Buliding::Buliding() {

	m_SittingRoom = "����";
	m_RedRoom = "����";
}

goodGay::goodGay() {

	buliding = new Buliding;
}

void goodGay::visit() {

	cout << "�û��������ڷ��ʣ�" << buliding->m_SittingRoom << endl;

	cout << "�û��������ڷ��ʣ�" << buliding->m_RedRoom << endl;

}

void test01() {

	goodGay gg;

	gg.visit();
}


int main() {

	test01();

	system("pause");

	return 0;
}