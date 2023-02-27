//
// Created by lxw on 2023/2/27.
//


#include <iostream>

using std::cout;
using std::endl;
using std::string;

// class template 声明友元函数
// 1. 全局函数做友元函数, class 内实现
// 2. 全局函数做友元函数, class 外实现

// class 内外实现, 要先声明 class
template<typename T,typename K>
class Person;

template<typename T,typename K>
void printInfo(Person<T,K>& p){
    cout<<"name :"<<p.m_Name<<endl;
    cout<<"age :"<<p.m_Age<<endl;
}

template<typename T,typename K>
class Person{
    // 1.友元函数 class 内实现
    friend void showInfo(Person<T,K>* p){
        cout<<"name :"<<p->m_Name<<endl;
        cout<<"age :"<<p->m_Age<<endl;
    };
    friend void printInfo<>(Person<T,K>& p);
public:
    T m_Name;
    K m_Age;
    Person(T name,K age){
        this->m_Name=name;
        this->m_Age=age;
    };

};
// class 内实现
void test01(){
    Person<string,int>* p=new Person<string,int>("张三",34);
    showInfo(p);
};
// 2. class 外实现;
void test02(){
    Person<string,int>p("张天时",24);
    printInfo(p);
};

int main() {
    test01();
    test02();
    system("pause");
    return 0;
}