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

class Hero{
public:
    Hero(string name,int age){
        this->m_Name=name;
        this->m_Age=age;
    };
    string m_Name;
    int m_Age;
};

void printItem(Hero h){
    cout<<"姓名: "<<h.m_Name<<"年龄:"<<h.m_Age<<endl;
}

void test01(){
    //创建vector容器对象，并且通过模板参数指定容器中存放的数据的类型
    Hero h1("孙悟空",2200);
    Hero h2("唐僧",40);
    Hero h3("赵云",33);
    Hero h4("钟繇",45);
    Hero h5("贾宝玉",22);
    vector<Hero>v;
    Hero a[5]={h1,h2,h3,h4,h5};
    for (int i = 0; i < sizeof (a)/sizeof a[0]; ++i) {
        // 向容器中push 数据
        v.push_back(a[i]);
    }
    //每一个容器都有自己的迭代器，迭代器是用来遍历容器中的元素
    // 把迭代器看成一个指针
    //v.begin()返回迭代器，这个迭代器指向容器中第一个数据
    //v.end()返回迭代器，这个迭代器指向容器元素的最后一个元素的下一个位置
    //vector<int>::iterator 拿到vector<int>这种容器的迭代器类型
    vector<Hero>::iterator pBegin=v.begin();
    vector<Hero>::iterator pEnd=v.end();

    // 遍历数据
    // 1. 第一种方式, 手动遍历迭代器
    while(pBegin!=pEnd){
        printItem(*pBegin);
        pBegin++;
    }

    // 2. 使用for循环
    for (vector<Hero>::iterator it=v.begin();it!=v.end();it++) {
        printItem(*it);
    }

    // 3. 使用 algorithm 提供的算法来进行遍历
    std::for_each(v.begin(),v.end(),printItem);
};

int main() {
    test01();
    system("pause");
    return 0;
}