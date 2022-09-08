//set����͸�ֵ
# include <iostream>
using namespace std;
# include <set>

/*
���죺
     set<T> st;            //Ĭ�Ϲ��캯��
     set(Const set &st);   //�������캯��

��ֵ��
     set& operator=(const set &st);     //���صȺŲ�����
*/

void printSet(const set<int>s) {

    for (set<int>::const_iterator it = s.begin(); it != s.end(); it++) {

        cout << *it << " ";
    }
    cout << endl;
}

void test01() {

    set<int>s1;

    //�������� ֻ��insert��ʽ
    s1.insert(10);
    s1.insert(40);
    s1.insert(20);
    s1.insert(30);
    s1.insert(30);
    s1.insert(40);

    //��������
    //set�������ص㣬����Ԫ���ڲ����ʱ����Զ�����
    //set��������������ظ���ֵ
    printSet(s1);   //10 20 30 40

    //��������
    set<int>s2(s1);
    printSet(s2);

    //��ֵ
    set<int>s3;
    s3 = s2;
    printSet(s3);
}

int main() {

    test01();

	system("pause");

	return 0;
}