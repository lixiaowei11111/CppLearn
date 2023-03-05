//
// Created by lxw on 2023/3/5.
//


#include <iostream>

using std::cout;
using std::endl;
using std::string;

/**
 * string中单个字符存取方式有两种
 * char& operator[](int n);//通过[]方式取字符
 * char& at(int n);//通过at方法获取字符
 * */

int main() {
    // const char* s="abcdefg"; s.zie() ×
    string s="abcdefg";//s.size() √
    for (int i = 0; i < s.size(); ++i) {
        cout<<"s["<<i<<"]"<<s[i]<<endl;
        cout<<"s.at("<<i<<")"<<s.at(i)<<endl;
    }
    s[1]='x';
    cout<<s<<endl;
    system("pause");
    return 0;
}