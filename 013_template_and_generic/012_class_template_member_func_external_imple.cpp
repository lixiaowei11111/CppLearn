//
// Created by lxw on 2023/2/24.
//


#include <iostream>

using std::cout;
using std::endl;
using std::string;

// ��ģ�� ��Ա���� �� ���ⲿ��ʵ��
template<typename T,typename K>
class Person{
public:
    T n_Name;
    K n_Age;
    Person(T name,K age);// ���캯���ڲ�����, �ⲿʵ��
    void showInfo(); // ��ͨ��Ա��������, �ⲿʵ��
};

// 1. ���캯�����ⲿ����ʵ��
template<typename T, typename K>
Person<T,K>::Person(T name,K age){
    this->n_Age=age;
    this->n_Name=name;
};

// 2. ��ͨ�������ⲿ����ʵ��
template<typename T,typename K>
void Person<T,K>::showInfo() {
    cout<<"name is : "<<this->n_Name<<endl;
    cout<<"age is : "<<this->n_Age<<endl;
}

void test01(){
    Person<string ,int>p1("����",22);
    p1.showInfo();
};
int main() {
    test01();
    system("pause");
    return 0;
}