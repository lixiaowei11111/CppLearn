#include <iostream>
#include <fstream>


using std::cout;
using std::endl;
using std::string;
using std::ios;
using std::ifstream;


// ��ȡ�������ļ� binary_file.txt
class Person {
public:
	char m_Name[64];
	int m_Age;
};


void test01() {
	// 1. ���ͷ�ļ�
	// 2. ����stream ����
	ifstream ifs("binary_file.txt", ios::in | ios::binary);

	// 3. �ж��Ƿ��ȡ�ɹ�
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	};

	// 4. ���ļ����� ��ֵ������
	Person p;
	ifs.read((char*)&p, sizeof(Person));

	cout << "����:" << p.m_Age << endl;
	cout << "����:" << p.m_Name << endl;

	//5. �ر� stream ����
	ifs.close();
}
int main() {
	test01();
	system("pause");
	return 0;
}
