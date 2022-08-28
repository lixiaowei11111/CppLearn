#include<iostream>
#include<string>
//#include  #define 后不能够加 ; 分隔符,否则会产生难以预估的错误
#include "addressbooks.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;
int main() {
	
	// 2.功能选择
	int select = 0;

	// 3. 创建通讯录变量
	Addressbooks addressbooks;
	addressbooks.m_Size = 0;
	while (true)
	{
		// 1.调用显示菜单程序
		showMenu();
		cout << "欢迎使用通讯录,请输入数字选择功能!" << endl;

		cin >> select;
		switch (select)
		{
		case 1: //1,添加联系人
			addPerson(&addressbooks);
			break;
		case 2: //2,显示联系人
			printAddressbooksInfo(&addressbooks);
			break;
		case 3: //3,删除联系人
		{
			string phone = "";
			cout << "请输入要删除的联系人的电话" << endl;
			cin >> phone;
			deletePersonByPhone(&addressbooks, phone);
		}
			break;
		case 4: //4,查找联系人
			findPerson(&addressbooks);
			break;
		case 5: //5,修改联系人
			modifPerson(&addressbooks);
			break;
		case 6: //6,清空联系人
			clsAddressbook(&addressbooks);
			break;
		case 0: //0,退出通讯录
			cout << "欢迎你的再次使用!" << endl;
			system("pause");
			return 0;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}