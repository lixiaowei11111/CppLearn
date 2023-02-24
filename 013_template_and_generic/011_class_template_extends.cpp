//
// Created by lxw on 2023/2/24.
//


#include <iostream>
#include <cxxabi.h>

using std::cout;
using std::endl;
using std::string;
using abi::__cxa_demangle; // gcc �������� �����������

// class template
/**
* ����ģ�������̳�ʱ����Ҫע��һ�¼��㣺
* ������̳еĸ�����һ����ģ��ʱ��������������ʱ��Ҫָ����������T������
* �����ָ�����������޷�����������ڴ�
* ��������ָ����������T�����ͣ�����Ҳ���Ϊ��ģ��
*/
template<typename T>
class Father{
    T n_Age;
};

// 1. ����̳и���, ����Ϊclass template ������������, �������ڴ�
class SonA: public Father<int>{

};
void test01(){
    SonA s1;
};

// 2. ����̳и��� ��������ָ����������T�����ͣ�����Ҳ���Ϊ��ģ��
template<typename T,typename K>
class SonB:public Father<T>{
public:
    SonB(){
        cout<<"T��������: "<<__cxa_demangle(typeid(T).name(),0,0,0)<<endl;
        // T��������: std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >
        cout<<"K��������: "<<__cxa_demangle(typeid(K).name(),0,0,0)<<endl;
        //K��������: int
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