#include<iostream>
#include<string>
//#include  #define ���ܹ��� ; �ָ���,������������Ԥ���Ĵ���
#include "addressbooks.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;
int main() {
	
	// 2.����ѡ��
	int select = 0;

	// 3. ����ͨѶ¼����
	Addressbooks addressbooks;
	addressbooks.m_Size = 0;
	while (true)
	{
		// 1.������ʾ�˵�����
		showMenu();
		cout << "��ӭʹ��ͨѶ¼,����������ѡ����!" << endl;

		cin >> select;
		switch (select)
		{
		case 1: //1,�����ϵ��
			addPerson(&addressbooks);
			break;
		case 2: //2,��ʾ��ϵ��
			printAddressbooksInfo(&addressbooks);
			break;
		case 3: //3,ɾ����ϵ��
		{
			string phone = "";
			cout << "������Ҫɾ������ϵ�˵ĵ绰" << endl;
			cin >> phone;
			deletePersonByPhone(&addressbooks, phone);
		}
			break;
		case 4: //4,������ϵ��
			findPerson(&addressbooks);
			break;
		case 5: //5,�޸���ϵ��
			modifPerson(&addressbooks);
			break;
		case 6: //6,�����ϵ��
			clsAddressbook(&addressbooks);
			break;
		case 0: //0,�˳�ͨѶ¼
			cout << "��ӭ����ٴ�ʹ��!" << endl;
			system("pause");
			return 0;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}