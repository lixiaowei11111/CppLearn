#include <iostream>

using std::cout;
using std::endl;
using std::string;

// ������Ԫ


//������
class Home;
class GoodFriend {
public:
	Home* home;
	void visit();
	GoodFriend();
};
class Home {
	friend class GoodFriend;
public:
	string m_LivingRoom;
	Home();
private:
	string m_Bedroom;
};
Home::Home() {
	m_LivingRoom = "����";
	m_Bedroom = "����";
}
GoodFriend::GoodFriend() {
	home = new Home;
}
void GoodFriend::visit() {
	cout << "home->m_LivingRoom: " << home->m_LivingRoom << endl;
	cout << "home->m_Bedroom: " << home->m_Bedroom << endl;
}
void test01() {
	GoodFriend gf;
	gf.visit();
}

int main() {
	test01();
	system("pause");
	return 0;
}
