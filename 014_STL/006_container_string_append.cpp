//
// Created by lxw on 2023/3/3.
//


#include <iostream>

using std::cout;
using std::endl;
using std::string;

//`string& operator+=(const char* str);`                   //重载+=操作符
//
//`string& operator+=(const char c);`                         //重载+=操作符
//
//`string& operator+=(const string& str);`                //重载+=操作符
//
//`string& append(const char *s); `                               //把字符串s连接到当前字符串结尾
//
//`string& append(const char *s, int n);`                 //把字符串s的前n个字符连接到当前字符串结尾
//
//`string& append(const string &s);`                           //同operator+=(const string& str)
//
//`string& append(const string &s, int pos, int n);`//字符串s中从pos开始的n个字符连接到字符串结尾


void test01(){
    const char* s="this is a sentence";
    string s1("s1: ");
    s1=s1+s;
    cout<<s1<<endl;// s1: this is a sentence
    char c='a';
    string s2="2: ";
    s2=s2+c;
    cout<<s2<<endl;// 2: a
    string s3="s3: ";
    s3=s3+s1;
    cout<<s3<<endl;// s3: s1: this is a sentence
    string s4="s4 :";
    s4.append(s);
    cout<<s4<<endl;// s4 :this is a sentence
    string s5("s5: ");
    s5.append(s,7);
    cout<<s5<<endl;// s5: this is
    string s6="s6: ";
    s6.append(s5);
    cout<<s6<<endl;// s6: s5: this is
    string s7("s7: ");
    s7.append(s,1,5);
    cout<<s7<<endl;// s7: his i
};

int main() {
    test01();
    system("pause");
    return 0;
}