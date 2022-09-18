# include "orderFile.h"

//���캯��
OrderFile::OrderFile() {

	ifstream ifs(ORDER_FILE);
	
	string date; //����
	string interval; //ʱ���
	string stuId; //ѧ�����
	string stuName; //ѧ������
	string roomId; //�������
	string status; //ԤԼ״̬

	this->m_Size = 0; //ԤԼ��¼����

	while (ifs >> date && ifs >> interval && ifs >> stuId && ifs >> stuName && ifs >> roomId && ifs >> status) {

		string key;
		string value;
		map<string, string>m;

		//date:111
		//��ȡʱ��
		int pos = date.find(":"); // 4
		if (pos != -1) {

			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos - 1); // size() = 8   pos = 4  size - pos - 1 = 3

			m.insert(make_pair(key, value));
		}

		//��ȡʱ���
		pos = interval.find(":"); // 4
		if (pos != -1) {

			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		//��ȡѧ�����
		pos = stuId.find(":"); // 4
		if (pos != -1) {

			key = stuId.substr(0, pos);
			value = stuId.substr(pos + 1, stuId.size() - pos - 1);

			m.insert(make_pair(key, value));
		}

		//��ȡѧ������
		pos = stuName.find(":"); // 4
		if (pos != -1) {

			key = stuName.substr(0, pos);
			value = stuName.substr(pos + 1, stuName.size() - pos - 1); 

			m.insert(make_pair(key, value));
		}

		//��ȡ�������
		pos = roomId.find(":"); // 4
		if (pos != -1) {

			key = roomId.substr(0, pos);
			value = roomId.substr(pos + 1, roomId.size() - pos - 1); 

			m.insert(make_pair(key, value));
		}

		//��ȡ���״̬
		pos = status.find(":"); // 4
		if (pos != -1) {

			key = status.substr(0, pos);
			value = status.substr(pos + 1, status.size() - pos - 1); 

			m.insert(make_pair(key, value));
		}

		//��Сmap�������뵽���map����
		this->m_orderDate.insert(make_pair(this->m_Size, m));
		this->m_Size++;
	}

	ifs.close();
}

//����ԤԼ��¼
void OrderFile::updateOrder() {

	if (this->m_Size == 0) {

		return;
	}

	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < this->m_Size; i++) {

		ofs << "ʱ��:" << this->m_orderDate[i]["ʱ��"] << " ";
		ofs << "ʱ���:" << this->m_orderDate[i]["ʱ���"] << " ";
		ofs << "ѧ�����:" << this->m_orderDate[i]["ѧ�����"] << " ";
		ofs << "ѧ������:" << this->m_orderDate[i]["ѧ������"] << " ";
		ofs << "�������:" << this->m_orderDate[i]["�������"] << " ";
		ofs << "���״̬:" << this->m_orderDate[i]["���״̬"] << " ";
	}

	ofs.close();
}