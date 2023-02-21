//
// Created by lxw on 2023/2/21.
//


#include <iostream>

using std::cout;
using std::endl;
using std::string;

// class template 基础语法
template<typename T,class K>
class Person{
public:
    T m_Name;
    K m_Age;
    Person(T name,K age){
        // has params constructor function
        this->m_Name=name;
        this->m_Age=age;
    }
    void showPersonInfo(){
        cout<<"name:"<<this->m_Name<<endl;
        cout<<"age:"<<this->m_Age<<endl;
    };


};

void test01(){
    Person<string,int>p1("张三",23);
    p1.showPersonInfo();
};

int main() {
    test01();
    system("pause");
    return 0;
}