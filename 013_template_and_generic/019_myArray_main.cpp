//
// Created by lxw on 2023/2/28.
//


#include <iostream>
#include "019_myArray_class_template.hpp"
using std::cout;
using std::endl;
using std::string;

void test01(){
    MyArray<int>arr1(5);
    MyArray<int>arr2(arr1);
    MyArray<int>arr3(100);
    arr3=arr1;// operator overload func execute
};
void printArr(MyArray<int>& arr1){
    for (int i = 0; i < arr1.getLength(); ++i) {
            cout<<(arr1[i])<<endl;
    }
};

void test02(){
    MyArray<int>arr1(5);
    for (int i = 0; i < 5; ++i) {
        arr1.Push_Back(i);
    }
    printArr(arr1);
    cout<<"arr1������:"<<arr1.getCapacity()<<endl;// 5
    cout<<"arr1�Ĵ�С:"<<arr1.getLength()<<endl;// 5
};

// �����Զ�����������
class Hero{
public:
    string m_Name;
    int m_Age;
    Hero(){};
    Hero(string name,int age){
        this->m_Name=name;
        this->m_Age=age;
    };
};
void printArr(MyArray<Hero>& arr){
    for (int i = 0; i < arr.getLength(); ++i) {
        cout<<"����:"<<arr[i].m_Name<<"  ����:"<<arr[i].m_Age<<endl;
    }

};

void test03(){
    Hero h1("��",114514);
    Hero h2("��",110);
    Hero h3("��",1200);
    Hero h4("��ͷ",12000);
    Hero h5("ţͷ",9000);
    Hero h[5]={h1,h2,h3,h4,h5};

    MyArray<Hero>arr1(10);
    for (int i = 0; i < sizeof (h)/sizeof (h[0]); ++i) {
        arr1.Push_Back(h[i]);
    }
    printArr(arr1);
    cout<<"arr1������:"<<arr1.getCapacity()<<endl;// 10
    cout<<"arr1�Ĵ�С:"<<arr1.getLength()<<endl;// 5

};
int main() {
//    test01();
//    test02();
    test03();
    system("pause");
    return 0;
}