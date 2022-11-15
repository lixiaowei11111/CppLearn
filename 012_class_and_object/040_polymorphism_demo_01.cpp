#include <iostream>

using std::cout;
using std::endl;
using std::string;


// 多态 符合 开闭原则, 不去修改老代码, 在老代码的基础上进行开发

// 利用 一个 多态 开发一个具有扩展性的计算器,实现 整型的四则运算

// 1.实现一个计算器的抽象类
class AbstractCalculator {
public:
	int m_A;
	int m_B;
	virtual int getResult() {
		return 0;
	}
};

class AddCalculator:public AbstractCalculator {
public:
	int getResult() {
		return m_A + m_B;
	}
};

class SubCalculator :public AbstractCalculator {
public:
	int getResult() {
		return m_A - m_B;
	}
};

class MulCalculator :public AbstractCalculator {
public:
	int getResult() {
		return m_A*m_B;
	}
};

class DivCalculator :public AbstractCalculator {
public:
	int getResult() {
		return m_A/m_B;
	}
};

void test01() {
	AbstractCalculator* abc=new AddCalculator;
	// 重写基类中的 虚函数, 需要将 基类指针的指向设为 对应的子类实例地址,达到动态对函数进行函数的地址赋值
	abc->m_A = 10;
	abc->m_B = 20;
	cout <<"+: " << abc->getResult() << endl;//30

	delete abc;// 清空add

	abc = new SubCalculator;
	abc->m_A = 10;
	abc->m_B = 20;
	cout << "+: " << abc->getResult() << endl;//-10
	delete abc;

	abc = new MulCalculator;
	abc->m_A = 10;
	abc->m_B = 20;
	cout << "+: " << abc->getResult() << endl;//200
	delete abc;

	abc = new DivCalculator;
	abc->m_A = 100;
	abc->m_B = 20;
	cout << "+: " << abc->getResult() << endl;//5
	delete abc;

}

int main() {
	test01();
	system("pause");
	return 0;
}
