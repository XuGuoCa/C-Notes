#pragma once
# include <iostream>
using namespace std;
# include <string>

class Person {

public:

	//构造函数
	Person(string name, string number, string address) {
		this->m_Name = name;
		this->m_Number = number;
		this->m_Address = address;
	}

	//联系人资料
	string m_Name;
	string m_Number;
	string m_Address;

	void ShowPer();
};
