//
// Created by lxw on 2023/2/20.
//

#include <iostream>

using std::cout;
using std::endl;
using std::string;

// 函数模板 和 同名普通函数的调用规则
// 1.如果函数模板和普通函数都可以调用,则优先调用 普通函数
    // 注意 如果同名普通函数只有声明,没有定义,则编译器还是会调用 同名普通函数,并且会报错该函数未定义
// 2. 强制调用模板函数: 通过空模板参数列表来调用<>
// 3. 函数模板也可以发生重载
// 4. 如果函数模板可以产生更好的匹配,优先调用函数模板

template<class T>
// 同名模板函数
void myPrint(T a,T b){
    cout<<"模板函数调用"<<endl;
};


void myPrint(int a,int b){
    cout<<"普通函数调用"<<endl;
}

// 函数模板重载
template<class T>
void myPrint(T a,T b,T c){
    cout<<"调用重载函数模板"<<endl;
};


void test01(){
    int a=10;
    int b=20;
    int c=30;
    myPrint(a,b);// 普通同名函数调用
    myPrint<>(a,b);// 模板函数调用 使用空模板参数列表来强制调用 模板函数
    myPrint(a,b,c);// 调用重载函数模板 函数模板发生的重载

    char d='d';
    char e='e';
    myPrint(d,e);//模板函数调用 普通同名函数可以发生隐式转换, 但编译器会优先调用 模板函数
}


int main() {
    test01();
    system("pause");
    return 0;
}