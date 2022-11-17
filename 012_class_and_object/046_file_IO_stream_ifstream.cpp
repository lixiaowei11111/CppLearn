#include <iostream>
#include<fstream>
#include<sstream>

using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::ios;
using std::getline;

// ���ļ�
void test01() {
	// 1.����ͷ�ļ�
	//2. ���� �� ����
	ifstream ifs;

	//3.���ļ�
	ifs.open("fileIO_Demo.txt", ios::in);

	//3.1 �ж��ļ��Ƿ��ʧ��
	if (!ifs.is_open() ){
		cout << "�ļ���ʧ��" << endl;
	}

	//4.��ȡ�ļ����ݵ����ַ�ʽ
	
	// 4.1 ��ʽһ C�����ַ��� ѭ������
	/*char buf[1024] = {};
	while (ifs>>buf)
	{
		cout << buf << endl;
	}*/

	//4.2 ��ʽ�� C�����ַ���, ��� ifstream��getline����, getline����, 1.�����������ݵ��ַ���,2.����Ĵ�С
	/*char buf[1024] = {};
	while (ifs.getline(buf,sizeof(buf)))
	{
		cout << buf << endl;
	}*/

	//4.3 ��ʽ�� C++ �����ַ���,��������, ȫ�ֺ���getline ��������
	/*string str;
	while (getline(ifs,str))
	{
		cout << str << endl;
	}*/

	//4.4 ��ʽ�� �����ַ�����, ʹ�� ifstream�� get�������е����ַ���ֵ
	char c;
	while ((c = ifs.get())!=EOF) //EOF(end of file) �����ж��ļ������Ƿ�����ı�־
	{
		cout << c;
	}


	//5. �ر��ļ�
	ifs.close();
}

int main() {
	test01();
	system("pause");
	return 0;
}
