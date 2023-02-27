//
// Created by lxw on 2023/2/27.
//


#include <iostream>

using std::cout;
using std::endl;
using std::string;

// 第一个命名空间
namespace first_space{
    void func(){
        cout<<"namespace is first_space"<<endl;
    }
    namespace  first_space_son{
        void func(){
            cout<<"namespace is first_space"<<endl;
        }

    }
}
// 第二个命名空间
namespace second_space{
    void func(){
        cout<<"namespace is second_space"<<endl;
    }
}
void test01(){
    first_space::func();// 调用第一个命名空间中的函数
    second_space::func();// 调用第二个命名空间中的函数
};
using namespace first_space;
using namespace first_space::first_space_son;

void test02(){
    first_space::func();// namespace is first_space
}

int main() {
    test01();
    test02();
    system("pause");
    return 0;
}