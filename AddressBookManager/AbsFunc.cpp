#include "addressbooks.h"
//1.����showMenu ����
void showMenu() {
	cout << "************************" << endl;
	cout << "***** 1,�����ϵ�� *****" << endl;
	cout << "***** 2,��ʾ��ϵ�� *****" << endl;
	cout << "***** 3,ɾ����ϵ�� *****" << endl;
	cout << "***** 4,������ϵ�� *****" << endl;
	cout << "***** 5,�޸���ϵ�� *****" << endl;
	cout << "***** 6,�����ϵ�� *****" << endl;
	cout << "***** 0,�˳�ͨѶ¼ *****" << endl;
	cout << "************************" << endl;
}

// 4.���������ϵ�˺���
void addPerson(Addressbooks* abs) {
	// �ж��Ƿ񳬹����ֵ
	if (abs->m_Size >= MAX) {
		cout << "��ǰͨѶ¼�����Ѵ�����" << endl;
		return;
	}
	int size = abs->m_Size;
	// �����ϵ����Ϣ

	//����
	string name = "δ֪";
	cout << "����������" << endl;
	cin >> name;
	abs->personArray[size].m_Name = name;

	//�Ա�
	int sex = 1;
	cout << "�������Ա� 1��ʾ�� 2��ʾŮ" << endl;
	while (true)
	{
		cin >> sex;
		if (sex == 1 || sex == 2) {
			abs->personArray[size].m_Sex = sex;
			break;
		}
		else
		{
			cout << "��������ȷ�Ա�!" << endl;
		}
	}
	// ����
	unsigned int age = 0;
	cout << "����������" << endl;
	cin >> age;
	abs->personArray[size].m_Age = age;
	// �绰
	string phone = "δ֪";
	cout << "������绰" << endl;
	cin >> phone;
	abs->personArray[size].m_Phone = phone;

	// ��ַ
	string address = "δ֪";
	cout << "�������ַ" << endl;
	cin >> address;
	abs->personArray[size].m_Address = address;

	abs->m_Size++;
	cout << "¼����ϵ����Ϣ�ɹ�!" << endl;
	system("pause"); // �밴���������
	system("cls");// ���;

	return;
}

// 5. ������ʾ��ϵ�˲���
void printAddressbooksInfo(Addressbooks* abs) {
	int absSize = abs->m_Size;

	// �ж���û����ϵ��
	if (absSize == 0) {
		cout << "������ϵ��,����Ӻ��ٽ��в���!" << endl;
	}
	else
	{
		cout << "����: " << "\t�Ա�: " << "\t����: " << "\t�绰: " << "\t\t\t��ַ: " << endl;
		for (size_t i = 0; i < absSize; i++)
		{
			Person person = abs->personArray[i];
			cout << person.m_Name << "\t" << (person.m_Sex == 1 ? "��" : "Ů") << "\t" << person.m_Age << "\t" << person.m_Phone << "\t\t\t" << person.m_Address << endl;
		}
	}
	system("pause"); // �밴���������
	system("cls");// ���;
}

// 6. �����ѯ�������Ƿ���ڸ���ϵ�˵ĺ��� ���� index�������, ����-1��������
int isExist(Addressbooks* abs, string phone) {
	int flag = -1;
	for (size_t i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Phone == phone) {
			flag = i;
		}
	}

	return flag;// ���ڷ��ض�Ӧ���±���,�����ڷ���-1
}

// 7. ����ɾ����ϵ�˺���
void deletePersonByPhone(Addressbooks* abs, string phone) {
	int ret = isExist(abs, phone);
	if (ret != -1) {
		for (size_t i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		};
		abs->m_Size--;
		cout << "ɾ����ϵ�˳ɹ�!" << endl;
	}
	else
	{
		cout << "δ���ҵ���ϵ�绰δ" << phone << "����ϵ��,����ִ��ɾ������!" << endl;

	};
	system("pause");
	system("cls");
	return;
}

//8. ���������ϵ�˺���
void findPerson(Addressbooks* abs) {
	string phone = "";
	cout << "��������Ҫ���ҵ���ϵ�ĵ绰" << endl;
	cin >> phone;
	int ret = -1;
	ret = isExist(abs, phone);
	if (ret != -1) {
		cout << "����" << abs->personArray[ret].m_Name << endl;
		cout << "�Ա�" << abs->personArray[ret].m_Sex << endl;
		cout << "����" << abs->personArray[ret].m_Age << endl;
		cout << "�绰" << abs->personArray[ret].m_Phone << endl;
		cout << "��ַ" << abs->personArray[ret].m_Address << endl;
	}
	else
	{
		cout << "δ���ҵ�����ϵ��" << endl;
	};
	system("pause");
	system("cls");
	return;
}

// 9.�����޸���ϵ�˺���
void modifPerson(Addressbooks* abs) {
	string phone = "";
	cout << "��������Ҫ���ҵ���ϵ�ĵ绰" << endl;
	cin >> phone;
	int ret = -1;
	ret = isExist(abs, phone);
	if (ret != -1) {
		//����
		string name = "δ֪";
		cout << "����������" << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;

		//�Ա�
		int sex = 1;
		cout << "�������Ա� 1��ʾ�� 2��ʾŮ" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			else
			{
				cout << "��������ȷ�Ա�!" << endl;
			}
		}
		// ����
		unsigned int age = 0;
		cout << "����������" << endl;
		cin >> age;
		abs->personArray[ret].m_Age = age;
		// �绰
		string phone = "δ֪";
		cout << "������绰" << endl;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;

		// ��ַ
		string address = "δ֪";
		cout << "�������ַ" << endl;
		cin >> address;
		abs->personArray[ret].m_Address = address;
		cout << "�޸���ϵ����Ϣ�ɹ�!" << endl;
	}
	else
	{
		cout << "δ���ҵ�����ϵ��" << endl;
	};
	system("pause");
	system("cls");
	return;
}

//10.�������ͨѶ¼����
void  clsAddressbook(Addressbooks* abs) {
	string flag = "";
	cout << "ȷ��Ҫ���ͨѶ¼��? ȷ����������y/Y" << endl;
	cin >> flag;
	if (flag == "yes" || flag == "y" || flag == "Y") {
		abs->m_Size = 0;
		cout << "ͨѶ¼��ճɹ�!" << endl;
	};
	system("pause");
	system("cls");
	return;
};