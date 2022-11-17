#include <iostream>
#include<fstream>


using std::cout;
using std::endl;
using std::string;
using std::ofstream;
using std::ios;
// д�ı��ļ�
// **�ı��ļ�** -�ļ����ı��� **ASCII**��ʽ�洢�ڼ������
//�����ļ���������:
//
//1. ofstream : д����
//2. ifstream : ������
//3. fstream : ��д����

// д�ļ�����
void test01() {
	// 1. ���� fstream ͷ�ļ�
	// 2. ���� �� ����
	ofstream ofs;
	// 3.���ļ���ʽ
	ofs.open("fileIO_Demo.txt", ios::out);
	// 4.д����
	ofs << "����һ����д�������" << endl;
	ofs << "����txt�ı�" << endl;
	// 5. �ر��ļ�
	ofs.close();

}

void test02() {
	// 1. ���� fstream ͷ�ļ�
	// 2. ���� �� ����
	ofstream ofs;
	// 3.���ļ���ʽ
	ofs.open("./fileIO/01.txt", ios::out);
	// 4.д����
	ofs << "����һ����д�������" << endl;
	ofs << "����txt�ı�" << endl;
	// 5. �ر��ļ�
	ofs.close();

}

int main() {
	test01();
	test02();
	system("pause");
	return 0;
}
