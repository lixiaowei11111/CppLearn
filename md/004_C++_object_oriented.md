# C++ 核心编程

# 1.内存分区模型

+ C++ 程序在执行时, 将内存大方向划分为4个区域
  + 程序运行前:
    + 代码区: 存放函数体的二进制代码,由操作系统进行管理
    + 全局区:存放全局变量和静态变量以及常量
  + 程序运行后:
    + 栈区:由编译器自动分配释放, 存放函数的参数值,局部变量等
    + 堆区: 由程序员分分配和释放,若程序员不释放,程序结束时由操作系统回收
+ 内存四区的意义
  + 不同区域存放的数据,赋予不同的生命周期,给我们更大的灵活编程

## 1.1 程序运行前

在代码编译后,生成了 exe可执行文件,未执行该程序前分为两个区域

+ 代码区:

  + 存放CPU执行的机器指令
  + 代码区是**共享**的, 共享的目的是对于频繁被执行的程序,只需要在内存中有一份代码即可
  + 代码是**只读**的,时期只读的原因是防止程序意外的修改了它的指令

+ 全局区

  + **全局变量**和**静态变量**存放在此
  + 全局区还包含了常量区,字符串常量和其他常量也存放在此
  + 该区域的数据在程序结束后由操作系统释放

+ 代码示例:

  + 定义静态变量 使用关键词 static

    ```c++
    static int s_g_b = 456;
    ```

  ```c++
  #include<iostream>
  #include<string>
  
  using std::cout;
  using std::endl;
  
  // 1.定义全局变量
  int g_a = 123;
  int g_b = 456;
  
  //4.定义静态全局变量
  static int s_g_a = 123;
  static int s_g_b = 456;
  
  //6. 定义和初始化 全局常量
  const int c_g_a = 123;
  const int c_g_b = 456;
  
  int main() {
  	//2. 定义局部变量
  	int l_a = 123;
  	int l_b = 345;
  	cout << "全局常量 g_a的地址为:  " << (int)&g_a << endl;
  	cout << "全局常量 g_b的地址为:  " << (int)&g_b << endl;
  	cout << "局部常量 l_a的地址为:  " << (int)&l_a << endl;
  	cout << "局部常量 l_b的地址为:  " << (int)&l_b << endl;
  
  	//3. 定义静态局部变量, 使用 static
  	static int s_l_a = 123;
  	static int s_l_b = 456;
  	cout << "static全局常量 c_g_a的地址为:  " << (int)&s_g_a << endl;
  	cout << "static全局常量 c_g_b的地址为:  " << (int)&s_g_b << endl;
  	cout << "static局部常量 s_l_a的地址为:  " << (int)&s_l_a << endl;
  	cout << "static局部常量 s_l_b的地址为:  " << (int)&s_l_b << endl;
  
  	//4.const 修饰 局部变量
  	const int c_l_a = 123;
  	const int c_l_b = 456;
  	cout << "全局常量 c_g_a的地址为:  " << (int)&c_g_a << endl;
  	cout << "全局常量 c_g_b的地址为:  " << (int)&c_g_b << endl;
  	cout << "局部常量 c_l_a的地址为:  " << (int)&c_l_a << endl;
  	cout << "局部常量 c_l_b的地址为:  " << (int)&c_l_b << endl;
  	//5.字符串常量
  	cout << "字符串常量的地址为" << (int)&"hello_world" << endl;
  
  
  	system("pause");
  	return 0;
  }
  ```

+ 结果:

  <img src="E:\Learn\006-cpp\img\全局区示例代码结果.png" style="zoom:50%;" />

+ 结论:

  + C++中在程序运行前分为 全局区 和代码区
  + 代码区特点是共享和只读
  + 全局区存放全局变量,静态变量(包括局部静态变量),常量
  + 常量区中存放 const 修饰的全局常量 和 字符串常量

## 1.2 程序运行后

+ 栈区

  + 由编译器自动分配释放,存放函数的参数值,局部变量等
  + 注意事项: 不要返回局部变量的地址, 栈区开辟的数据由编译器自动释放

+ 示例:

  ```c++
  // 1.定义一个返回局部变量地址的方法
  
  
  int* func(int b) {// 形参数据也被编译器 存放在 栈区
  
  	int a = 10;
  	return &a;
  }
  
  
  
  int main() {
  	//1. 栈区, 由编译器自动分配,自动释放. 包括 局部变量 和 函数函数形参
  	//2. 不要返回局部变量的地址,  编译器会将其自动释放
  
  	int* p = func(1);
  	cout << *p << endl;//10
  	cout << *p << endl;// 不同编译器结果不同, 但编译器会给出警告
  
  
  	return 0;
  }
  ```

  

+ 堆区:

  + 由程序员分配释放, 若程序员不释放,程序结束时由操作系统回收
  + 在C++中主要利用 new在堆区 开辟内存

+ 示例:

  + **new 在堆区开辟地址, new返回的也是一个地址**, 需要使用 指针变量来接收

  ```c++
  // 1.定义一个返回局部变量地址的方法
  int* func() {
  	// new 关键字在 堆区 中开辟地址, 堆区中的内存变量由程序员来手动释放分配
  	int* p = new int(10);// new 关键字在C++ 中本身返回的就是 地址, 使用指针来接收
  	return p;
  }
  
  
  
  int main() {
  	int* p = func();
  	cout << *p << endl;//10
  	cout << *p << endl;//10
  
  
  	return 0;
  }
  ```

  

## 1.3 new操作符

+ C++ 中利用**new**操作符在堆区开辟内存
+ 堆区开辟的数据,由程序员手动开辟,手动释放, 释放利用操作符<mark>delete</mark>
+ 语法: `new 数据类型`
+ 利用new创建的数据,会返回该数据对应的类型的指针

+ 示例: 基本语法

  + new  : 堆区开辟变量, 防止被编译器自动释放
    + 单个变量:`new int(10)`;代表heap上开辟的该地址的 值为int类型的 10;
    + 数组:`new int`[10]; 代表heap上开辟了 拥有10个元素的数组
  + delete: 删除对应堆区地址上的变量值, 清空内存
    + 单个变量: `delete 堆区地址`
      + 如: `int* p = new int(10);delete p;`
    + 数组:`delete [] 堆区地址(数组首地址)`
      + 如:`int* p = new int[10];delete [] p;`

  ```c++
  // 利用new创建一个变量
  double* test01() {
  	return new double(3.14159); // new 在堆区开辟数据
  };
  
  // 2.利用 new创建一个数组
  void test02() {
  	int* p = new int[10];// 中括号[]代表的是 数组, 表示这个数组有10个元素
  
  	for (size_t i = 0; i < 10; i++)
  	{
  		p[i] = 100 + i;
  	}
  	for (size_t i = 0; i < 10; i++)
  	{
  		cout << p[i] << endl;// 100 101 102 103 104 105 106 107 108 109
  	}
  
  	delete[]  p;
  };
  
  
  int main() {
  	double* p1 = test01();
  
  
  	cout << *p1 << endl;// 3.14159
  	// 堆区的数据不会被编译器自动释放,
  	cout << *p1 << endl;//3.14159
  
  	//使用delete 关键字释放 变量, 语法: delete 地址
  	delete p1;
  
  	//cout << *p1 << endl;// delete在堆区,编译器提示:拥有未初始化的内存p1
  
  	test02();
  
  	system("pause");
  	return 0;
  }
  ```


# 2. 引用

## 2.1 引用的基本使用

+ 作用: 给变量起别名

+ 语法: `数据类型& 别名 = 原名`

+ 示例: 

  ```c++
  int main() {
  	// 1. 引用 (引用的概念类似于 JS的引用类型,可以使得多个变量的值指向同一个地址,随意通过一个变量更改,另外一个变量获取到的值也会改变,不过Cpp中对值类型同样生效);
  	int a = 10;
  
  	// 使得变量b 引用a的值
  	int& b = a;
  	b = 20;
  	cout << a << endl;// 20
  	cout << b << endl;// 20
  
  	cout << &b << endl;
  	cout << &a << endl;// 地址相同
  
  	int c = 30;
  	int* d = &c;
  	*d = 40;
  	cout << c << endl;// 40
  	cout << *d << endl;//40
  
  
  
  	system("pause");
  	return 0;
  }
  ```

+ 个人理解:

  引用的概念类似于 JS的引用类型,可以使得多个变量的值指向同一个地址,随意通过一个变量更改,另外一个变量获取到的值也会改变,不过Cpp中对值类型同样生效

  ```javascript
  const a = {proeprty:10};
  const b = a;
  b.property = 10;
  console.log(a.property);//10
  console.log(b.property);//10
  ```

## 2.2 引用注意事项

+ 引用必须初始化
+ 引用在初始化后, 不可以改变

+ 示例:

  ```c++
  int main() {
  	
  	// 引用注意事项;
  	
  	//1.引用必须初始化
  	int a = 20;
  
  	//int& b;// 不初始化引用变量时, vs2022会报错,未能初始化本地变量
  
  	// 2.引用变量的 指向 不能被再次改变
  	int& b = a;
  	int c = 30;
  
  	int& d = c;
  	b = d; // 引用的值 可以再次被赋值
  	cout << a << endl;
  	system("pause");
  	return 0;
  }
  ```



## 2.3 C++ 引用 vs 指针

+ 不存在空引用. 引用必须链接到一块合法的内存
+ 一旦 引用被初始化为 一个对象, 就不能被指向另外一个对象. 指针可以在任意时候改变指向
+ 引用在创建时必须初始化.指针可以在任何时候初始化

引用的本质就是一个 指针常量, (指针的值不可以被更改)

## 2.4 引用做函数参数

+ 作用: 函数传参时, 可以利用引用的技术让形参修饰实参

+ 优点: 可以简化指针修改实参

+ 示例:

  ```c++
  // 声明一个函数参数
  void test01(int& param, int* param2);
  int main() {
  	// 引用做函数返回值
  	int a = 100;
  	test01(a, &a);
  	cout << a << endl;//20
  	system("pause");
  	return 0;
  }
  
  void test01(int& param,int* param2) {
  	param = 20;
  	cout << param << endl; //20
  	cout << *param2 << endl;//20
  };
  ```

  

## 2.5 引用做函数返回值

+ 通过使用引用来替代指针, 会使C++程序更容易阅读和维护

+ 作用: 引用是可以作为函数的返回值存在的



+ 注意: 不要返回局部变量引用
+ 用法: 函数调用作为左值

+ 当返回一个引用时，要注意被引用的对象不能超出作用域。所以返回一个对局部变量的引用是不合法的，但是，可以返回一个对静态变量的引用。

  ```c++
  int& func() {
     int q;
     //! return q; // 在编译时发生错误
     static int x;
     return x;     // 安全，x 在函数作用域外依然是有效的
  }
  ```

+ 

+ 示例代码:

  ```c++
  
  // 定义一个全局变量
  double vals[] = { 1.23,3.14,6.28 };
  
  // 声明一个返回引用的函数
  double& test01(int i);
  
  
  // 不能返回一个局部变量的引用
  int& test02() {
  	int i = 10;
  	return i;
  }
  int main() {
  
  	//改变值之前的全局变量
  	for (size_t i = 0; i < 3; i++)
  	{
  		cout << "vals[" << i << "]: " << vals[i] << endl;
  	}
  	// 通过返回函数的引用值改变
  	test01(2) = 3.25;
  	test01(0) = 3.25;
  
  	//改变值之后的数组
  	for (size_t i = 0; i < 3; i++)
  	{
  		cout << "vals[" << i << "]: " << vals[i] << endl;
  	}
  	cout<<test02()<<endl;// 报错
  
  	system("pause");
  	return 0;
  }
  
  // 定义一个 返回引用的变量
  double& test01(int i) {
  	double& ref = vals[i];// 数组中 指定位置 i的值 被地址引用被返回
  	return ref;
  }
  ```

  ![](E:\Learn\006-cpp\img\引用作为函数返回值.png)

## 2.6 引用的本质

+ 本质: **引用的本质在C++内部实现是一个指针常量**

  + 指针常量 : 指针的值是一个常量,值不能被修改, 即指针指向不能被改变
    + 语法:``int a =20;int* const p = a;`
    + p不能再指向其他其他地方
  + 常量指针: 指向常量的指针, 即 指针指向的值不能被修改
    + 语法:`int a = 20;const int * p = a;`
    + `*p 不能再改变 a的值`

+ 示例:

  ```c++
  // 发现是引用,自动转换为 指针常量 int* const ref=&a;
  void func(int& ref) {
  	ref = 100;// ref是引用 , 进行解引用操作 *ref = 100
  }
  
  
  int main() {
  	int a = 10;
  
  
  	// 自动转换为指针常量(指针指向不变) int* const ref = &a;
  	int& ref = a;
  
  	ref = 20;// 内部发现ref 是引用, 自动转换为 *ref = 20;
  
  	cout << a << endl;//20
  	cout << ref << endl;//20
  
  	system("pause");
  	return 0;
  }
  ```

## 2.7 常量引用

+ 作用: 常量引用主要用来修饰形参, 防止误操作.

+ 在函数形参列表中, 可以加 <mark>const</mark>修饰符,防止形参改变实参

+ 示例:

  ```c++
  void showValue(const int& ref) {
  	// const修饰 引用变量时, 引用变量指向的值也不能再被修改
  	// ref = 20;// vs2022报错, 表达式必须是可修改的左值
  	cout << ref << endl;
  }
  
  
  int main() {
  
  	// 正常情况下, 声明引用必须初始化,分配一个合理的引用地址
  	//直接复制==赋值是违法的
  	//int& ref = 200;
  
  	//const修饰 引用
  	const int& ref = 200;
  	//相当于 int temp = 10;const int& ref = temp;
  	//ref = 20;// const修饰后,变为只读常量
  	int a = 20;
  	showValue(a);
  
  	system("pause");
  	return 0;
  }
  ```


# 3 函数高级使用

+ 函数可以声明任意次数, 但只能定义一次
+ 函数声明可以有

## 3.1 函数的默认参数

在C++ 中,函数的形参列表中形参是可以有默认值的

语法:`返回值类型 函数名 (参数=默认值){}`

+ 示例:

  ```c++
  //1. 当某个参数有默认参数时, 该参数的右边的参数也必须有默认参数
  
  //int addFunc(int a=10,int b,int c=2);// 编译器报错 默认实参不在形参结尾的列表
  int addFunc2(int a = 1, int b = 2, int c = 4);
  
  // 2. 默认参数不能重定义(即在函数声明定义,又在函数定义)
  int sumFunc(int a = 10,int b = 10);
  
  int sumFunc(int a = 10, int b = 10) {
  	return a + b;
  }
  
  
  
  int main() {
  
  	cout << sumFunc(10, 10) << endl;// 报错 重定义默认参数 :参数1,参数2
  
  	system("pause");
  	return 0;
  }
  ```

  

+ 注意
  1. 如果某个位置已经有了默认参数, 那么从这个位置往后,从左往右都必须有默认参数
  2. 默认参数不能被重定义.   如果函数声明有默认参数,函数实现就不能有默认参数. 声明和实现只能有一个默认参数

## 3.2 函数展位参数

C++中函数的形参列表里可以有占位参数,用来做占位,调用函数时,必须填补该位置

语法:`返回值类型 函数名 (数据类型){}`

在现阶段函数的占位参数意义不大,但是后面会用到

```c++
using std::endl;

// 占位参数 形参声明数据类型, 但不声明变量
void func1(int a, int);

// 占位参数 默认值
void func2(int a, int = 10);
int main() {
	system("pause");
	return 0;
}

```

+ 占位参数还可以有默认参数

## 3.3 函数重载

### 3.3.1 函数重载概述

+ 作用: 函数名可以相同, 提高复用性



+ 函数重载满足条件:
  1. 同一个作用域下
  2. 函数名称相同
  3. 函数参数类型不同 或者 个数不同 或者顺序不同
+ 注意: 函数的返回值不能作为函数重载的条件



+ 示例:

  ```c++
  // 声明函数;
  void func();
  void func();// 重复声明
  
  void func(int a);
  
  void func(int a, int);
  
  void func(float a);
  
  void func(double a, int b);
  
  
  
  int main() {
  	func();
  	func(1);
  	func(1, 2);
  	func(2.14f);
  	func(3.14, 2);
  
  	system("pause");
  	return 0;
  }
  
  
  //定义函数
  
  void func(){
  	cout << "param 为空" << endl;
  }
  
  void func(int a) {
  	cout << "参数为int a" << endl;
  }
  
  void func(int a, int) {
  	cout << "参数为int a, int" << endl;
  }
  
  void func(float a) {
  	cout << "参数为float a" << endl;
  }
  
  void func(double a, int b) {
  	cout << "参数为double a, int b" << endl;
  }
  ```

### 3.3.2 函数重载注意事项

+ 引用作为重载条件
+ 函数重载碰到函数默认参数



+ 示例:

  ```c++
  // 函数重载时 ,选用引用 作为参数时的注意事项
  
  void func1(int& a);
  
  void func1(const int& a);
  
  //函数有默认参数时的二义性
  
  void func2(int a);
  
  void func2(int a, int b = 10);
  
  int main() {
  	int a = 10;
  	func1(a);// 相当于 int& a=a; 合法
  
  
  	func1(10);// 相当于 const int& a=10; 合法的,但是第一个函数func(int&a), int& a=10; 不合法
  
  	//func2(10);// 编译器报错,有多个重载函数与之匹配
  
  	func2(10, 12); // func2(int a,int b = 10)
  
  	system("pause");
  	return 0;
  }
  
  void func1(int& a) {
  	cout << "func(int& a)" << endl;
  }
  
  void func1(const int& a) {
  	cout << "func(const int& a)" << endl;
  }
  
  void func2(int a) {
  	cout << "func2(int a)" << endl;
  }
  
  void func2(int a, int b) {
  	cout << "func2(int a,int b = 10)" << endl;
  }
  ```

# 4. 类和对象

+ C++ 面向对象的三大特性为:<mark>封装, 继承, 多态</mark>
+ C++认为 `万事万物皆对象`,对象上有其属性和行为



+ 例如:
  + 人可以做为对象, 属性有姓名, 年龄, 身高,体重
+ 具有相同性质的对象, 我们可以抽象为类, 人属于人类



## 4.1 封装

### 4.1.1 封装的意义

封装时C++面向对象三大特性之一

封装的意义:

+ 将属性和行为作为一个整体,表现生活中事物
+ 将属性和行为 加以权限控制

#### 封装意义一:

​	在设计类的时候,属性和行为写在一起,表现事物

语法:`class 类名{访问权限: 属性/行为};`



+ 示例1: 设计一个圆形类, 求圆的周长

+ 示例代码:

  ```c++
  ```

  
