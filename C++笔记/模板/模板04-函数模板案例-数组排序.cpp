# include <iostream>
using namespace std;

//�������������ú���ģ���װһ������ĺ����� ���ԶԲ�ͬ�������������������
//          �������Ӵ�С�� �����㷨Ϊѡ������
//          �ֱ�����char�����int������в���
            
template<class T>
void Sequence(T arr[], int len) {

	for (int i = 0; i < len; i++) {
		int mainOrMax = i;

		for (int j = i + 1; j < len; j++) {

			if (arr[mainOrMax] < arr[j]) {
				mainOrMax = j;
			}
		}

		if (mainOrMax != i) {
			T temp = arr[mainOrMax];
			arr[mainOrMax] = arr[i];
			arr[i] = temp;
		}
	}
}

void test01() {
	int arr1[] = { 2,4,7,3,1,9 };
	char arr2[] = "amdswb";

	Sequence(arr1, 6);
	Sequence(arr2, 6);

	for (int i = 0; i < 6; i++) {
		cout << arr1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < 6; i++) {
		cout << arr2[i] << " ";
	}
	cout << endl;
	cout << endl;
}

int main() {
	
	test01();

	system("pause");

	return 0;
}