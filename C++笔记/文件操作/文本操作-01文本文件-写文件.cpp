//�ı�����
# include <iostream>
# include <fstream>//ͷ�ļ�����

using namespace std;


/*
�����ļ���������
1.ofstream : д����
2.ifstream : ������
3.fstream  : ��д����
*/

int main() {

	//1.����ͷ�ļ� fstream
	
	//2.����������
	ofstream ofs;//ofs ���������ȡ

	//3.ָ���򿪷�ʽ
	ofs.open("test.txt", ios::out);

	//4.д����
	ofs << "����������" << endl;
	ofs << "�Ա���" << endl;
	ofs << "���䣺18" << endl;

	//5.�ر��ļ�
	ofs.close();
	

	system("pause");

	return 0;
}