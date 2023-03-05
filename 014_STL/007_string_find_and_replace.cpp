//
// Created by lxw on 2023/3/5.
//


#include <iostream>

using std::cout;
using std::endl;
using std::string;

//`int find(const string& str, int pos = 0) const;`              //查找str第一次出现位置,从pos开始查找
//`int find(const char* s, int pos = 0) const;`                     //查找s第一次出现位置,从pos开始查找
//`int find(const char* s, int pos, int n) const;`               //从pos位置查找s的前n个字符第一次位置
//`int find(const char c, int pos = 0) const;`                       //查找字符c第一次出现位置
//`int rfind(const string& str, int pos = npos) const;`      //查找str最后一次位置,从pos开始查找
//`int rfind(const char* s, int pos = npos) const;`              //查找s最后一次出现位置,从pos开始查找
//`int rfind(const char* s, int pos, int n) const;`              //从pos查找s的前n个字符最后一次位置
//`int rfind(const char c, int pos = 0) const;`                      //查找字符c最后一次出现位置
//`string& replace(int pos, int n, const string& str);`       //替换从pos开始n个字符为字符串str
//`string& replace(int pos, int n,const char* s);`                 //替换从pos开始的n个字符为字符串s

void test(){
    string s="this is a sentence";
    string target="is";
    string no_exist_str="ybb";
    int positionA=s.find(target);
    cout<<positionA<<endl;// 2
    int positionB=s.find(no_exist_str);
    cout<<positionB<<endl;// -1 字符串不存在
    int positionC=s.find(target,3);
    cout<<positionC<<endl;// 5
    int positionD=s.rfind("e");
    cout<<positionD<<endl;// 17
    string s1=s.replace(0,17,"bb bb");
    cout<<s1<<endl;// bb bbe
};

int main() {
    test();
    system("pause");
    return 0;
}