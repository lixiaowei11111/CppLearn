#include <iostream>
#include <ctime>

using namespace std;

// ��д����ʱӦϰ���Ե�������������Ȼ���ڶ��庯��
void getSeconds(unsigned long* par);

int main9()
{
	unsigned long sec;


	getSeconds(&sec);

	// ���ʵ��ֵ
	cout << "Number of seconds :" << sec << endl;

	return 0;
}

void getSeconds(unsigned long* par)
{
	// ��ȡ��ǰ������
	*par = time(NULL);
	return;
}