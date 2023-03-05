//
// Created by lxw on 2023/3/5.
//


#include <iostream>

using std::cout;
using std::endl;
using std::string;

/**
 * string& insert(int pos, const char* s);//插入字符串
 * string& insert(int pos, const string& str);//插入字符串
 * string& insert(int pos, int n, char c);//在指定位置插入n个字符c
 * string& erase(int pos, int n = npos);//删除从Pos开始的n个字符
 * */

int main() {
    string s="hello";
    const char* s2="world";
    string s1=s.insert(5,s2);
    cout<<s1<<endl;// helloworld

    // 会改变原数组
    string s3=s.insert(6,s2);
    cout<<s3<<endl;// hellowworldorld

    //如果超出字符串的长度,会报错,而不会自动补位空格
    string s5="hello";
    //string s4=s5.insert(6,s2);//terminate called after throwing an instance of 'std::out_of_range'
                                     //what():  basic_string::replace: __pos (which is 6) > this->size() (which is 5)
    //cout<<s4<<endl;//

    string s6="hello";
    string s7=s6.insert(1,10,'y');
    cout<<s6<<endl;// hyyyyyyyyyyello

    s6.erase(1,10);
    cout<<s6<<endl;// hello

    system("pause");
    return 0;
}