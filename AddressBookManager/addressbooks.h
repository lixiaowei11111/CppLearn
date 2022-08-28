#pragma once
#include<iostream>
#include<string>
#define MAX 50
//#include  #define 后不能够加 ; 分隔符,否则会产生难以预估的错误

using std::cout;
using std::cin;
using std::endl;
using std::string;

// 1. 声明菜单显示函数
void showMenu();

//2. 定义联系人结构体
struct Person {
	string m_Name;// 姓名;
	int m_Sex;// 性别; 1男 2女
	int m_Age;// 年龄
	string m_Phone;// 电话
	string m_Address;// 地址
};

// 2. 通讯录结构体
struct Addressbooks {
	//通讯录保存的联系人数组
	struct Person personArray[MAX];
	//通讯录当前联系人个数
	int m_Size;

};

// 4. 声明添加联系人函数
void addPerson(Addressbooks * abs);

// 5. 声明显示联系人操作
void printAddressbooksInfo(Addressbooks* abs);


// 6. 声明查询数组中是否存在该联系人的函数 返回1代表存在, 返回0代表不存在
int isExist(Addressbooks * abs, string phone);


// 7.声明删除联系人函数
void deletePersonByPhone(Addressbooks* abs, string phone);

//8. 声明查找联系人函数
void findPerson(Addressbooks* abs);

// 9.声明修改联系人函数
void modifPerson(Addressbooks* abs);

//10.声明清空通讯录函数
void  clsAddressbook(Addressbooks* abs);