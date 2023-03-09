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
using std::for_each;

void printItem(int val){
    cout<<val<<endl;
}

void printVectorIntItem(vector<int> &v){
    for_each(v.begin(),v.end(),printItem);
};

int main() {
    vector<int> v1;
    int arr[7]={1,2,3,4,5,6,7};
    int size=sizeof(arr)/sizeof(arr[0]);
    for (int i = 0; i < size; ++i) {
        v1.push_back(i);
    }
    vector<int> v2;
    // 1. assign operator = overload
    v2=v1;
    printVectorIntItem(v2);
    // 2.
    vector<int> v3(v2.begin(),v2.end());
    printVectorIntItem(v3);
    //3.
    vector<int> v4(10,250);
    printVectorIntItem(v4);
    system("pause");
    return 0;
}