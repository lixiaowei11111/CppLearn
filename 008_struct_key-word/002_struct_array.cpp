#include<iostream>


using namespace std;

// 1. ����ṹ��
struct student {
	string name; //����
	int age;//����
	int score;// ����
}; // �ṹ�����������ʽ3

int main2() {
	
	// 2.�����ṹ�����������
	student stuArr[3] = { {"����",32,90},{"����",12,40},{"����",23,87} };

	// 3. ���ṹ�������е�Ԫ�ظ�ֵ
	stuArr[2].name = "����";
	stuArr[2].age = 88;
	stuArr[2].score = 100;

	// 4.�����ṹ���е�����
	int length = sizeof(stuArr) / sizeof(stuArr[0]);

	for (size_t i = 0; i < length; i++)
	{
		cout << stuArr[i].name << "\t" << stuArr[i].age << "\t" << stuArr[i].score << "\t" << endl;
	}
	return 0;
}