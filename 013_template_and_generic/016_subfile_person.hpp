#pragma once
#include <iostream>
using std::cout;
using std::endl;
using std::string;

template<typename T,typename  K>
class Person{
public:
    T n_Name;
    K n_Age;
    Person(T name,K age);
    void showInfo();


};

// 1. 类外实现成员函数
template <typename T,typename K>
Person<T,K>::Person(T name,K age){
    this->n_Name=name;
    this->n_Age=age;
};

template <typename T,typename K>
void Person<T, K>::showInfo() {
    cout<<"name is :"<<this->n_Name<<endl;
    cout<<"age is :"<<this->n_Age<<endl;
};