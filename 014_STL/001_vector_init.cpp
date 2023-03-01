//
// Created by lxw on 2023/3/1.
//


#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::vector;

template<typename T>
void printItem(T val){
    cout<<val<<endl;
    cout<<"execute"<<endl;
}

void test01(){
    //创建vector容器对象，并且通过模板参数指定容器中存放的数据的类型
    vector<int>v;
    int a[5]={10,20,30,40,50};
    for (int i = 0; i < sizeof (a)/sizeof a[0]; ++i) {
        // 向容器中push 数据
        v.push_back(a[i]);
    }
    //每一个容器都有自己的迭代器，迭代器是用来遍历容器中的元素
    // 把迭代器看成一个指针
    //v.begin()返回迭代器，这个迭代器指向容器中第一个数据
    //v.end()返回迭代器，这个迭代器指向容器元素的最后一个元素的下一个位置
    //vector<int>::iterator 拿到vector<int>这种容器的迭代器类型
    vector<int>::iterator pBegin=v.begin();
    vector<int>::iterator pEnd=v.end();

    // 遍历数据
    // 1. 第一种方式, 手动遍历迭代器
    while(pBegin!=pEnd){
        cout<<*pBegin<<endl;
        pBegin++;
    }

    // 2. 使用for循环
    for (vector<int>::iterator it=v.begin();it!=v.end();it++) {
        cout<<*it<<endl;
    }

    // 3. 使用 algorithm 提供的算法来进行遍历
    std::for_each(v.begin(),v.end(),printItem<int>);
};

int main() {
    test01();
    system("pause");
    return 0;
}