//ȫ�ֺ�������Ԫ��
# include <iostream>
using namespace std;
# include <string>

class Buliding {

	friend void goodGay(Buliding& buliding);

public:
  	Buliding() {

		m_BedRoom = "����";
		m_SittingRoom = "����";
	}

public:
	string m_SittingRoom;  //����
private:
	string m_BedRoom; //����
};

	void goodGay(Buliding &buliding) {  //�û���

		cout << "�û���ȫ�ֺ��� ���ڷ��ʣ�" << buliding.m_SittingRoom << endl;

		cout << "�û���ȫ�ֺ��� ���ڷ��ʣ�" << buliding.m_BedRoom << endl;
	}

	void test01() {

		Buliding buliding;
		goodGay(buliding);
	}


int main() {

	test01();

	system("pause");

	return 0;

}