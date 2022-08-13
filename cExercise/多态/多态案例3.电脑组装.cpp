# include <iostream>
using namespace std;

//����ͬ�������
//����CPU��
class CPU {

public :
	//����ļ��㺯��
	virtual void calculate() = 0;
};

//�����Կ���
class VideoCard {

public:
	//������Կ�����
	virtual void display() = 0;
};
//�����ڴ����� 
class Memory {

public:
	//����Ĵ��溯��
	virtual void storage() = 0;
};

//������
class Computer {

public:

	Computer(CPU* cpu, VideoCard * vc, Memory* mem) {

		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem;
	}

	~Computer() {

		if (m_cpu != NULL) {
			delete m_cpu;
			m_cpu = NULL;
		}
		if (m_vc != NULL) {
			delete m_vc;
			m_vc = NULL;
		}
		if (m_mem != NULL) {
			delete m_mem;
			m_mem = NULL;
		}
	}

	//��������
	void work() {

		//��������������� ���ýӿ�
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}

private:
	CPU * m_cpu;//cpu���ָ��
	VideoCard * m_vc;//�Կ����ָ��
	Memory * m_mem;//�ڴ������ָ��
};

//����ĳ���
//Intel����
class IntelCPU : public CPU {
public :
	void calculate() {

		cout << "Intel��CPU��ʼ�����ˣ�" << endl;
	}
};

class IntelVideoCard : public VideoCard {
public:

	void display() {

		cout << "Intel���Կ���ʼ��ʾ�ˣ�" << endl;
	}
};

class IntelMemory : public Memory {
public:

	void storage() {

		cout << "Intel���ڴ�����ʼ�����ˣ�" << endl;
	}
};

//Lenovo
class LenovoCPU : public CPU {
public:
	void calculate() {

		cout << "Lenovo��CPU��ʼ�����ˣ�" << endl;
	}
};

class LenovoVideoCard : public VideoCard {
public:

	void display() {

		cout << "Lenovo���Կ���ʼ��ʾ�ˣ�" << endl;
	}
};

class LenovoMemory : public Memory {
public:

	void storage() {

		cout << "Lenovo���ڴ�����ʼ�����ˣ�" << endl;
	}
};

void test01() {

	//��һ̨������װ
	cout << "�ڶ�̨���Կ�ʼ����" << endl;
	CPU* intelCPU = new IntelCPU;
	VideoCard* intelVideoCard = new IntelVideoCard;
	Memory* intelMemory = new IntelMemory;

	Computer* computer1 = new Computer(intelCPU, intelVideoCard, intelMemory);
	computer1->work();
	delete computer1;

	cout << "-----------------------------------------------------------" << endl;
	//�ڶ�̨������װ
	cout << "�ڶ�̨���Կ�ʼ����" << endl;
	Computer* computer2 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMemory);
	computer2->work();
	delete computer2;

	cout << "--------------------------------------" << endl;
	//����̨������װ
	cout << "����̨���Կ�ʼ����" << endl;
	Computer* computer3 = new Computer(new IntelCPU, new LenovoVideoCard, new LenovoMemory);
	computer3->work();
	delete computer3;
}
int main() {

	test01();

	system("Pause");

	return 0;
}