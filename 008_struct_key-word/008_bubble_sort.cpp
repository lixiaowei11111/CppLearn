#include<iostream>


//using namespace std;
using std::string;
using std::cout;
using std::endl;

// 1.���� Ӣ�� �ṹ��
struct Hero {
	string name;
	int age;
	string sex;
};


// 3. ����¼����Ϣ�ĺ���
void importInfo(Hero heroArr[], int length);
int main() {
	// 2. ����Ӣ�۽ṹ�� �������
	Hero heroArr[5] = {
		{"����",23,"��"},
		{"����",22,"��"},
		{"�ŷ�",20,"��"},
		{"����",21,"��"},
		{"����",19,"Ů"},
	};
	int len = sizeof(heroArr) / sizeof(heroArr[0]);
	importInfo(heroArr,len);
	system("pause");
	return 0;
}

// 4. ���嵼����Ϣ�ĺ���, ����ð������
void importInfo(Hero heroArr[], int length) {
	for (size_t i = 0; i < length-1; i++)
	{
		for (size_t j = 0; j < length-i - 1; j++)
		{
			if (heroArr[j].age > heroArr[j + 1].age) {
				Hero temp = heroArr[j + 1];
				heroArr[j + 1] = heroArr[j];
				heroArr[j] = temp;
			}
		}
	}
	for (size_t i = 0; i < length; i++)
	{
		cout << "����: " << heroArr[i].name << "\t ����: " << heroArr[i].age << "\t�Ա�: " << heroArr[i].sex << endl;
	}
}