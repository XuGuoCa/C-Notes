//�������ʹ����鹹
# include <iostream>
using namespace std;

class Animal {

public:
	//���麯��
	virtual void speak() = 0;

	Animal() {

		cout << "Animal �Ĺ��캯������" << endl;
	}

	//���������Խ��  ����ָ���ͷ��������ʱ���ɾ�������
	/*virtual ~Animal() {

		cout << "Animal ��������������" << endl;
	}*/

	//��������    ��Ҫ����Ҳ��Ҫ��ʵ��
	//���˴������� ֮�� �����Ҳ���ڳ����࣬ �޷�ʵ��������
	virtual ~Animal() = 0;
};

Animal::~Animal() {

	cout << "Animal �Ĵ�������������" << endl;
}

class Cat : public Animal {
public:

	Cat(string name) {

		cout << "Cat ���캯������" << endl;
		m_Name = new string(name);
	}

	~Cat() {

		if (m_Name != NULL) {

			cout << "Cat ������������" << endl;
			delete m_Name;
			m_Name = NULL;
		}
	}

	void speak() {

		cout << *m_Name << "Сè��˵��" << endl;
	}

	string *m_Name;
};

void test01() {

	Animal* animal = new Cat("Tom");
	animal->speak();
	//����ָ����������ʱ��  ����������������������� ��������������ж������ԣ� �����ڴ�й©
	delete animal;
}

int main() {

	test01();

	system("Pause");

	return 0;
}