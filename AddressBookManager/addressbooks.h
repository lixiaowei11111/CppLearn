#pragma once
#include<iostream>
#include<string>
#define MAX 50
//#include  #define ���ܹ��� ; �ָ���,������������Ԥ���Ĵ���

using std::cout;
using std::cin;
using std::endl;
using std::string;

// 1. �����˵���ʾ����
void showMenu();

//2. ������ϵ�˽ṹ��
struct Person {
	string m_Name;// ����;
	int m_Sex;// �Ա�; 1�� 2Ů
	int m_Age;// ����
	string m_Phone;// �绰
	string m_Address;// ��ַ
};

// 2. ͨѶ¼�ṹ��
struct Addressbooks {
	//ͨѶ¼�������ϵ������
	struct Person personArray[MAX];
	//ͨѶ¼��ǰ��ϵ�˸���
	int m_Size;

};

// 4. ���������ϵ�˺���
void addPerson(Addressbooks * abs);

// 5. ������ʾ��ϵ�˲���
void printAddressbooksInfo(Addressbooks* abs);


// 6. ������ѯ�������Ƿ���ڸ���ϵ�˵ĺ��� ����1�������, ����0��������
int isExist(Addressbooks * abs, string phone);


// 7.����ɾ����ϵ�˺���
void deletePersonByPhone(Addressbooks* abs, string phone);

//8. ����������ϵ�˺���
void findPerson(Addressbooks* abs);

// 9.�����޸���ϵ�˺���
void modifPerson(Addressbooks* abs);

//10.�������ͨѶ¼����
void  clsAddressbook(Addressbooks* abs);