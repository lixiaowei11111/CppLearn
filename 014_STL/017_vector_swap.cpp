//
// Created by lxw on 2023/3/11.
//


#include <iostream>
#include<vector>
#include<algorithm>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::for_each;

void  printItem(int v){
    cout<<v<<endl;
};

// 1. 基本使用
void test01(){
    int arr[3]={1,2,3};
    int arr2[3]={9,9,9};
    vector<int> v1;
    vector<int> v2;
    for (int i = 0; i < 3; ++i) {
        v1.push_back(arr[i]);
        v2.push_back(arr2[i]);
    }
    for_each(v1.begin(),v1.end(), printItem);// 1 2 3
    for_each(v2.begin(),v2.end(), printItem);// 9 9 9
    v1.swap(v2);
    for_each(v1.begin(),v1.end(), printItem);// 9 9 9
    for_each(v2.begin(),v2.end(), printItem);// 1 2 3

};

// 2. 实际用途
// 巧用swap 收缩内存空间, 使用 vector的 capacity和size相等
void test02(){
    vector<int> v1;
    for (int i = 0; i <10000; ++i) {
        v1.push_back(i);
    }
    cout<<"capacity:"<<v1.capacity()<<endl;// 16384
    cout<<"size:"<<v1.size()<<endl;// 10000
    v1.resize(3);
    cout<<"capacity:"<<v1.capacity()<<endl;// 16384 vector动态扩展, 但不会自动收缩
    cout<<"size:"<<v1.size()<<endl;// 3

    vector<int>(v1).swap(v1);// 匿名函数执行完后, 会被立即释放掉
    cout<<"capacity:"<<v1.capacity()<<endl;// 3 使用匿名函数拷贝构造
    cout<<"size:"<<v1.size()<<endl;// 3
};

int main() {
    test01();
    test02();
    system("pause");
    return 0;
}