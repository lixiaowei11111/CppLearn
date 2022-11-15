#include <iostream>

using std::cout;
using std::endl;
using std::string;


// ��̬ ���� ����ԭ��, ��ȥ�޸��ϴ���, ���ϴ���Ļ����Ͻ��п���

// ���� һ�� ��̬ ����һ��������չ�Եļ�����,ʵ�� ���͵���������

// 1.ʵ��һ���������ĳ�����
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
	// ��д�����е� �麯��, ��Ҫ�� ����ָ���ָ����Ϊ ��Ӧ������ʵ����ַ,�ﵽ��̬�Ժ������к����ĵ�ַ��ֵ
	abc->m_A = 10;
	abc->m_B = 20;
	cout <<"+: " << abc->getResult() << endl;//30

	delete abc;// ���add

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
