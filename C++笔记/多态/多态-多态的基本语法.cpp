//��̬
# include <iostream>
using namespace std;

//������
class Animal {
public:
	//virtual ���麯��
	virtual void speak() {

		cout << "������˵��" << endl;
	}
};

class Cat : public Animal {

public:
	//��д  ��������ֵ����  ������  �����б�  ��ȫ��ͬ
	void speak() {          //����Ҳ���Լ�virtual��д�ɲ�д��Ӱ��
		cout << "è��˵��" << endl;
	}
};

class Dog : public Animal {

public:
	void speak() {
		cout << "����˵��" << endl;
	}
};

//ִ��˵������
//��ַ���  �ڱ���׶�ȷ��������ַ
//�����ִ��è˵���� ��ô���������ַ�Ͳ�����ǰ�󶨣� ��Ҫ���н׶ν��а󶨣� Ҳ���ǵ�ַ���

//��̬��̬��������
//1.�м̳й�ϵ
//2.������д������麯��
void doSpeak(Animal& animal) {
	animal.speak();
}

void test01() {
	Cat cat;

	doSpeak(cat);

	Dog dog;

	doSpeak(dog);
}


int main() {

	test01();

	system("pause");

	return 0;
}