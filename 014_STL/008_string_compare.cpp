//
// Created by lxw on 2023/3/5.
//


#include <iostream>

using std::cout;
using std::endl;
using std::string;

//�ַ����Ƚ��ǰ��ַ���ASCII����жԱ�
//= ����   0
//> ����   1
//< ����  -1
void strCompare(const string &s1,const string &s2){
    int flag=s1.compare(s2);
    if(flag==0){
        cout<<"s1����s2"<<endl;
    }else if(flag==1||flag==-1){
        cout<<"s1������s2"<<endl;
    }
}

int main() {
    const char* s1 ="ybb";
    string s2="Ybb";
    strCompare(s1,s2);// s1 ������s2

    // ���ı���֧�ֶ�
    const char* s3="�Ļ���?";
    const string s4="�Ļ���?";
    strCompare(s3,s4);// s1 ����s2
    system("pause");
    return 0;
}