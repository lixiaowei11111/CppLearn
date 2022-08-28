#include "addressbooks.h"
//1.定义showMenu 函数
void showMenu() {
	cout << "************************" << endl;
	cout << "***** 1,添加联系人 *****" << endl;
	cout << "***** 2,显示联系人 *****" << endl;
	cout << "***** 3,删除联系人 *****" << endl;
	cout << "***** 4,查找联系人 *****" << endl;
	cout << "***** 5,修改联系人 *****" << endl;
	cout << "***** 6,清空联系人 *****" << endl;
	cout << "***** 0,退出通讯录 *****" << endl;
	cout << "************************" << endl;
}

// 4.定义添加联系人函数
void addPerson(Addressbooks* abs) {
	// 判断是否超过最大值
	if (abs->m_Size >= MAX) {
		cout << "当前通讯录容量已达上限" << endl;
		return;
	}
	int size = abs->m_Size;
	// 添加联系人信息

	//姓名
	string name = "未知";
	cout << "请输入姓名" << endl;
	cin >> name;
	abs->personArray[size].m_Name = name;

	//性别
	int sex = 1;
	cout << "请输入性别 1表示男 2表示女" << endl;
	while (true)
	{
		cin >> sex;
		if (sex == 1 || sex == 2) {
			abs->personArray[size].m_Sex = sex;
			break;
		}
		else
		{
			cout << "请输入正确性别!" << endl;
		}
	}
	// 年龄
	unsigned int age = 0;
	cout << "请输入年龄" << endl;
	cin >> age;
	abs->personArray[size].m_Age = age;
	// 电话
	string phone = "未知";
	cout << "请输入电话" << endl;
	cin >> phone;
	abs->personArray[size].m_Phone = phone;

	// 地址
	string address = "未知";
	cout << "请输入地址" << endl;
	cin >> address;
	abs->personArray[size].m_Address = address;

	abs->m_Size++;
	cout << "录入联系人信息成功!" << endl;
	system("pause"); // 请按任意键继续
	system("cls");// 清空;

	return;
}

// 5. 定义显示联系人操作
void printAddressbooksInfo(Addressbooks* abs) {
	int absSize = abs->m_Size;

	// 判断有没有联系人
	if (absSize == 0) {
		cout << "暂无联系人,请添加后再进行操作!" << endl;
	}
	else
	{
		cout << "姓名: " << "\t性别: " << "\t年龄: " << "\t电话: " << "\t\t\t地址: " << endl;
		for (size_t i = 0; i < absSize; i++)
		{
			Person person = abs->personArray[i];
			cout << person.m_Name << "\t" << (person.m_Sex == 1 ? "男" : "女") << "\t" << person.m_Age << "\t" << person.m_Phone << "\t\t\t" << person.m_Address << endl;
		}
	}
	system("pause"); // 请按任意键继续
	system("cls");// 清空;
}

// 6. 定义查询数组中是否存在该联系人的函数 返回 index代表存在, 返回-1代表不存在
int isExist(Addressbooks* abs, string phone) {
	int flag = -1;
	for (size_t i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Phone == phone) {
			flag = i;
		}
	}

	return flag;// 存在返回对应的下表编号,不存在返回-1
}

// 7. 定义删除联系人函数
void deletePersonByPhone(Addressbooks* abs, string phone) {
	int ret = isExist(abs, phone);
	if (ret != -1) {
		for (size_t i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		};
		abs->m_Size--;
		cout << "删除联系人成功!" << endl;
	}
	else
	{
		cout << "未查找到联系电话未" << phone << "的联系人,不能执行删除操作!" << endl;

	};
	system("pause");
	system("cls");
	return;
}

//8. 定义查找联系人函数
void findPerson(Addressbooks* abs) {
	string phone = "";
	cout << "请输入需要查找的联系的电话" << endl;
	cin >> phone;
	int ret = -1;
	ret = isExist(abs, phone);
	if (ret != -1) {
		cout << "姓名" << abs->personArray[ret].m_Name << endl;
		cout << "性别" << abs->personArray[ret].m_Sex << endl;
		cout << "年龄" << abs->personArray[ret].m_Age << endl;
		cout << "电话" << abs->personArray[ret].m_Phone << endl;
		cout << "地址" << abs->personArray[ret].m_Address << endl;
	}
	else
	{
		cout << "未查找到该联系人" << endl;
	};
	system("pause");
	system("cls");
	return;
}

// 9.定义修改联系人函数
void modifPerson(Addressbooks* abs) {
	string phone = "";
	cout << "请输入需要查找的联系的电话" << endl;
	cin >> phone;
	int ret = -1;
	ret = isExist(abs, phone);
	if (ret != -1) {
		//姓名
		string name = "未知";
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		//性别
		int sex = 1;
		cout << "请输入性别 1表示男 2表示女" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			else
			{
				cout << "请输入正确性别!" << endl;
			}
		}
		// 年龄
		unsigned int age = 0;
		cout << "请输入年龄" << endl;
		cin >> age;
		abs->personArray[ret].m_Age = age;
		// 电话
		string phone = "未知";
		cout << "请输入电话" << endl;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		// 地址
		string address = "未知";
		cout << "请输入地址" << endl;
		cin >> address;
		abs->personArray[ret].m_Address = address;
		cout << "修改联系人信息成功!" << endl;
	}
	else
	{
		cout << "未查找到该联系人" << endl;
	};
	system("pause");
	system("cls");
	return;
}

//10.定义清空通讯录函数
void  clsAddressbook(Addressbooks* abs) {
	string flag = "";
	cout << "确定要清空通讯录吗? 确认是请输入y/Y" << endl;
	cin >> flag;
	if (flag == "yes" || flag == "y" || flag == "Y") {
		abs->m_Size = 0;
		cout << "通讯录清空成功!" << endl;
	};
	system("pause");
	system("cls");
	return;
};