//�̳л����﷨
# include <iostream>
using namespace std;

class Basepage {

public:
	void header() {

		cout << "��ҳ, �����Σ� ��¼�� ע��...������ͷ����" << endl;
	}
	void footer() {

		cout << "�������ģ� ���������� վ�ڵ�ͼ...�������ײ���" << endl;
	}
	void left() {

		cout << "Java, python, C++...�����������б�" << endl;
	}
};

//�̳еĺô��� �����ظ�����
//�﷨�� class ���ࣺ �̳з�ʽ ����
//���� Ҳ��Ϊ ������
//���� Ҳ��Ϊ ����

class Java : public Basepage {   //�̳л����﷨

public:
	void content() {

		cout << "Java����ҳ��" << endl;
	}
};

class Python : public Basepage {

public:
	void content() {

		cout << "Python����ҳ��" << endl;
	}
};

class Cpp : public Basepage {

public:
	void content() {

		cout << "C++����ҳ��" << endl;
	}
};

void test01() {

	Java ja;
	ja.header();
	ja.footer(); 
    ja.left();
	ja.content();

	cout << "--------------------" << endl;

	Python py;
	py.header();
	py.footer();
	py.left();
	py.content();

	cout << "--------------------" << endl;

	Cpp cp;
	cp.header();
	cp.footer();
	cp.left();
	cp.content();
}

int main() {

	test01();

	system("pause");

	return 0;
}