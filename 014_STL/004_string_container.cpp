//
// Created by lxw on 2023/3/2.
//


#include <iostream>

using std::cout;
using std::endl;
using std::string;

/*
* string();          	     创建一个空的字符串 例如: string str;
* string(const char* s);	 使用字符串s初始化
* string(const string& str); 使用一个string对象初始化另一个string对象
* string(int n, char c);     使用n个字符c初始化
*/
void test01(){
    string str;

    char* s1="hello world";
    string s2(s1);
    cout<<s2<<endl;
    string s3(s2);
    cout<<"s3: "<<s3<<endl;
    string s4(10,'a');
    cout<<"s4: "<<s4<<endl;
};

int main(){
    test01();
   system("pause");
    return 0;
}