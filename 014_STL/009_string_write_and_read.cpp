//
// Created by lxw on 2023/3/5.
//


#include <iostream>

using std::cout;
using std::endl;
using std::string;

/**
 * string�е����ַ���ȡ��ʽ������
 * char& operator[](int n);//ͨ��[]��ʽȡ�ַ�
 * char& at(int n);//ͨ��at������ȡ�ַ�
 * */

int main() {
    // const char* s="abcdefg"; s.zie() ��
    string s="abcdefg";//s.size() ��
    for (int i = 0; i < s.size(); ++i) {
        cout<<"s["<<i<<"]"<<s[i]<<endl;
        cout<<"s.at("<<i<<")"<<s.at(i)<<endl;
    }
    s[1]='x';
    cout<<s<<endl;
    system("pause");
    return 0;
}