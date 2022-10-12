#include <iostream>

using std::cout;
using std::endl;
using std::string;


// �̳е����ַ�ʽ public protected private
class Father {
public:
	int a;
protected:
	int b;
private :
	int c;
public:
	Father() {
		a = b = c = 1;
	}
};


// 1.public �̳�, �̳и�������Ȩ�޼̳еĳ�Ա(public, protected),Ȩ���������б��ֲ���
class Son1 :public Father {
public:
	int d;
};
void test01() {
	Son1 s1;
	cout << s1.a << endl;//1
	//cout << s1.b << endl;// protected ��Աʵ����Ȩ����
	//cout << s1.c << endl// private��Ա ��Ȩ����
}

// 2.protected �̳�, �̳и�������Ȩ�޼̳еĳ�Ա(public, protected),�̳еĳ�Ա�������е�Ȩ��ȫ����Ϊprotected
class Son2 :protected Father {
public:
	int d;
};
void test02() {
	Son2 s2;
	//cout << s2.a << endl;// protected ��Աʵ����Ȩ����
	//cout << s2.b << endl;// protected ��Աʵ����Ȩ����
	//cout << s2.c << endl// private��Ա ��Ȩ����
}

// 2.private �̳�, �̳и�������Ȩ�޼̳еĳ�Ա(public, protected),�̳еĳ�Ա�������е�Ȩ��ȫ����Ϊprivate
class Son3 :private Father {
public:
	int d;
};
void test03() {
	Son3 s3;
	//cout << s3.a << endl;// private ��Աʵ����Ȩ����
	//cout << s3.b << endl;// private ��Աʵ����Ȩ����
	//cout << s3.c << endl// private��Ա ��Ȩ����
}

int main() {
	test01();
	test02();
	test03();
	system("pause");
	return 0;
}
