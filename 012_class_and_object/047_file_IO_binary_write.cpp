#include <iostream>
#include<fstream>


using std::cout;
using std::endl;
using std::ofstream;
using std::ios;


// д��������ļ�
class Person {
public:
	char m_Name[64];
	int m_Age;
};


void test01() {
	// 1.����ͷ�ļ�
	// 2.���ù��캯����������ʼ�� stream ����
	ofstream ofs("binary_file.txt", ios::out | ios::binary);

	// 3. д�� ���ļ��������
	Person p = { "����",28};//c++�� class Ҳ����ʹ�� struct�Ĵ�����ʽ, ע��class �� struct������, ֻ��Ȩ����������
	ofs.write((const char*) &p,sizeof(p));
	// (const char*)&ofs ����˼�ǽ� Person* ǿ��תΪ char* ָ��;��Ϊ �����ֿ� (const char*) ָ����Ҫ��һ������ǿ��ת��Ϊ char*��; &ofs ��ʾ����Person* ���͵�ָ��

	// 4. �ر� stream ����
	ofs.close();
}

int main() {
	test01();
	system("pause");
	return 0;
}
