//�˵�����Դ�ļ�
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
		Seek(Data);
		break;
	case 4: //ɾ����ϵ��
		CutOut(Data);
		break;
	case 5: //�޸���ϵ��
		Alter(Data);
		break;
	case 6: // �����ϵ��
		Empty(Data);
		break;
	default:
		return;
	}
}