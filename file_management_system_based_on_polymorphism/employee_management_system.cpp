#include <iostream>
#include "workManager.h"

using std::cout;
using std::endl;
using std::string;

int main() {
	/* ����ʵ���� WorkManager ����*/
	WorkManager wm;

	// ���������
	int choice = 0;
	while (true)
	{
		wm.show_menu();
		cout << "����������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			wm.exit_system();
			break;//0 �˳�ϵͳ
		case 1:
			break;//1 ����ְ��
		case 2:
			break;//2 ��ʾְ��
		case 3:
			break;//3 ɾ��ְ��
		case 4:
			break;//4 �޸�ְ��
		case 5:
			break;//5 ����ְ��
		case 6:
			break;//6 �������
		case 7:
			break;//7 ����ĵ�
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}
