# include "Function.h"

void Function(Science& Data, int Choose) {

	switch(Choose) {

	case 1:      //添加学生资料
		Add(Data);
		break;
	case 2:   //添加学生成绩
		break;
	case 3:   //查找学生资料
		break;
	case 4:  //显示学生资料
		break;
	case 5:     //学生总成绩排名
		break;
	case 6:     //学生各科成绩排名
		break;
	default:
		return;

	}
}