//
// Created by lxw on 2023/2/26.
//


#include <iostream>
#include "014_person.cpp"

using std::cout;
using std::endl;
using std::string;

void test01(){
    Person<string,int>p1("������",28);
    p1.showInfo();
};
// 2.����class templateʱ, ��Ϊ����ֻ���ڵ���ʱ�Żᴴ��,���Բ���ֱ�ӵ���.h�����ļ�
// ��һ�ֲ𿪷���, ����𿪲�����cpp,������.h�ļ�, �ļ� Person.h, Person.cpp


int main() {
    test01();
    system("pause");
    return 0;
}

