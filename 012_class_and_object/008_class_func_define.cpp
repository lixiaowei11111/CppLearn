#include <iostream>


using std::cout;
using std::string;
using std::endl;

// �ڲ����庯��
class Box1 {
public:
	// �� �ڲ����庯�� getVolume
	double getVolume(void) {
		return length * width * height;
	};
private:
	double length;
	double width;
	double height;
};

// �� �ⲿ ͨ����Χ**���������** ���������к���, ���к�����Ҫ��������
class Box2 {
public:
	// �� �ڲ����庯�� getVolume
	double getVolume(void);
private:
	double length;
	double width;
	double height;
};
double Box2::getVolume(void) {
	return length * width * height;
};


int main() {




	system("pause");
	return 0;
}