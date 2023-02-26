//
// Created by lxw on 2023/2/26.
//


#include <iostream>
#include "016_subfile_person.hpp"

using std::cout;
using std::endl;
using std::string;

void test01(){
    Person<string,int>p1("张撒比22",32);
    p1.showInfo();
};
// 2.导入class template时, 因为方法只会在调用时才会创建,所以不能直接导入.h声明文件
// 第一种拆开方法, 将其拆开并引入cpp,而不是.h文件, 文件 Person.h, Person.cpp


int main() {
    test01();
    system("pause");
    return 0;
}

