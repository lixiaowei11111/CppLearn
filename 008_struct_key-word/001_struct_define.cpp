#include<iostream>


using namespace std;

// 1. ����ṹ��
struct student {
	string name; //����
	int age;//����
	int score;// ����
} stu3; // �ṹ�����������ʽ3

int main1() {
	// 1. �ṹ�����������ʽ1
	student stu1;
	stu1.name = "����";
	stu1.age = 32;
	stu1.score = 89;

	cout << stu1.name << stu1.age << stu1.score << endl;

	// 2. �ṹ�����������ʽ2
	student stu2 = { "����",24,78 };
	cout << stu2.name << stu2.age << stu2.score << endl;


	// 3.����ṹ���ʱ��,˳�㶨�����
	stu3.name = "����";
	stu3.age = 22;
	stu3.score = 80;

	cout << stu3.name << stu3.age << stu3.score << endl;

	return 0;
}