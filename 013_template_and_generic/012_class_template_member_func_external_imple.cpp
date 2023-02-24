//
// Created by lxw on 2023/2/24.
//


#include <iostream>

using std::cout;
using std::endl;
using std::string;

// 类模板 成员函数 在 类外部的实现
template<typename T,typename K>
class Person{
public:
    T n_Name;
    K n_Age;
    Person(T name,K age);// 构造函数内部声明, 外部实现
    void showInfo(); // 普通成员类内声明, 外部实现
};

// 1. 构造函数的外部定义实现
template<typename T, typename K>
Person<T,K>::Person(T name,K age){
    this->n_Age=age;
    this->n_Name=name;
};

// 2. 普通函数的外部定义实现
template<typename T,typename K>
void Person<T,K>::showInfo() {
    cout<<"name is : "<<this->n_Name<<endl;
    cout<<"age is : "<<this->n_Age<<endl;
}

void test01(){
    Person<string ,int>p1("张三",22);
    p1.showInfo();
};
int main() {
    test01();
    system("pause");
    return 0;
}