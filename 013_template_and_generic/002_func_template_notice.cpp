#include <iostream>

using std::cout;
using std::endl;
using std::string;


//template<class T> // ���巺�͹ؼ��� ������ typename Ҳ������ class
// һ����Զ�����classʱ ʹ�� class ,���庯��ʱʹ�� typename
// ���� ���ۺ��� ���� �� ,����class �ؼ���
// ʹ�÷���ʱ,Ҫע�������

//1. �Զ������Ƶ��������Ƶ���һ�µ���������T,�ſ���ʹ��

template<typename T>
void mySwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}
void test01() {
	int a = 10;
	string b = "aa";
	char char1[] = "1311331";
	//mySwap(a, b);// error û�����������ƥ��ĺ���ģ��
	//mySwap(b, char1);// error û�����������ƥ��ĺ���ģ��
}

// 2. ģ�����Ҫȷ����T���������ͣ��ſ���ʹ��
template<class T>
void func() {
	cout << "����func����" << endl;
}

void test02() {
	//func();//error ��������Ҫȷ����T���������� �ſ���ʹ��
	func<string>();// ����func����
}


int main() {
	test01();
	test02();
	system("pause");
	return 0;
}
