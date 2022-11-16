#include <iostream>

using std::cout;
using std::endl;
using std::string;

//  CPU ,�Կ�, �ڴ����ĳ�����, �ֱ�ʵ��class ���麯��

class CPU {
public:
	virtual void calculate() = 0;

};

class GraphCard {
public:
	virtual void display() = 0;

};

class MemoryBlock {
public:
	virtual void storage() = 0;
};

// ����, �ṩ��������
class Computer {
public:
	Computer(CPU* cpu,GraphCard* gc,MemoryBlock* mb) {
		m_cpu = cpu;
		m_gc = gc;
		m_mb = mb;

	}
	void work() {
		m_cpu->calculate();
		m_gc->display();
		m_mb->storage();
	}
	~Computer() {
		if (m_cpu != NULL) {
			delete m_cpu;
		}
		if (m_gc != NULL) {
			delete m_gc;
		}
		if (m_mb != NULL) {
			delete m_mb;
		}
		cout << "Computer destructor func execute" << endl;
	}

private:
	CPU* m_cpu;
	GraphCard* m_gc;
	MemoryBlock* m_mb;
};

// Intel CPU ������
class IntelCPU :public CPU {
public:
	virtual void calculate() {
		cout << "Intel CPU has run" << endl;
	}
};

// Amd CPU ������
class AmdCPU :public CPU {
public:
	virtual void calculate() {
		cout << "Amd CPU has run" << endl;
	}
};

// Nvidia GPU ������
class NvidiaGPU :public GraphCard {
public:
	virtual void display() {
		cout << "NvidiaGPU has run" << endl;
	}
};

// AMD GPU ������
class AmdGPU :public GraphCard {
public:
	virtual void display() {
		cout << "AmdGPU has run" << endl;
	}
};

// Samsung Memory Block ������
class SamsungMemoryBlock :public MemoryBlock{
public:
	 void storage () {
		cout << "Samsung MemoryBlock has storage" << endl;
	}
};

// ZhiTai Memory Block ������
class ZhiTaiMemoryBlock :public MemoryBlock {
public:
	void storage() {
		cout << "ZhiTai MemoryBlock has storage" << endl;
	}
};

void test01() {
	CPU* cpu = new IntelCPU;
	GraphCard* gc = new AmdGPU;
	MemoryBlock* mb = new SamsungMemoryBlock;

	Computer* c = new Computer(cpu, gc, mb);
	c->work();
}

int main() {
	test01();
	system("pause");
	return 0;
}
