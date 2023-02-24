//
// Created by lxw on 2023/2/24.
//


#include <iostream>
#include <cxxabi.h>

using std::cout;
using std::endl;
using std::string;
using abi::__cxa_demangle; // gcc 编译器中 完整输出类型

// class template
/**
* 当类模板碰到继承时，需要注意一下几点：
* 当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中T的类型
* 如果不指定，编译器无法给子类分配内存
* 如果想灵活指定出父类中T的类型，子类也需变为类模板
*/
template<typename T>
class Father{
    T n_Age;
};

// 1. 子类继承父类, 父类为class template 可以声明类型, 来分配内存
class SonA: public Father<int>{

};
void test01(){
    SonA s1;
};

// 2. 子类继承父类 如果想灵活指定出父类中T的类型，子类也需变为类模板
template<typename T,typename K>
class SonB:public Father<T>{
public:
    SonB(){
        cout<<"T的类型是: "<<__cxa_demangle(typeid(T).name(),0,0,0)<<endl;
        // T的类型是: std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >
        cout<<"K的类型是: "<<__cxa_demangle(typeid(K).name(),0,0,0)<<endl;
        //K的类型是: int
    };
};
void test02(){
    SonB<string,int>sb;
};
int main() {
    test01();
    test02();
    system("pause");
    return 0;
}