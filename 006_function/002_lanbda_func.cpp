#include<iostream>


using namespace std;


// ��ǰ������������,  ���������ж��,���� �ж��
void addFun(int param1, int param2);


int main2() {
	
	addFun(2000,10); //2000 10


	// lambda (��ͷ����)
	/*a = [](int x, int y)->int {int z = x + y; return z; };*/
	system("pause");
	return 0;
}


//1. Ĭ�ϲ���
//void addFun(int param1=20, int param2) { // Ĭ��ʵ�β����β��б�Ľ�β
void addFun(int param1, int param2 = 20) {
	cout << "param1:" << param1 << "\t" << "��Ĭ��ֵparam2:" << param2 << endl;
};