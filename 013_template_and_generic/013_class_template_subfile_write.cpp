//
// Created by lxw on 2023/2/26.
//


#include <iostream>

using std::cout;
using std::endl;
using std::string;
// 类模板的分文件编写

// 原来的编写
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
void test01(){
    Person<string,int>p1("张安",23);
    p1.showInfo();
};
// 2.导入class template时, 因为方法只会在调用时才会创建,所以不能直接导入.h声明文件
// 第一种拆开方法, 将其拆开并引入cpp,而不是.h文件, 文件 Person.h, Person.cpp


int main() {
    test01();
    system("pause");
    return 0;
}