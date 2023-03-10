//
// Created by lxw on 2023/3/11.
//


#include <iostream>
#include <vector>
#include <algorithm>


using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::for_each;

int main() {
    int arr[5]={1,3,4,5,6};
    vector<int> v1;
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i) {
        v1.push_back(arr[i]);
    }
    for (int i = 0; i < v1.size(); ++i) {
        cout<<"v1.at(i)"<<v1.at(i)<<endl;
        cout<<"v1[i]"<<v1[i]<<endl;
    }
    cout<<v1.front()<<endl;// 访问第一个元素 1
    cout<<v1.back()<<endl;// 访问最后一个元素 6
    system("pause");
    return 0;
}