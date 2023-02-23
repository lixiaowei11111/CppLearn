//
// Created by lxw on 2023/2/23.
//


#include <iostream>
#include <cxxabi.h>
using std::cout;
using std::endl;
using std::string;

// 类模板 实例化出的对象, 作为函数参数的三种形式
/**
 *1. 指定传入的类型  --- 直接显示对象的数据类型
 *2. 参数模板化     --- 将对象中的参数变为模板进行传递
 *3. 整个类模板化   --- 将这个对象类型 模板化进行传递
 */

template<typename T,typename K=int>
class Person{
public:
    T m_Name;
    K m_Age;
    Person(T name,K age){
        this->m_Name=name;
        this->m_Age=age;
    };
    void showPersonInfo(){
        cout<<"name: "<<this->m_Name<<endl;
        cout<<"age: "<<this->m_Age<<endl;
    };

};
// 1. 指定传入的类型   --- 直接显示对象的数据类型
void showInfoA(Person<string ,int> p){
    p.showPersonInfo();
};
void test01(){
    Person<string>p("张三",18);
    showInfoA(p);
};

// 2. 参数模板化     --- 将对象中的参数变为模板进行传递
template<typename T1=string,typename T2=int>
void showInfoB(Person<T1 ,T2> p){
    p.showPersonInfo();
    cout<<"T type is:"<<(abi::__cxa_demangle(typeid(T1).name(),0,0,0))<<endl;
    //  std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >
    cout<<"K type is:"<<(abi::__cxa_demangle(typeid(T2).name(),0,0,0))<<endl;//int
};

void test02(){
    Person<string>p("张三",18);
    showInfoB(p);
}
// 3. 整个类模板化   --- 将这个对象类型 模板化进行传递
template <class T>
void showInfoC(T& p){
    p.showPersonInfo();
    cout<<"T type is : "<<(abi::__cxa_demangle(typeid(T).name(),0,0,0))<<endl;
    // Person<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, int>
};

void test03(){
    Person<string>p("王五",29);
    showInfoC(p);
}

int main() {
    test01();
    test02();
    test03();
    system("pause");
    return 0;
}