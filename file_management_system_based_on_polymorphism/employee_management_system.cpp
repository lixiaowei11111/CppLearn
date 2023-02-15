#include <iostream>
#include "workManager.h"

using std::cout;
using std::endl;
using std::string;

int main() {
	/* 创建实例化 WorkManager 对象*/
	WorkManager wm;

	// 输入的数字
	int choice = 0;
	while (true)
	{
		wm.show_menu();
		cout << "请输入您的选项" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			wm.exit_system();
			break;//0 退出系统
		case 1:
			break;//1 增加职工
		case 2:
			break;//2 显示职工
		case 3:
			break;//3 删除职工
		case 4:
			break;//4 修改职工
		case 5:
			break;//5 查找职工
		case 6:
			break;//6 编号排序
		case 7:
			break;//7 清空文档
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}
