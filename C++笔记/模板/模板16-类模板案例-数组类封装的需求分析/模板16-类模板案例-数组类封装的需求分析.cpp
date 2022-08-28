//��ģ�尸��
# include <iostream>
using namespace std;
# include "MyArray.hpp"
# include <string>

/*
����������
        ���Զ��������������Լ��Զ����������͵����ݽ��д���
		�������е����ݴ洢������
		���캯���п��Դ�����������
		�ṩ��Ӧ�Ŀ��������Լ�operator=��ֹǳ��������
		�ṩβ�巨��βɾ���������е����ݽ������Ӻ�ɾ��
		����ͨ���±�ķ�ʽ���������е�Ԫ��
		���Ի�ȡ�����е�ǰԪ�ظ�������������
*/

//��ӡ����
void printIntArray(MyArray<int>& arr) {
	for (int i = 0; i < arr.getSize(); i++) {
		cout << arr[i] << endl;
	}
}

void test01() {

	MyArray<int>arr1(5);
	for (int i = 0; i < arr1.getCapacity(); i++) {
		
		arr1.Push_Back(i);
	}

	cout << "arr1�Ĵ�ӡ���Ϊ:" << endl;

	printIntArray(arr1);

	cout << "arr1������Ϊ:" << arr1.getCapacity() << endl;
	cout << "arr1�Ĵ�СΪ:" << arr1.getSize() << endl;

	cout << "------------------------" << endl;
	MyArray<int>arr2(arr1);

	cout << "arr2�Ĵ�ӡ���Ϊ:" << endl;

	printIntArray(arr2);


	//βɾ
	arr2.Del_Back();
	cout << "arr2βɾ��:" << endl;
	cout << "arr2������Ϊ:" << arr2.getCapacity() << endl;
	cout << "arr2�Ĵ�СΪ:" << arr2.getSize() << endl;
}

void test02();

int main() {

	//test01();
	test02();

	system("pause");

	return 0;
}

//�����Զ�����������
class Person {

public :

	Person(){}
	//�вι���
	Person(string name, int age) {
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;
};

void printPersonArray(MyArray<Person> &arr) {

	for (int i = 0; i < arr.getSize(); i++) {
		cout << "����:" << arr[i].m_Name << "  ����:" << arr[i].m_Age << endl;
	}
}

void test02() {

	MyArray<Person>arr3(10);

	Person p1("����", 18);
	Person p2("����", 19);
	Person p3("�����", 999);
	Person p4("С��", 20);
	Person p5("С��", 22);

	//�����ݲ��뵽������
	arr3.Push_Back(p1);
	arr3.Push_Back(p2);
	arr3.Push_Back(p3);
	arr3.Push_Back(p4);
	arr3.Push_Back(p5);

	//��ӡ����
	printPersonArray(arr3);

	//�������
	cout << "����������СΪ:" << arr3.getCapacity() << endl;

	//����Ĵ�С
	cout << "�����СΪ:" << arr3.getSize() << endl;

}