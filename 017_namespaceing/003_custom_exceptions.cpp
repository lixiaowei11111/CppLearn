//
// Created by lxw on 2023/2/28.
//


#include <iostream>
#include <exception>

using std::cout;
using std::endl;
using std::string;
using std::cerr;
using std::exception;

class MyException : public exception
{
public:
    const char * what () const throw ()
    {
        return "C++ Exception";
    }
};

void test01(){
    try
    {
        throw MyException();
    }
    catch(MyException& e)
    {
        cout << "MyException caught" << endl;
        cout << e.what() << endl;
    }
};

int main() {
    test01();
    system("pause");
    return 0;
}