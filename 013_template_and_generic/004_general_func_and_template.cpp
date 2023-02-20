//
// Created by lxw on 2023/2/20.
//

#include <iostream>

using std::cout;
using std::endl;
using std::string;
// 普通函数和函数模板的区别
// 1. 普通函数自动调用 隐式转换
// 2. 模板函数,
// 2.1 模板函数中利用自动类型推导, 则不会发生隐式转换
// 2.2 模板函数显式的制定类型,可以发生隐式转换

// 1. 普通函数
int add(int a,int b){
    return a+b;
}
// 2. 模板函数,自动类型推导
template<typename T>
T autoTypeAdd(T a,T b){
    return  a+b;
}

void test01(){
    int a=10;
    int b=20;
    char c='c';
    cout<<add(a,c)<<endl;// 109
    cout<<c<<int(c)<<endl;
    // 不采用引用,则在函数参数给其赋值时 b=int(c)=99,自动进行隐式转换,用引用则不行
    // cout<<autoTypeAdd(a,c);// error 自动类型推导时,模板函数不进行隐式转换
    cout<<autoTypeAdd<int>(a,c);//109 显式制定类型为int, 则和普通函数add一样
}

int main() {
    test01();
    system("pause");
    return 0;
}