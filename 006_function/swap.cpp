// ���ñ���Ŀ¼��ͷ�ļ�ʱ, ʹ��˫����
#include "swap.h"



void swap(int num1, int param2) {
	int temp = param2;
	param2 = num1;
	num1 = temp;
	cout << "��һ��������ֵ��������Ϊ" << num1 << "\n" << "�ڶ���������ֵ������Ϊ:" << param2 << endl;
}