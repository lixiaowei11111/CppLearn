#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;


//2. ���� Student�ṹ��
struct Stu {
	string sName;
	int score;
};

// 1. ���� Teacher�ṹ��
struct Teacher {
	string tName;
	struct Stu stuArr[5];
};

// 4. ���� �� �ṹ���Ա��ֵ�ĺ���
void allocateSpace(struct Teacher tArray[], int len);

// 5. ������ӡ������ memberd��value�ĺ���
void printInfo(struct Teacher tArray[], int len);


int main7() {
	srand((unsigned)time(NULL));// ���������
	//3. ����Teacher �Ľṹ������ 
	struct Teacher teacherArr[3];
	int length = sizeof(teacherArr) / sizeof(teacherArr[0]);

	//8. ���� ��ֵ����
	allocateSpace(teacherArr, length);

	//9.���� ��ӡ����
	printInfo(teacherArr, length);
	system("pause");
	return 0;
}

// 6. ���帳ֵ����
void allocateSpace(Teacher tArray[], int len) {

	string nameSeed = "ABCDE";
	string tName = "Teacher_";
	string sName = "Student_";
	for (int i = 0; i < len; i++)
	{
		tArray[i].tName = tName + nameSeed[i];
		for (int j = 0; j < 5; j++) {
			tArray[i].stuArr[j].sName = sName + nameSeed[j];
			tArray[i].stuArr[j].score = 40 + rand() % 61;
		}
	}
}

// 7. ���� ��ӡ��Ϣ�ĺ���
void printInfo(Teacher tArray[], int len) {
	for (int i = 0; i < len; i++)
	{
		cout << "��ʦ������: " << tArray[i].tName << "\n" << "\n\tѧ��: ";
		for (int j = 0; j < 5; j++) {
			cout << "ѧ������: " << tArray[i].stuArr[j].sName << "ѧ������" << tArray[i].stuArr[j].score << endl;
		}
		cout << endl;
	}
	return;
}