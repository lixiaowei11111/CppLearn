#include <iostream>
#include<math.h>

using std::cout;
using std::endl;
using std::string;
using std::pow;

// ��Ԫ���� ��Ԫ���������Ĺؼ���Ϊ friend
class Pointer {
	friend void calcDistance(Pointer* p);
public:
	Pointer(int x,int y):m_X(x),m_Y(y) {
		cout << "�вι��캯��������" << endl;
	}
private:
	int m_X;
	int m_Y;
	void getDsitance() {
		cout << "�������ԭ���ֱ�߾���Ϊ: " << pow((m_X * m_X + m_Y * m_Y),0.5) << endl;
	}
};
void calcDistance(Pointer* p) {
	p->getDsitance();// ��Ԫ���� ����˽������
};

int main() {
	Pointer p(3,4);
	calcDistance(&p);//5
	system("pause");
	return 0;
}
