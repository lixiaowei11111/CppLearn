#include <iostream>

using std::cout;
using std::endl;
using std::string;
class Home;
class GoodFriend {
public:
	GoodFriend();
	void visit();
	void visit2();
	Home* home;
};
class Home {
	friend void GoodFriend::visit();// ����һ����ĳ�Ա������Ϊ����һ�������Ԫ����
public:
	Home();
	string m_LivingRoom;
private:
	string m_BedRoom;
};
Home::Home() {
	m_BedRoom = "����";
	m_LivingRoom = "����";
}
GoodFriend::GoodFriend() {
	home = new Home;
}
void GoodFriend::visit() {
	cout << "visit��������m_Living: " << home->m_LivingRoom << endl;
	cout << "visit��������m_Bedroom: " << home->m_BedRoom << endl;
}
void GoodFriend::visit2() {
	cout << "visit2��������m_Living: " << home->m_LivingRoom << endl;
	//cout << "visit2��������m_Bedroom: " << home->m_BedRoom << endl;// error ͬһ����� visit2�������� Home����Ԫ�������ܷ���
}

void test01() {
	GoodFriend gf;
	gf.visit();
	gf.visit2();
}
int main() {
	test01();
	system("pause");
	return 0;
}
