//�̳��еĶ���ģ��
# include <iostream>
using namespace std;

class Base {

public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son : public Base {

public:
	int m_D;

};

void test01() {

	cout << "size of Son = " << sizeof(Son) << endl;
	//vs������������ʾ������cl /d1 reportSingleClassLayoutSon "�̳�-�̳��еĶ���ģ��.cpp"Ҳ�ɲ鿴������Ĳ���
}


int main() { 

	test01();
	
	system("Pause");

	return 0;
}