//
// Created by lxw on 2023/2/28.
//


#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::cerr;

double division(int a, int b)
{
    if( b == 0 )
    {
        throw "Division by zero condition!";
    }
    return (a/b);
}

void test01(){
    try {
        int a=1;
        int b=0;
        division(a,b);
        // 保护代码
    }catch(const char* msg){
        // catch 块
        cerr<<msg<<endl;// Division by zero condition!
    }

};

int main() {
    test01();
    system("pause");
    return 0;
}