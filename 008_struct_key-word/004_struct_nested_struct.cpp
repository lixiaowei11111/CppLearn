#include<iostream>


using namespace std;

// 1. ����ṹ��, �ȶ��� Tool
struct Tool {
	int countPencil;//����
};

// 2. ����Teacher �ṹ��
struct Teacher {
	string name;
	int age;
	//struct Student { // �ṹ�����涨�� һ���ṹ�� �ǷǷ���!
	//	string name; //����
	//	int age;//����
	//	int score;// ���� // ����д�Ļ�,������һ��,Ĭ��
	//};
	Tool tool; // ����һ���ṹ�����, ��Ϊһ���ṹ��, �Ϸ���
};



int main4() {
	// 3. ����Teacher�ṹ�����
	Teacher teacher;
	teacher.name = "������";
	teacher.age = 108;
	teacher.tool.countPencil = 20;

	// 4. ����ָ�����, ָ��� �ṹ�����teacher
	Teacher* p = &teacher;

	// 5. ָ����ʳ�Ա
	cout << "teacher�µ�tool��count: " << p->tool.countPencil << endl;// 20 ��������



	return 0;
}