//���μ̳�
# include <iostream>
using namespace std;

//������
class animal{

public:
	int m_A;
};

//����
//������̳� ������μ̳�����
//�ڼ̳�֮ǰ ���Ϲؼ��� virtual ��Ϊ��̳�
//Animal���Ϊ �����
class Sheep :virtual public animal{};

//����
class Tuo :virtual public animal{};

//������
class SheTuo : public Sheep, public Tuo{};

void test01() {

	SheTuo s1;

	s1.Sheep::m_A = 18;
	s1.Tuo::m_A = 28;

	cout << "s1.Sheep::m_A = " << s1.Sheep::m_A << endl;
	cout << "s1.Tuo::m_A =" << s1.Tuo::m_A << endl;
	cout << "s1.m_A = " << s1.m_A << endl;
}

int main() {

	test01();

	system("pause");

	return 0;
}