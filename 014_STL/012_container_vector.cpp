//
// Created by lxw on 2023/3/7.
//


#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

//vector<T> v;//采用模板实现类实现，默认构造函数
//vector(v.begin(), v.end());//将v[begin(), end())区间中的元素拷贝给本身。
//vector(n, elem);//构造函数将n个elem拷贝给本身。
//vector(const vector &vec);//拷贝构造函数。

template<typename T>
void printVectorItem(vector<T> &v){
    // 使用iterator 加for循环来遍历输出
    for (typename vector<T>::iterator it=v.begin();it!=v.end();it++){
        cout<<*it<<endl;
    }
}

int main() {
    vector<int> v1;
    cout<<sizeof(v1)<<endl;// 24 Byte
    for (int i = 0; i < 10; ++i) {
        v1.push_back(i);
    }
    printVectorItem(v1);
    vector<int> v2(v1.begin(),v1.end());
    printVectorItem(v2);

    vector<char> v3(10,'a');
    printVectorItem(v3);

    vector<char>v4(v3);
    printVectorItem(v4);
    system("pause");
    return 0;
}