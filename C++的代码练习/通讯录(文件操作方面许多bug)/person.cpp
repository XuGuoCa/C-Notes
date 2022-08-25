# include "person.h"

void Person::ShowPer() {
	cout << "姓名:" << this->m_Name
		<< "\t电话号码:" << this->m_Number
		<< "\t地址:" << this->m_Address << endl;
}