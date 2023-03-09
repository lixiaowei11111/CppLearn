//
// Created by lxw on 2023/3/9.
//


#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::string;
using std::vector;

void printItem(int item){
    cout<<item<<endl;
}
void printVectorIntItem(vector<int> &v){
    std::for_each(v.begin(),v.end(),printItem);
}

int main() {
    vector<int> v1;
    cout<<"容器是否为空: "<<v1.empty()<<endl;// 1;
    int arr[5]={1,2,3,4,5};
    int len=sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < len; ++i) {
        v1.push_back(i);
    }
    cout<<"容器是否为空: "<<v1.empty()<<endl;// 0;
    cout<<"容器的容量为: "<<v1.capacity()<<endl;// 8
    cout<<"容器的大小为: "<<v1.size()<<endl;// 5
    // resize 重新指定大小 ，若指定的更大，默认用0填充新位置，可以利用重载版本替换默认填充
    v1.resize(10,200);// 改变原容器
    printVectorIntItem(v1);// 0 1 2 3 4 200 200 200 200 200
    v1.resize(5);
    printVectorIntItem(v1);// 0 1 2 3 4
    cout<<"容器的容量为: "<<v1.capacity()<<endl;// 10
    cout<<"容器的大小为: "<<v1.size()<<endl;// 5
    v1.resize(11);
    printVectorIntItem(v1);// 0 1 2 3 4 0 0 0 0 0 0
    cout<<"容器的容量为: "<<v1.capacity()<<endl;// 11
    cout<<"容器的大小为: "<<v1.size()<<endl;// 11

    system("pause");
    return 0;
}