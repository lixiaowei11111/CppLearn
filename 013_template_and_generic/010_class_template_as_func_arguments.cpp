//
// Created by lxw on 2023/2/23.
//


#include <iostream>
#include <cxxabi.h>
using std::cout;
using std::endl;
using std::string;

// ��ģ�� ʵ�������Ķ���, ��Ϊ����������������ʽ
/**
 *1. ָ�����������  --- ֱ����ʾ�������������
 *2. ����ģ�廯     --- �������еĲ�����Ϊģ����д���
 *3. ������ģ�廯   --- ������������� ģ�廯���д���
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
// 1. ָ�����������   --- ֱ����ʾ�������������
void showInfoA(Person<string ,int> p){
    p.showPersonInfo();
};
void test01(){
    Person<string>p("����",18);
    showInfoA(p);
};

// 2. ����ģ�廯     --- �������еĲ�����Ϊģ����д���
template<typename T1=string,typename T2=int>
void showInfoB(Person<T1 ,T2> p){
    p.showPersonInfo();
    cout<<"T type is:"<<(abi::__cxa_demangle(typeid(T1).name(),0,0,0))<<endl;
    //  std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >
    cout<<"K type is:"<<(abi::__cxa_demangle(typeid(T2).name(),0,0,0))<<endl;//int
};

void test02(){
    Person<string>p("����",18);
    showInfoB(p);
}
// 3. ������ģ�廯   --- ������������� ģ�廯���д���
template <class T>
void showInfoC(T& p){
    p.showPersonInfo();
    cout<<"T type is : "<<(abi::__cxa_demangle(typeid(T).name(),0,0,0))<<endl;
    // Person<std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >, int>
};

void test03(){
    Person<string>p("����",29);
    showInfoC(p);
}

int main() {
    test01();
    test02();
    test03();
    system("pause");
    return 0;
}