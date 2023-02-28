#pragma once
#include <iostream>


using std::cout;
using std::endl;
using std::string;

//- 可以对内置数据类型以及自定义数据类型的数据进行存储
//- 将数组中的数据存储到堆区
//- 构造函数中可以传入数组的容量
//- 提供对应的拷贝构造函数以及operator=防止浅拷贝问题
//- 提供尾插法和尾删法对数组中的数据进行增加和删除
//- 可以通过下标的方式访问数组中的元素
//- 可以获取数组中当前元素个数和数组的容量

template <typename T>
class MyArray{
public:
    // has params constructor func
    MyArray(int capacity){
        this->capacity=capacity;
        this->length=0;
        this->pArray=new T[this->capacity];
        cout<<"params constructor func execute"<<endl;
    };
    // copy constructor func
    MyArray(const MyArray& array){
        //+ 作用: 常量引用主要用来修饰形参, 防止误操作,引用的本质就是一个常量指针,即指针的指向不能被更改,
        // 加上const,即const MyArray* const pArray=要拷贝的实例
        //+ 在函数形参列表中, 可以加 <mark>const</mark>修饰符,防止形参改变实参
        this->capacity=array.capacity;
        this->length=array.length;
        this->pArray=new T[this->capacity];
        for (int i = 0; i < this->length; i++) {
            this->pArray[i]=array.pArray[i];
        }
        cout<<"copy constructor func execute"<<endl;
    }
    // operator overload 一定要使用引用作为函数返回值,不然相当于新建一个实例
    MyArray& operator=(const MyArray& array){
        if (this->pArray != NULL)
        {
            delete[] this->pArray;
            this->pArray = NULL;
            this->capacity = 0;
            this->length = 0;
        }
        this->capacity=array.capacity;
        this->length=array.length;
        this->pArray=new T[this->capacity];
        for (int i = 0; i < this->length; i++) {
            this->pArray[i]=pArray[i];
        }
        cout<<"operator = func execute"<<endl;
        return *this;// 对实例解引用
    }
    // destructor func
    ~ MyArray(){
        if (this->pArray != NULL)
        {
            delete[] this->pArray;
            this->pArray = NULL;
            this->capacity = 0;
            this->length = 0;
        }
        cout<<"destructor func execute"<<endl;
    };
    // 尾插函数
    void Push_Back(T& item){
        if(this->length==this->capacity){
            // 达到容量大小时,不再插入
            return;
        }
        this->pArray[this->length]=item;
        this->length++;
    };
    // 尾删函数, 删除数组最后一个元素,(让用户访问不到这个元素(软删除))
    void Pop_Back(){
        if(this->length==0){
            return;
        };
        this->length--;
    }
    // 中括号重载, 通过下标方式来访问数组重的数据
    T& operator[](int index){
        return this->pArray[index];
    };
    // 获取数组容量
    int getCapacity(){
        return  this->capacity;
    };
    // 获取数组长度
    int getLength(){
      return  this->length;
    };

private:
    T* pArray;// 数组类型的指针
    int capacity; // 容量
    int length;// 长度
};
