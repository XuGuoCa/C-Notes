//��ģ�尸��
# include <iostream>
using namespace std;
# include "MyArray.hpp"

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

int main() {

	test01();

	system("pause");

	return 0;
}