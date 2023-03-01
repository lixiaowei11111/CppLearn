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
    cout<<"����: "<<h.m_Name<<"����:"<<h.m_Age<<endl;
}

void test01(){
    //����vector�������󣬲���ͨ��ģ�����ָ�������д�ŵ����ݵ�����
    Hero h1("�����",2200);
    Hero h2("��ɮ",40);
    Hero h3("����",33);
    Hero h4("����",45);
    Hero h5("�ֱ���",22);
    vector<Hero>v;
    Hero a[5]={h1,h2,h3,h4,h5};
    for (int i = 0; i < sizeof (a)/sizeof a[0]; ++i) {
        // ��������push ����
        v.push_back(a[i]);
    }
    //ÿһ�����������Լ��ĵ����������������������������е�Ԫ��
    // �ѵ���������һ��ָ��
    //v.begin()���ص����������������ָ�������е�һ������
    //v.end()���ص����������������ָ������Ԫ�ص����һ��Ԫ�ص���һ��λ��
    //vector<int>::iterator �õ�vector<int>���������ĵ���������
    vector<Hero>::iterator pBegin=v.begin();
    vector<Hero>::iterator pEnd=v.end();

    // ��������
    // 1. ��һ�ַ�ʽ, �ֶ�����������
    while(pBegin!=pEnd){
        printItem(*pBegin);
        pBegin++;
    }

    // 2. ʹ��forѭ��
    for (vector<Hero>::iterator it=v.begin();it!=v.end();it++) {
        printItem(*it);
    }

    // 3. ʹ�� algorithm �ṩ���㷨�����б���
    std::for_each(v.begin(),v.end(),printItem);
};

int main() {
    test01();
    system("pause");
    return 0;
}