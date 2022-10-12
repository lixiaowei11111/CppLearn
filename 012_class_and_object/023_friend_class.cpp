#include <iostream>

using std::cout;
using std::endl;
using std::string;

// 类做友元


//声明类
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
	m_LivingRoom = "客厅";
	m_Bedroom = "卧室";
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
