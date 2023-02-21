//
// Created by lxw on 2023/2/21.
//


#include <iostream>
using std::cout;
using std::endl;
using std::string;

// 比较两个数是否相等的的模板函数
// 这种处理不了复杂一点的数据 比如 数组 和 类
template<typename T>
bool myCompare(T &a,T &b){
    return  a==b;
};

class Person{
public:
    Person(string name,int age){
        this->m_Name=name;
        this->m_Age=age;
    }
    string m_Name;
    int m_Age;
};
// 具体化模板会优先调用
template<>bool myCompare(Person &a,Person &b){
    if(a.m_Age == b.m_Age&&a.m_Name == b.m_Name){
        return true;
    }else{
        return false;
    }
};


void test01(){
    int a=100;
    int b=90;
    cout<<(myCompare(a,b)?"a==b":"a!=b")<<endl;
     Person p1= Person("张三",22);
     Person p2= Person("张三",22);
    cout<<(myCompare(p1,p2)?"a==b":"a!=b")<<endl;// a==b 比较特殊变量类型的大小需要具体化模板

};

int main() {
    test01();
    system("pause");
    return 0;
}