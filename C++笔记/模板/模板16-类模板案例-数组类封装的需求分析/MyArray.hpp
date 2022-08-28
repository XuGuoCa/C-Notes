//�Լ���ͨ��������
# pragma once
# include <iostream>
using namespace std;

template<class T>
class MyArray {

private:
	T* pAddress; //ָ��ָ��������ٵ���ʵ����
	int m_Capacity; //����
	int m_Size; //��С

public:
	//���캯��
	MyArray(int capacity) {
		this->m_Capacity = capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];
	}

	//��������
	MyArray(const MyArray& arr) {
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < arr.m_Size; i++) {

			this->pAddress[i] = arr.pAddress[i];
		}
	}

	//��ֵ��������أ� ��ֹǳ��������
	MyArray& operator=(const MyArray& arr) {
		//���ж�ԭ�������Ƿ������ݣ� ��������ͷ�
		if (this->pAddress != NULL) {

			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Size = 0;
			this->m_Capacity = 0;
		}

		//���
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[arr.m_Capacity];
		for (int i = 0; i < arr.m_Size; i++) {

			this->pAddress[i] = arr.pAddress[i];
		}

		return *this;
	}

	//��������
	~MyArray() {
		if (this->pAddress != NULL) {
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}

	//β�巨
	void Push_Back(const T& val) {
		if (this->m_Size == this->m_Capacity) {
			return;
		}
		this->pAddress[this->m_Size] = val;
		this->m_Size++;
	}

	//βɾ��
	void Del_Back() {
		if (this->m_Size == 0) {
			return;
		}

		this->m_Size--;
	}

	//ͨ���±����Ԫ��
	T& operator[](int index) {
		return this->pAddress[index];
	}

	//��ȡ��ǰԪ�ظ���
	int getSize() {
		return this->m_Size;
	}

	//��ȡ��������
	int getCapacity() {
		return this->m_Capacity;
	}
};
