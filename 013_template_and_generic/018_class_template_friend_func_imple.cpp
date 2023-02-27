//
// Created by lxw on 2023/2/27.
//


#include <iostream>

using std::cout;
using std::endl;
using std::string;

// class template ������Ԫ����
// 1. ȫ�ֺ�������Ԫ����, class ��ʵ��
// 2. ȫ�ֺ�������Ԫ����, class ��ʵ��

// class ����ʵ��, Ҫ������ class
template<typename T,typename K>
class Person;

template<typename T,typename K>
void printInfo(Person<T,K>& p){
    cout<<"name :"<<p.m_Name<<endl;
    cout<<"age :"<<p.m_Age<<endl;
}

template<typename T,typename K>
class Person{
    // 1.��Ԫ���� class ��ʵ��
    friend void showInfo(Person<T,K>* p){
        cout<<"name :"<<p->m_Name<<endl;
        cout<<"age :"<<p->m_Age<<endl;
    };
    friend void printInfo<>(Person<T,K>& p);
public:
    T m_Name;
    K m_Age;
    Person(T name,K age){
        this->m_Name=name;
        this->m_Age=age;
    };

};
// class ��ʵ��
void test01(){
    Person<string,int>* p=new Person<string,int>("����",34);
    showInfo(p);
};
// 2. class ��ʵ��;
void test02(){
    Person<string,int>p("����ʱ",24);
    printInfo(p);
};

int main() {
    test01();
    test02();
    system("pause");
    return 0;
}