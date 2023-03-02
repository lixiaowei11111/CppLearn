//
// Created by lxw on 2023/3/2.
//


#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;


void test01(){
    // 进行容器嵌套容器
    vector<vector<int>>v;
    // 先定义小容器
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;

    // 再定义大容器
    cout<<sizeof(v1)<<endl;// 24 Byte

    // 给 每个 小容器插入值
    for (int i = 0; i < 4; ++i) {
        v1.push_back(i+1);
        v2.push_back(i+2);
        v3.push_back(i+3);
        v4.push_back(i+4);
    }
    // v1 [1,2,3,4]
    // v2 [2,3,4,5]
    // v3 [3,4,5,6]
    // v4 [4,5,6,7]
    // 把小容器插入到大容器中
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    // 二维数组v [ [1,2,3,4],[2,3,4,5],[3,4,5,6],[4,5,6,7]]
    for (vector<vector<int>>::iterator it= v.begin();it!=v.end();it++) {
        for (vector<int>::iterator item = (*it).begin(); item!=(*it).end();item++) {
                cout<<*item<<" ";
        }
        cout<<endl;
    }
};

int main() {
    test01();
    system("pause");
    return 0;
}