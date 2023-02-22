//
// Created by lxw on 2023/2/22.
//


#include <iostream>

using std::cout;
using std::endl;
using std::string;

// 类模板 和 函数模板的两点区别
// 1. 类模板不能进行自动类型推导
// 2. 类模板在模板参数列表中可以有默认参数

template<typename T,class K>
class Person{
public:
    Person(T name,K age){
        this->m_Name=name;
        this->m_Age=age;
    };

    T m_Name;
    K m_Age;
};

// 类模板在模板参数列表中可以有默认值 <>里面的就是模板函数中的参数列表
template<typename T=string,typename K = int>
class Animal{
public:
    Animal(T name,K age){
        this->m_Name=name;
        this->m_Age=age;
    };
    T m_Name;
    K m_Age;
};

void test01(){
//    Person p1('张三',12);//Error 类模板 不能像函数模板一样进行自动类型推导, 因为函数模板的类型推导其实是类似于强制类型转换
    Person<string,int>p1("张三",12);
    // 默认参数列表的类模板
   Animal<>a1("张三",23);
}
int main() {
    test01();
    system("pause");
    return 0;
}