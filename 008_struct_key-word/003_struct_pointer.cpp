#include<iostream>


using namespace std;

// 1. ����ṹ��
struct Student {
	string name; //����
	int age;//����
	int score;// ���� // ����д�Ļ�,������һ��,Ĭ��
}; 

int main3() {
	// 1. ����ѧ���ṹ�����,     ��������ʱ struct�ɺ���, ����ʱ����Ҫд
	struct Student Stu1 = {"����",32,90};

	// 2. ����ָ����� ָ��õ�ַ
	Student* p = &Stu1;

	// 3.ָ����� ���� �ṹ���Ա, ͨ�� -> ����
	cout << "  ����: " << p->name << "  ����: " << p->age << "  ����: " << p->score << endl;



	return 0;
}