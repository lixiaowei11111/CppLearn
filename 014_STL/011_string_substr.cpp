//
// Created by lxw on 2023/3/5.
//


#include <iostream>

using std::cout;
using std::endl;
using std::string;

// string substr(int pos = 0, int n = npos) const; //返回由pos开始的n个字符组成的字符串

int main() {
    // 不会改变原数组?
    string s="hello";
    string s1=s.substr(1,3);
    cout<<s1<<endl;// ell
    cout<<s<<endl;// hello

    string email="hello@163.com";
    int pos=email.find('@');
    string s2=email.substr(0,pos);
    cout<<s2<<endl;// hello
    system("pause");
    return 0;
}