//
// Created by lxw on 2023/2/26.
//


#include <iostream>

using std::cout;
using std::endl;
using std::string;
// ��ģ��ķ��ļ���д

// ԭ���ı�д
template<typename T,typename  K>
class Person{
public:
    T n_Name;
    K n_Age;
    Person(T name,K age);
    void showInfo();


};
// 1. ����ʵ�ֳ�Ա����
template <typename T,typename K>
Person<T,K>::Person(T name,K age){
    this->n_Name=name;
    this->n_Age=age;
};

template <typename T,typename K>
void Person<T, K>::showInfo() {
    cout<<"name is :"<<this->n_Name<<endl;
    cout<<"age is :"<<this->n_Age<<endl;
};
void test01(){
    Person<string,int>p1("�Ű�",23);
    p1.showInfo();
};
// 2.����class templateʱ, ��Ϊ����ֻ���ڵ���ʱ�Żᴴ��,���Բ���ֱ�ӵ���.h�����ļ�
// ��һ�ֲ𿪷���, ����𿪲�����cpp,������.h�ļ�, �ļ� Person.h, Person.cpp


int main() {
    test01();
    system("pause");
    return 0;
}