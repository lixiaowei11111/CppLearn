#pragma once  // ��ֹͷ�ļ��ظ�����
#include<iostream> // �������������ͷ�ļ�

using namespace std;// ʹ�ñ�׼�����ռ�



class WorkManager {
public:
	WorkManager(); // constructor func
	~WorkManager();// destructor func

	/* �˵�չʾ */
	void show_menu();
	/* �˳����� */
	void exit_system();
};