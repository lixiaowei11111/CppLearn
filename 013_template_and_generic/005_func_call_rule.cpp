//
// Created by lxw on 2023/2/20.
//

#include <iostream>

using std::cout;
using std::endl;
using std::string;

// ����ģ�� �� ͬ����ͨ�����ĵ��ù���
// 1.�������ģ�����ͨ���������Ե���,�����ȵ��� ��ͨ����
    // ע�� ���ͬ����ͨ����ֻ������,û�ж���,����������ǻ���� ͬ����ͨ����,���һᱨ��ú���δ����
// 2. ǿ�Ƶ���ģ�庯��: ͨ����ģ������б�������<>
// 3. ����ģ��Ҳ���Է�������
// 4. �������ģ����Բ������õ�ƥ��,���ȵ��ú���ģ��

template<class T>
// ͬ��ģ�庯��
void myPrint(T a,T b){
    cout<<"ģ�庯������"<<endl;
};


void myPrint(int a,int b){
    cout<<"��ͨ��������"<<endl;
}

// ����ģ������
template<class T>
void myPrint(T a,T b,T c){
    cout<<"�������غ���ģ��"<<endl;
};


void test01(){
    int a=10;
    int b=20;
    int c=30;
    myPrint(a,b);// ��ͨͬ����������
    myPrint<>(a,b);// ģ�庯������ ʹ�ÿ�ģ������б���ǿ�Ƶ��� ģ�庯��
    myPrint(a,b,c);// �������غ���ģ�� ����ģ�巢��������

    char d='d';
    char e='e';
    myPrint(d,e);//ģ�庯������ ��ͨͬ���������Է�����ʽת��, �������������ȵ��� ģ�庯��
}


int main() {
    test01();
    system("pause");
    return 0;
}