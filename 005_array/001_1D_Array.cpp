#include<iostream>

using namespace std;

int main1() {
	// 1.�����ʼ������ ��ʽ1
	double array1[10];

	//2. ����ĳ�ʼ�� ��ʽ2
	double array2[] = { 1,2,3,4,5,6,7 };
	cout << "����arrayռ��1���ڴ�ռ�δ:" << sizeof(array2)<<"byte" << array2 << endl;

	// 3. ����ĳ�ʼ�� ��ʽ3
	double array3[3] = { 1,2,3 };

	// 4. ��ȡ�ַ������ȵķ��� strlen(char)
	 char char1[] ="adadadsaddada";
	 cout << "use strlen function get string length is :" << strlen(char1);//13

	 // 5. ��ȡ�������͵ķ���
	 string array4[] = { "1","2","3","4" };
	 cout << "string ���������ռ���ڴ�ռ��СΪ" << sizeof(array4) << "\n" << sizeof(string) << endl;


	 // 6. c++ �м�������ĳ���, ����sizeof
	 for (int i = 0; i < sizeof(array4) / sizeof(array4[0]); i++) {
		 cout << array4[i]<<array4 << endl;
	 }


	 // 7. sizeof ��ȡ array�ڵ�ַ�г���
	 double array5[] = { 1,2,3,4,5,6,7 };
	 int a = sizeof(array5); // array5��������ĳ���
	 int b = sizeof(array5[0]); // ���鵥��Ԫ�صĳ���,Ҳ������array5[1]�����
	 int b1 = sizeof(array5[1]);
	 cout << "array5�����鳤��Ϊ:" << (a / b) << endl;// 7
	 cout << "array5����ĳ���Ϊ" << (a / b1) << endl;// 7

	system("pause");
	return 0;
}