#include <iostream>

using std::cout;
using std::endl;
using std::string;

// C++ ���Ա�������·�ʽ����,ֻ��һ�ֱ��� ����� ��Ķ���(ʵ��) ����
class Person {
	int m_A;// �Ǿ�̬��Ա���� ��ʵ������
	static int m_b;// ��̬��Ա���� ����ʾ����������
	int func() { return 0; };// �Ǿ�̬��Ա����,����ʵ����������
	static int function2() { return 0; };// ��̬��Ա����,����ʵ����������
};
void test01() {
	/*class Person {

	};*/
	Person p;
	// �� class��ʵ�� �ڴ�ռ�ô�СΪ1���ֽ�,
	//C++���������ÿ���ն���Ҳ����һ���ڴ�ռ�,��Ϊ�����ֿն���ռ�ڴ�ĵ�ַ,ÿ���ն���ĵ�ַҲ������ͬ
	cout << "size of p: " << sizeof(p) << endl;// 1
}

void test02() {
	
	Person p1;
	// һ�� class ��Ϊ��, �ն���Ҳ�Ͳ�������, ԭ��ռ�õ� 1byte�ռ�Ҳ�Ͳ������,���ǰ��ճ�Ա����ķǾ�̬��Ա�����Ĵ�С������
	cout << "size of p1: " << sizeof(p1) << endl;// 4
}
int main() {
	test01();
	test02();
	system("pause");
	return 0;
}
