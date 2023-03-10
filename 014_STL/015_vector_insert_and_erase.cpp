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

void printItem(int v){
    cout<<v<<endl;
}


int main() {
    int arr[5]={1,2,3,45,12};
    vector<int> v1;
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i) {
        v1.push_back(arr[i]); // 尾部插入一个元素 push_back
    };
    for_each(v1.begin(),v1.end(), printItem);// 1 2 3 45 12
    // 删除一个尾部元素 pop_back
    v1.pop_back();
    for_each(v1.begin(),v1.end(), printItem);// 1 2 3 45
    v1.insert(v1.begin(),23);
    for_each(v1.begin(),v1.end(), printItem);//23 1 2 3 45
    v1.insert(v1.end(),3,99);
    for_each(v1.begin(),v1.end(), printItem);//23 1 2 3 45 99 99 99
    v1.erase(v1.begin());
    for_each(v1.begin(),v1.end(), printItem);// 1 2 3 45 99 99 99
    v1.erase(v1.begin(),v1.end());
    for_each(v1.begin(),v1.end(), printItem);
    cout<<v1.empty()<<endl;// 清空操作
    v1.push_back(1);
    v1.clear();// 清空操作
    cout<<v1.empty()<<endl;
    system("pause");
    return 0;
}