//
// Created by lxw on 2023/3/11.
//


#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

void test01(){
    int num=0;
    int* p=NULL;// 统计开辟内存空间的次数
    vector<int> v1;
    v1.reserve(100000);// 使用reserve 开辟内存空间后
    for (int i = 0; i < 100000; ++i) {
        v1.push_back(i);
        if(p!=&v1[0]){
            p=&v1[0];
            num++;
        }
    }
    cout<<num<<endl;// 38 // 使用reserve 开辟内存空间后 1
};

int main() {
    test01();
    system("pause");
    return 0;
}