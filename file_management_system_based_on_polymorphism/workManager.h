#pragma once  // 防止头文件重复包含
#include<iostream> // 包含输入输出流头文件

using namespace std;// 使用标准命名空间



class WorkManager {
public:
	WorkManager(); // constructor func
	~WorkManager();// destructor func

	/* 菜单展示 */
	void show_menu();
	/* 退出功能 */
	void exit_system();
};