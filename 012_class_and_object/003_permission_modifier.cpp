#include<iostream>

using std::cout;
using std::endl;
using std::string;
using std::cin;

// ��� Ȩ�ޱ�ʶ�� public private protected
//һ��������ж�� public��protected �� private �������
//ÿ�������������һ���������ʼ֮ǰ�������������������������֮ǰ������Ч�ġ���Ա�����Ĭ�Ϸ������η��� private��

class PermissionClass {
	// public ���� ��Ա���Ա� ���� �� ʵ������
	string s_age;// Ĭ��Ϊ˽������
public:
	string s_name;

private:
	string s_id;

protected:
	int s_money;

public:
	// ���� ���Է��� ��������г�Ա, ���� public, private, protected
	void setDefault() {
		s_name = "����";
		s_id = "114514";
		s_money = 115;
	};
};

int main3() {
	PermissionClass class1;
	class1.s_name = "11";// ���� ֻ�ܷ���public
	//class1.s_age = "123";//����������, ��Ա PermissionClass::s_age ���ɷ���
	//class1.s_id = "123";// ����������, s_id��Ա���ɷ���
	//class1.s_money = 123;// ����������, s_money��Ա���ɷ���
	system("pause");
	return 0;
}