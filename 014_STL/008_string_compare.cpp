//
// Created by lxw on 2023/3/5.
//


#include <iostream>

using std::cout;
using std::endl;
using std::string;

//字符串比较是按字符的ASCII码进行对比
//= 返回   0
//> 返回   1
//< 返回  -1
void strCompare(const string &s1,const string &s2){
    int flag=s1.compare(s2);
    if(flag==0){
        cout<<"s1等于s2"<<endl;
    }else if(flag==1||flag==-1){
        cout<<"s1不等于s2"<<endl;
    }
}

int main() {
    const char* s1 ="ybb";
    string s2="Ybb";
    strCompare(s1,s2);// s1 不等于s2

    // 中文表情支持度
    const char* s3="文化人?";
    const string s4="文化人?";
    strCompare(s3,s4);// s1 等于s2
    system("pause");
    return 0;
}