//
// Created by lxw on 2023/2/22.
//


#include <iostream>

using std::cout;
using std::endl;
using std::string;

// 普通类的 成员函数,会在 类初始化时,就创建
// 类模板中的成员函数,会在调用时才会创建
class Person{
public:
    void showPerson(){
        cout<<"showPerson func "<<endl;
    };
};

class Animal{
    void showAnimal(){
        cout<<"showAnimal func "<<endl;
    };
};

template<typename T>
class Execute{
public:
    T obj;

    void func1(){
        obj.showPerson();
    };
    void func2(){
        obj.showAnimal();
    };
};
void test01(){
    Execute<Person> e;
    e.func1();// showPerson func
    //e.func2();// error: 'class Person' has no member named 'showAnimal'
}

int main() {
    test01();
    system("pause");
    return 0;
}