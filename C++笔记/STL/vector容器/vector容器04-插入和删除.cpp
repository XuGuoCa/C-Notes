//vector�����ɾ��
# include <iostream>
using namespace std;
# include <vector>

//������������vector�������в��룬 ɾ������

/*
����ԭ�ͣ�
       push_back(lel);                                     β������Ԫ��ele
	   pop_back();                                         ɾ�����һ��Ԫ��
	   insert(const_iterator pos, ele);                    ������ָ��λ��pos����Ԫ��ele
	   insert(const_iterator pos, int count, ele);         ������ָ��λ��pos����count��Ԫ��ele
	   erase(const_iterator pos);                          ɾ��������ָ���Ԫ��
	   erase(cinst_iterator start, const_iterator end);    ɾ����������start��end֮��Ԫ��
	   clear();                                            ɾ������������Ԫ��
*/

void printVector(vector<int>& v) {

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

void test01() {

	vector<int> v;
	//β��
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	//����
	printVector(v);

	//βɾ
	v.pop_back();
	printVector(v);

	//����  ��һ������Ҳ�ǵ�����
	v.insert(v.begin(), 100);
	printVector(v);

	v.insert(v.begin(), 2, 100);
	printVector(v);

	//ɾ��  ����Ҳ�ǵ�����
	v.erase(v.begin());
	printVector(v);

	//���
	//v.erase(v.begin(), v.end());
	v.clear();
	printVector(v);


}

int main() {

	test01();

	system("pause");

	return 0;
}