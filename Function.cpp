# include "Function.h"

void Function(int Choose, Person &Data) {

	switch (Choose) {

	case 1: //�����ϵ��
		Add(Data);
		break;
	case 2: //��ʾ��ϵ��
		Show(Data);
		break;
	case 3: //������ϵ��
		break;
	case 4: //ɾ����ϵ��
		break;
	case 5: //�޸���ϵ��
		break;
	default:
		return;
	}
}