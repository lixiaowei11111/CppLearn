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
	friend void GoodFriend::visit();// 声明一个类的成员函数作为另外一个类的友元函数
public:
	Home();
	string m_LivingRoom;
private:
	string m_BedRoom;
};
Home::Home() {
	m_BedRoom = "卧室";
	m_LivingRoom = "客厅";
}
GoodFriend::GoodFriend() {
	home = new Home;
}
void GoodFriend::visit() {
	cout << "visit函数访问m_Living: " << home->m_LivingRoom << endl;
	cout << "visit函数访问m_Bedroom: " << home->m_BedRoom << endl;
}
void GoodFriend::visit2() {
	cout << "visit2函数访问m_Living: " << home->m_LivingRoom << endl;
	//cout << "visit2函数访问m_Bedroom: " << home->m_BedRoom << endl;// error 同一个类的 visit2函数不是 Home的友元函数不能访问
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
