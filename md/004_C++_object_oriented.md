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

+ C++ 函数中 参数默认都为值引用

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

## 3.2 函数占位参数

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
  // 类的定义, 定义一个圆 类,包括圆的属性和方法, 同时可以计算圆的周长
  class MyCircle {
  	// 访问权限
  	// public 公共权限
  	public:
  		// 圆的半径, 是圆的一个属性
  		int m_r;
  	// 行为
  	//计算圆形的周长
  		double calculatePerimeter() {
  			return 2 * PI * m_r;
  		};
  	private:
  		string shape="round";
  
  };
  
  int main() {
  
  	// 实例化 circle 类
  	MyCircle circle;
  
  	// 类的公共属性 可以 . 的方式来访问, 给实例属性进行赋值
  	circle.m_r = 2;
  
  	cout << circle.calculatePerimeter() << endl;
  		
  
  	system("pause");
  	return 0;
  }
  ```

+ 示例二: 设计一个学生类, 属性有姓名和学号,可以给姓名和学号赋值,可以显示学生的姓名和学号

+ 示例代码:

  ```c++
  using std::cout;
  using std::endl;
  using std::string;
  using std::cin;
  
  // 定义一个学生类, 有姓名和学号属性, 可以给姓名和学号赋值, 可以显示学生的学号
  class Student {
  	public:
  		string s_name;
  		string s_id;
  
  		void setStuName(string name) {
  			s_name = name;
  		};
  		void setStuId(string id) {
  			s_id = id;
  		};
  
  		void showStuInfo() {
  			string type = "";
  			cout << "请输入需要查询的信息, name:学生姓名;id:学生学号;all:姓名和学号" << endl;
  			cin >> type;
  			if (type == "name") {
  				cout << s_name << endl;
  			}
  			else if (type == "id") {
  				cout << s_id << endl;
  			}
  			else if (type == "all") {
  				cout <<"姓名" << s_name << endl;
  				cout <<"学号" << s_id << endl;
  			}
  		};
  
  
  };
  
  
  int main() {
  	Student stu1;
  	stu1.setStuName("张三");
  	stu1.setStuId("114514");
  
  	stu1.showStuInfo();
  
  	system("pause");
  	return 0;
  }
  ```

  

##### 1. C++ 中 类的定义

+ 定义一个类，本质上是定义一个数据类型的蓝图。这实际上并没有定义任何数据，但它定义了类的名称意味着什么，也就是说，它定义了类的对象包括了什么，以及可以在这个对象上执行哪些操作。

  <img src="E:\Learn\006-cpp\img\cpp-classes-objects-2020-12-10-11.png" style="zoom:75%;" />

+ 类定义是以关键字 **class** 开头，后跟类的名称。类的主体是包含在一对花括号中。类定义后必须跟着一个分号或一个声明列表。例如，我们使用关键字 **class** 定义 Box 数据类型，如下所示：

  ```c++
  class Box
  {
     public:
        double length;   // 盒子的长度
        double breadth;  // 盒子的宽度
        double height;   // 盒子的高度
  };
  ```

+ 关键字 **public** 确定了类成员的访问属性。在类对象作用域内，公共成员在类的外部是可访问的。您也可以指定类的成员为 **private** 或 **protected**

##### 2. 定义C++ 中的对象 (类似 js中的 实例对象的概念)

+ 类提供了对象的蓝图，所以基本上，对象是根据类来创建的。声明类的对象，就像声明基本类型的变量一样。下面的语句声明了类 Box 的两个对象：

  ```c++
  Box Box1;          // 声明 Box1，类型为 Box
  Box Box2;          // 声明 Box2，类型为 Box
  ```

+ 对象 Box1 和 Box2 都有它们各自的数据成员。

##### 3. 访问数据成员

+ 类的对象的公共数据成员可以使用直接成员访问运算符 **.** 来访问。

  ![](E:\Learn\006-cpp\img\cpp-classes-objects-2020-12-10-11-2.png)

+ 需要注意的是，私有的成员和受保护的成员不能使用直接成员访问运算符 (.) 来直接访问。我们将在后续的教程中学习如何访问私有成员和受保护的成员。

#### 封装意义二:

+ 据封装是面向对象编程的一个重要特点，它防止函数直接访问类类型的内部成员。类成员的访问限制是通过在类主体内部对各个区域标记 **public、private、protected** 来指定的。关键字 **public、private、protected** 称为访问修饰符。
+ 一个类可以有多个 public、protected 或 private 标记区域。每个标记区域在下一个标记区域开始之前或者在遇到类主体结束右括号之前都是有效的。成员和类的默认访问修饰符是 private。

+ 访问权限有三种:

  1. public 公共          成员 类内可以访问, 类外(实例)可以访问
  2. private 私有        成员 类内可以访问,类外不可以访问
  3. protected 保护   成员 类内可以访问,类外不可以访问

+ 三种权限的区别:

  | 类型      |                                                              |      |
  | --------- | ------------------------------------------------------------ | ---- |
  | public    | **公有**成员在程序中类的外部是可访问的。可以不使用任何成员函数来设置和获取公有变量的值 |      |
  | private   | **私有**成员变量或函数在类的外部是不可访问的，甚至是不可查看的。**只有类和友元函数可以访问私有成员**。默认情况下，类的所有成员都是私有的。如果没有使用任何访问修饰符，类的成员将被假定为私有成员 |      |
  | protected | **protected（受保护）**成员变量或函数与私有成员十分相似，但有一点不同，protected（受保护）成员在派生类（即子类）中是可访问的。 |      |

  ## 继承中的特点

  有public, protected, private三种继承方式，它们相应地改变了基类成员的访问属性。

  - 1.**public 继承：**基类 public 成员，protected 成员，private 成员的访问属性在派生类中分别变成：public, protected, private
  - 2.**protected 继承：**基类 public 成员，protected 成员，private 成员的访问属性在派生类中分别变成：protected, protected, private
  - 3.**private 继承：**基类 public 成员，protected 成员，private 成员的访问属性在派生类中分别变成：private, private, private

  但无论哪种继承方式，上面两点都没有改变：

  - 1.private 成员只能被本类成员（类内）和友元访问，不能被派生类访问；
  - 2.protected 成员可以被派生类访问。

+ 示例:

  ```c++
  using std::cout;
  using std::endl;
  using std::string;
  using std::cin;
  
  // 类的 权限标识符 public private protected
  //一个类可以有多个 public、protected 或 private 标记区域。
  //每个标记区域在下一个标记区域开始之前或者在遇到类主体结束右括号之前都是有效的。成员和类的默认访问修饰符是 private。
  
  class PermissionClass {
  	// public 公共 成员可以被 类内 和 实例访问
  	string s_age;// 默认为私有类型
  public:
  	string s_name;
  
  private:
  	string s_id;
  
  protected:
  	int s_money;
  
  public:
  	// 类内 可以访问 任意该内中成员, 包括 public, private, protected
  	void setDefault() {
  		s_name = "张三";
  		s_id = "114514";
  		s_money = 115;
  	};
  };
  
  int main() {
  	PermissionClass class1;
  	class1.s_name = "11";// 类外 只能访问public
  	//class1.s_age = "123";//编译器报错, 成员 PermissionClass::s_age 不可访问
  	//class1.s_id = "123";// 编译器报错, s_id成员不可访问
  	//class1.s_money = 123;// 编译器报错, s_money成员不可访问
  	system("pause");
  	return 0;
  }
  ```

  

### 4.1.2 struct 和 class 的区别

+ 在C++ 中 struct 和 class 唯一区别就在于默认的访问权限不同

  1. class 的默认权限为 private
  2. struct的默认权限为 public

+ 示例:

  ```c++
  using std::cout;
  using std::cin;
  using std::endl;
  
  // class 的成员 默认属性为 private
  class test01 {
  	int m_r;
  };
  //struct为 public
  struct test02 {
  	int m_r;
  };
  
  int main() {
  	test01 test01;
  	//test01.m_r;// 成员 "test01::m_r" 不可访问
  	test02 test02;
  	test02.m_r = 2;
  
  
  	system("pause");
  	return 0;
  }
  ```

### 4.1.3 将成员属性设为私有

+ 优点:
  1. 将所有成员属性设置为私有,可以自己控制读写权限
  2. 对于写权限,我们可以检测数据的有效性

```c++
// 设置 class 中的 成员属性设为私有
// 1.可以控制成员属性的读写
// 2.对于写权限,可以检测数据的有效性

class Person {
public:
	void setName(string name) {
		p_name = name;
	};
	void getName() {
		cout << p_name << endl;
	};
	void getAge() {
		cout << (p_age ? 0 : p_age) << endl;
	};
	void setSex(int sex) {
		p_sex = sex == 1 ? "男" : "女";
	}



private:
	string p_name;// 可读可写
	int p_age;// 只读
	string p_sex;// 只写
};

int main() {
	Person person;
	person.setName("张三");
	person.setSex(1);
	person.getAge();
	person.getName();
	system("pause");
	return 0;
}
```

#### 实例1: 设计立方体类

设计立方体类(Cube);

求出立方体的面积和体积

分别用全局函数和成员函数判断两个立方体是否相等

+ ```c++
  #include<iostream>
  
  using std::cout;
  using std::endl;
  using std::string;
  
  // 建造一个立方体类
  class Cube {
  public:
  	// set
  	void setLength(int length) {
  		c_L = length;
  	};
  	void setWidth(int width) {
  		c_W = width;
  	};
  	void setHeight(int height) {
  		c_H = height;
  	};
  	// get
  	int getLength() {
  		return c_L;
  	};
  	int getWidth() {
  		return c_W;
  	};
  	int getHeight() {
  		return c_H;
  	};
  	int getArea() {
  		return(c_L * c_H + c_L * c_W + c_W * c_H) * 2;
  	};
  	int getBulk() {
  		return c_L * c_W * c_H;
  	};
  	// 比较两个立方体是否相等的成员方法
  	bool isSamec1(Cube& c1, Cube& c2) {
  		// 引用传递
  		return c1.getWidth() == c2.getWidth() && c1.getLength() == c2.getLength() && c1.getHeight() == c2.getHeight();
  
  	}
  
  
  
  private:
  	int c_L=0;
  	int c_W=0;
  	int c_H=0;
  };
  
  // 比较两个立方体是否相等的全局方法
  bool isSamec1(Cube c1, Cube c2) {
  	// 值传递
  	return c1.getWidth() == c2.getWidth() && c1.getLength() == c2.getLength() && c1.getHeight() == c2.getHeight();
  
  }
  
  int main() {
  	Cube c1;
  	c1.setWidth(10);
  	c1.setHeight(10);
  	c1.setLength(10);
  	Cube c2;
  	c2.setWidth(10);
  	c2.setHeight(10);
  	c2.setLength(10);
  	Cube c3;
  	c3.setWidth(10);
  	c3.setHeight(10);
  	c3.setLength(12);
  	cout << "长:" << c1.getLength() << endl;
  	cout << "宽:" << c1.getWidth() << endl;
  	cout << "高:" << c1.getHeight() << endl;
  	cout << "面积:" << c1.getArea() << endl;
  	cout << "体积:" << c1.getBulk() << endl;
  	cout << (isSamec1(c1, c2) ? "相等" : "不相等") << endl;// 相等
  	cout << (c1.isSamec1(c1, c3) ? "相等" : "不相等") << endl;// 不相等
  	system("pause");
  	return 0;
  }
  ```

#### 实例二: 点和圆的关系 (类文件声明和拆分)

+ 类的声明, 类的文件拆分和引用

```c++
#include<iostream>
using std::cout;
using std::endl;
using std::string;

// 定义一个 point 类, 包含 x和y 的坐标
class Point {

public:
	// 设置 x,y
	void setPointX(int x) {
		m_X = x;
	};
	void setPointY(int y) {
		m_Y = y;
	};

	// 读取 x,y
	int getPointX() {
		return m_X;
	};
	int getPointY() {
		return m_Y;
	};
private:
	int m_X;
	int m_Y;
};


// circle 类 包含 圆心 和 半径
class Circle {
public:
	// 设置半径和圆心
	void setRadius(int r) {
		m_R = r;
	}
	void setCenter(Point& p) {
		m_C = p;
	}

	// 读取圆心和半径
	int getRadius() {
		return m_R;
	}
	Point& getCenter() {
		return m_C;
	}


private:
	int m_R;
	Point m_C;
};

// 全局函数,用于判断 点和圆的位置关系
void getPointAndCircleDistance(Circle& c, Point& p) {
	int p_X = p.getPointX();
	int p_Y = p.getPointY();

	int c_R = c.getRadius();
	Point c_P = c.getCenter();
	int c_X = c_P.getPointX();
	int c_Y = c_P.getPointY();

	int distance = (p_X - c_X) * (p_X - c_X)+(p_Y-c_Y)*(p_Y - c_Y);

	if (distance > (c_R * c_R)) {
		cout << "点在圆外" << endl;
	}
	else if (distance == (c_R * c_R)) {
		cout << "点在圆上" << endl;
	}
	else
	{
		cout << "点在圆内" << endl;
	}
};

int main() {
	// 1.0设置圆类
	Circle c1;
	c1.setRadius(10);
	// 1.1设置圆心点
	Point p1;
	p1.setPointX(10);
	p1.setPointY(0);
	c1.setCenter(p1);
	
	// 设置点
	Point p2;
	p2.setPointX(10);
	p2.setPointY(10);
	getPointAndCircleDistance(c1, p2);

	system("pause");
	return 0;
}
```

+ 拆分文件版本

  **main.cpp**

  ```c++
  #include<iostream>
  #include "circle.h"
  using std::cout;
  using std::endl;
  using std::string;
  
  // 全局函数,用于判断 点和圆的位置关系
  void getPointAndCircleDistance(Circle& c, Point& p) {
  	int p_X = p.getPointX();
  	int p_Y = p.getPointY();
  
  	int c_R = c.getRadius();
  	Point c_P = c.getCenter();
  	int c_X = c_P.getPointX();
  	int c_Y = c_P.getPointY();
  
  	int distance = (p_X - c_X) * (p_X - c_X)+(p_Y-c_Y)*(p_Y - c_Y);
  
  	if (distance > (c_R * c_R)) {
  		cout << "点在圆外" << endl;
  	}
  	else if (distance == (c_R * c_R)) {
  		cout << "点在圆上" << endl;
  	}
  	else
  	{
  		cout << "点在圆内" << endl;
  	}
  };
  
  int main() {
  	// 1.0设置圆类
  	Circle c1;
  	c1.setRadius(9);
  	// 1.1设置圆心点
  	Point p1;
  	p1.setPointX(10);
  	p1.setPointY(0);
  	c1.setCenter(p1);
  	
  	// 设置点
  	Point p2;
  	p2.setPointX(10);
  	p2.setPointY(10);
  	getPointAndCircleDistance(c1, p2);
  
  	system("pause");
  	return 0;
  }
  ```

  **circle.h**

  ```c++
  #pragma once
  #include "pointer.h"
  class Circle {
  public:
  	// 设置半径和圆心
  	void setRadius(int r);
  	void setCenter(Point& p);
  
  	// 读取圆心和半径
  	int getRadius();
  	Point& getCenter();
  private:
  	int m_R;
  	Point m_C;
  };
  ```

  **Circle.cpp**

  ```c++
  #include "circle.h"
  // 设置半径和圆心
  void Circle::setRadius(int r) {
  	m_R = r;
  }
  void Circle::setCenter(Point& p) {
  	m_C = p;
  }
  
  // 读取圆心和半径
  int Circle::getRadius() {
  	return m_R;
  }
  Point& Circle::getCenter() {
  	return m_C;
  }
  ```

  **point.h**

  ```c++
  #pragma once
  #include<iostream>
  using std::cout;
  using std::endl;
  using std::string;
  
  
  // 定义一个 point 类, 包含 x和y 的坐标
  class Point {
  
  public:
  	// 设置 x,y
  	void setPointX(int x);
  	void setPointY(int y);
  
  	// 读取 x,y
  	int getPointX();
  	int getPointY();
  private:
  	int m_X;
  	int m_Y;
  };
  
  ```

  **Pointer.cpp**

  ```c++
  #include "pointer.h"
  // 设置 x,y
  void Point::setPointX(int x) {
  	m_X = x;
  };
  void Point::setPointY(int y) {
  	m_Y = y;
  };
  
  // 读取 x,y
  int Point::getPointX() {
  	return m_X;
  };
  int Point::getPointY() {
  	return m_Y;
  };
  ```




### 4.1.4 类的成员函数的声明和定义 ,以及类中的函数调用

+ 成员函数可以定义在类定义内部，或者单独使用**范围解析运算符 ::** 来定义。在类定义中定义的成员函数把函数声明为**内联**的，即便没有使用 inline 标识符。

+ class 内部定义函数(内联)

  ```c++
  // 内部定义函数
  class Box1 {
  public:
  	// 类 内部定义函数 getVolume
  	double getVolume(void) {
  		return length * width * height;
  	};
  private:
  	double length;
  	double width;
  	double height;
  };
  
  ```

+ class 内部声明,外部通过**范围解析运算符** 来定义内中函数, (类中函数需要事先声明)

  ```c++
  // 类 外部 通过范围**解析运算符** 来定义内中函数, 类中函数需要事先声明
  class Box2 {
  public:
  	// 类 内部定义函数 getVolume
  	double getVolume(void);
  private:
  	double length;
  	double width;
  	double height;
  };
  double Box2::getVolume(void) {
  	return length * width * height;
  };
  ```

  

## 4.2 对象的初始化和清理

+ 生活中我们买的电子产品都基本会有出厂设置,在某一天不用的时候也会删除一些自己的信息数据保证安全
+ C++ 面向对象来源于生活,每个对象也都会有初始设置以及对象销毁前的清理数据的设置



### 4.2.1 构造函数和折构函数(js中class的constructor和这个构造函数一个概念)

+ 类的构造函数是一种特殊的函数，在创建一个新的对象时调用。类的析构函数也是一种特殊的函数，在删除所创建的对象时调用。

+ 对象的**初始化和清理**也是两个非常重要的安全问题
  + 一个对象或者变量没有初始状态, 对其使用后果是未知
  + 同样的使用完一个对象或变量,没有及时清理,也会造成一定的安全问题



+ C++ 利用了**构造函数** 和 **折构函数**解决上述问题,这两个函数将会被编译器自动调用,完成对象初始化和清理工作.对象的初始化和清理工作是编译器强制要求我们做的事情,因此**如果我们不提供构造函数和折构函数,编译器会提供编译器提供的构造函数和折构函数是空实现**



+ 构造函数: 主要作用在于创建对象时为对象的成员属性赋值,构造函数由编译器自动调用,无须手动调用
+ 折构函数: 主要用于在于对象那个销毁前系统自动调用,执行一些清理工作

+ **构造函数语法:**`类名(){}`

  1. 构造函数,没有返回值也不写void
  2. 函数名称与类名相同
  3. 构造函数可以有参数,因此可以发生重载
  4. 程序在调用对象时候会自动调用构造函数,无序手动调用,而且只会调用一次

+ **析构函数语法:**`~类名(){}`

  1. 析构函数,没有返回值也不写void
  2. 函数名称与类名相同,在名称前加上符号`~`
  3. 析构函数不可以有参数,因此不可以发生重载
  4. 程序在对象销毁前会自动调用析构函数,无须手动调用,而且只会调用一次

  ```c++
  using std::cout;
  using std::endl;
  using std::string;
  
  
  // 1.构造函数 进行初始化的操作
  //1. 构造函数,没有返回值也不写void
  //2. 函数名称与类名相同
  //3. 构造函数可以有参数, 因此可以发生重载
  //4. 程序在调用对象时候会自动调用构造函数, 无序手动调用, 而且只会调用一次
  
  class Constructor {
  public:
  	Constructor() {
  		cout << "构造函数被调用" << endl;
  	}
  	/*1. 析构函数 进行清理的操作
  	1. 析构函数,没有返回值也不写void
  	2. 函数名称与类名相同,在名称前加上符号`~`
  	3. 析构函数不可以有参数,因此不可以发生重载
  	4. 程序在对象销毁前会自动调用析构函数,无须手动调用,而且只会调用一次
  	*/
  	~Constructor() {
  		cout << "析构函数被调用" << endl;
  	}
  };
  
  // 构造和析构都是必须有的实现,如果我们不提供,编译器会提供一个空实现的构造和析构
  void test01() {
  	Constructor c;// 局部变量,在栈区的数据,test01 执行完毕后,释放这个对象
  }
  
  void main() {
  	//test01();// 局部变量 中的对象C 会在函数 执行完毕后被释放
  	// 在main 函数中也需要等到main函数执行完毕后才能 执行析构和构造,所以比较难观察到
  	Constructor c;
  
  
  	system("pause");
  }
  ```

  

#### 1. 类的 构造函数

+ 类的**构造函数**是类的一种特殊的成员函数，它会在每次创建类的新对象时执行。

  **构造函数的<mark>名称与类的名称是完全相同的<mark>，并且<mark>不会返回任何类型</mark>，也<mark>不会返回 void</mark>。构造函数可用于为某些成员变量设置初始值**。

### 4.2.2 构造函数的分类以及调用

+ 两种分类方式:

  + 按照参数分类: 有参构造 和 无参构造(默认构造)
  + 按类型分为: 普通构造 和 拷贝构造
  + **拷贝构造函数的作用, 就是赋值 类的值,用于做函数的形参(值引用)或者返回**

+ 三种调用方式

  + 括号法
  + 显示法
  + <a name="隐式转换法">隐式转换法</a>

+ 使用new 来实例化一个class

  ```c++
  Person* p8 = new Person(10);
  ```

  

+ 示例:

  ```c++
  #include<iostream>
  
  
  using std::cout;
  using std::endl;
  using std::string;
  
  // 类中构造函数的分类
  class Person {
  public:
  	// 1. 按照有无参数分类, 有参构造 和 无参构造(无参构造又叫做默认构造, 编译器自动调用的构造函数没有参数)
  
  	//1.1 无参构造
  	Person() {
  		age = 0;
  		cout << "无参构造调用" << endl;
  	}
  	//1.2 有参构造
  	Person(int a) {
  		age = a;
  		cout << "有参构造调用" << endl;
  	}
  
  	//2. 按照类型分为 普通构造 和 拷贝构造
  	//2.1 上述皆为普通构造函数
  
  	//2.2 拷贝构造
  	Person(const Person& p) {
  		age = p.age;
  		cout << "拷贝构造调用" << endl;
  	}
  	~Person()
  	{
  		cout << "析构函数调用" << endl;
  	}
  	int age;
  };
  
  
  
  
  void main() {
  	// 3. 构造函数调用方法 三种
  
  	//1. 括号法
  	Person p1;// 默认构造函数调用
  	Person p2(10);// 有参构造函数调用
  	Person p3(p2);// 拷贝构造函数调用
  	//Person p4()
  	// 注意点1:不能使用着这种方法来调用构造函数, 因为编译器认为这是一个 返回Person类的函数声明,而不会认为在创建(实例化)一个对象
  
  	//2.显示法
  	Person p5;
  	Person p6 = Person(10);// 有参构造
  	Person p7 = Person(p6);// 拷贝构造
  
  	// Person(10) ; 
  	//匿名对象 特点: 当前执行结束后,系统会立即回收掉匿名对象
  
  	// 注意点2:
  	// 不要用拷贝构造函数来初始化一个匿名对象 
  	//Person(p7);// 报错 p7 重定义 
  	// 编译器会认为 Person(p7) 等价于 Person p7(对象声明,即在实例化一个 p3的Person实例对象)
  	Person* p8 = new Person(10); // 使用new 创建指针变量p8 来接收class实例对象
  	cout<< p8->age <<endl;// 10
  
  	//3. 隐式转换法
  	Person p10 = 10;// 相当于 Person p10 = Person(10);
  	Person p11 = p10;// 相当于 Person p11=Person(p10);
  	system("pause");
  }
  ```

+ 注意事项:
  1. `Person p4()`
     + 不能使用着这种方法来调用构造函数, 因为编译器认为这是一个 返回Person类的**函数声明**,而不会认为在创建(实例化)一个对象
  2. `Person(p7)`
     + 编译器会认为 Person(p7) 等价于 Person p7(对象声明,即在实例化一个 p3的Person实例对象)

### 4.2.3 拷贝构造函数调用时机

+ C++ 中拷贝构造函数 调用时机通常有三种情况

  + 使用一个已经创建完毕的对象来初始化一个新对象
  + 值传递的方式给函数参数传参
  + 以值方式返回局部变量

+ 示例:

  ```c++
  #include<iostream>
  using std::cout;
  using std::endl;
  using std::string;
  
  
  // 拷贝构造函数被调用的时机
  /*
  	1. 使用一个已经创建完毕的对象来初始化一个新对象
  	2. 值传递的方式给函数参数传参
  	3. 以值方式返回局部变量
  */
  
  class Person {
  public:
  	int m_age;
  	//1. 默认构造
  	Person() {
  		m_age = 0;
  		cout << "无参构造被调用" << endl;
  	}
  	//2.有参构造
  	Person(int age) {
  		m_age = age;
  		cout << "有参构造被调用" << endl;
  	}
  	//3. 拷贝构造函数
  	Person(const Person& p) {
  		cout << "拷贝构造函数被调用" << endl;
  		m_age = p.m_age;
  	}
  	// 4. 析构函数
  	~Person() {
  		cout << "析构函数被调用" << endl;
  	}
  private:
  	
  };
  
  // 1. 使用一个已经创建完毕的对象来初始化一个新对象, 类会自动调用拷贝构造函数
  void test01() {
  	Person p1(10);// 有参构造函数被调用
  	Person p2(p1);// 拷贝构造函数被调用
  	cout << "p1.m_age: " << p1.m_age << endl;
  	cout << "p2.m_age: " << p2.m_age << endl;
  }
  // 2.值传递的方式给函数参数传参,类会自动调用拷贝构造函数
  void doWork(Person p) {
  
  }
  
  void test02() {
  	Person p3(10);// 有参构造被调用
  	doWork(p3);// 拷贝构造函数被调用  函数形参接收到参数时,进行了隐式调换 ,类似于 void doWork(Perosn p=p3), 为构造函数的隐式转换法
  	// 函数形参 值传递时发生的动作为,将变量的值 赋值给这个局部变量形参
  	// 声明函数,加上形参默认值 void doWork(Person p= Person p4(10)); 当传入参数p3 时,顶替掉即可void doWork(Person p= p3); 构造函数的隐式转换法写法
  }
  
  //3. 以值方式返回局部变量, 类会自动调用 拷贝构造函数
  Person doWork02() {
  	Person p1;// 无参构造被调用
  	cout <<(int*) & p1 << endl;
  	return p1;
  }
  
  void test03() {
  	Person p4 = doWork02();// 拷贝构造被调用
  	// 涉及到类的值被调用的, 都会自动调用 拷贝构造函数
  	cout << (int*) & p4 << endl;
  }
  
  void main() {
  	//test01();
  	//test02();
  	test03();
  	system("pause");
  }
  ```

  

### 4.2.3 构造函数调用规则

+ 默认情况下,c++编译器至少给一个类添加3个函数

  1. 默认构造函数(无参, 函数体为空)
  2. 默认析构函数(无参,函数体为空)
  3. 默认拷贝构造函数,对属性进行值拷贝

+ 构造函数调用规则如下:

  + 如果用户有定义有参构造函数,c++ 不在提供默认的无参构造,但是会提供默认拷贝构造
  + 如果用户定义拷贝构造函数,c++不会再提供其他构造函数

+ 示例:

  ```c++
  #include <iostream>
  
  using std::cout;
  using std::endl;
  using std::string;
  
  class Person {
  public:
  	int m_Height = 0;
  	// 默认构造 default constructor
  	Person() {
  		cout << "调用了默认构造" << endl;
  	};
  	// 有参构造 构造函数的重载
  	Person(int h) {
  		m_Height = h;
  		cout << "调用了有参构造" << endl;
  	};
  	// 拷贝构造 构造函数重载
  	Person(const Person& p) {
  		m_Height = p.m_Height;
  		cout << "调用了拷贝构造" << endl;
  	};
  	//析构函数 destructor
  	~Person() {
  		cout << "调用了析构函数" << endl;
  	};
  };
  
  //1.如果用户有定义有参构造函数,c++ 不在提供默认的无参构造,但是会提供默认拷贝构造
  void test01(); //函数声明
  //2.如果用户定义拷贝构造函数,c++不会再提供其他构造函数
  void test02();
  int main() {
  	test01();
  
  
  	system("pause");
  	return 0;
  }
  
  void test01() {
  	//Person p1;//语法错误!  如果用户定义拷贝构造函数,编译器不会再提供默认构造
  	Person p1(20);// 调用了有参构造
  	Person p2(p1);// 调用了拷贝构造
  	// 如果只写了有参构造, 编译器 会自动执行一个值传递的拷贝构造
  	cout << "p2实例的1m_Height:" << p2.m_Height << endl;
  }
  
  void test02() {
  	//Person p1;//语法错误!  如果用户定义拷贝构造函数,编译器不会再提供默认构造
  }
  ```
  

### 4.2.5 深拷贝和 浅拷贝

+ 浅拷贝: 简单的赋值拷贝操作
+ 深拷贝:在堆区重新申请空间,进行拷贝操作



+ 示例:

  ```c++
  #include <iostream>
  
  using std::cout;
  using std::endl;
  using std::string;
  
  // 1. class 中的 拷贝构造函数默认为 浅拷贝, 利用new来开辟 堆区地址进行 深拷贝
  class Person {
  public:
  	int m_Height;
  	int* m_age;// int 类型的指针变量
  	Person(int h,int a) {
  		m_Height = h;
  		m_age = new int(a);
  		cout << "有参构造函数的调用" << endl;
  	}
  	Person(const Person& p) {
  		m_Height = p.m_Height;
  		//m_age = p.m_age;// 拷贝函数提供的就是类似于这种浅拷贝, 使用的变量来自于一个地址
  		m_age = new int (*p.m_age);// 重新开辟一个堆区来存放值
  		cout << "拷贝构造函数的调用" << endl;
  	}
  	~Person() {
  		if (m_age != NULL) {
  			delete m_age;// new 开辟的空间需要手动释放
  			m_age = NULL;// 防止野指针
  		}
  		cout << "destructor 的调用" << endl;
  	}
  };
  void test01();
  
  
  int main() {
  	test01();
  	system("pause");
  	return 0;
  }
  void test01() {
  	Person p1(180, 20);
  	cout << "p1的身高:" << p1.m_Height << "\np1的年龄:" << *p1.m_age << endl;
  	Person p2(p1);
  	cout << "p2的身高:" << p2.m_Height << "\np2的年龄:" << *p2.m_age << endl;
  }
  ```

### 4.2.6 初始化列表

+ 作用:

  C++ 提供了初始化列表语法,用来初始化属性

+ 语法: `构造函数():属性1(值1),属性2(值2){}`

+ 示例:

  ```c++
  #include <iostream>
  
  using std::cout;
  using std::endl;
  using std::string;
  
  class Person {
  public:
  	int m_A;
  	int m_B;
  	int m_C;
  	// 传统的初始化赋值
  	/*Person(int a, int b,int c) {
  		m_A = a;
  		m_B = b;
  		m_C = c;
  	};*/
  	// 使用初始化列表进行初始化赋值
  	/*Person() :m_A(10), m_B(20), m_C(30) {
  
  	};*/
  	Person(int a,int b,int c) :m_A(a), m_B(b), m_C(c) {
  
  	};
  };
  
  
  void test01();
  int main() {
  	test01();
  	system("pause");
  	return 0;
  }
  void test01() {
  	Person p1(10, 20, 30);
  	//Person p1;
  	cout << "m_A: " << p1.m_A << endl;
  	cout << "m_B: " << p1.m_B << endl;
  	cout << "m_C: " << p1.m_C << endl;
  
  }
  ```

### 4.2.7 类对象作为类成员

+ C++ 类中的成员可以是另外一个类的对象, 我们称该对象为对象成员

+ 例如:

  ```c++
  ```

+ B类中,有对象A作为 对象成员,

+ 那么创建B对象时,A与B的构造和析构函数执行顺序是怎样的?

+ 结论:

  1. 构造时, 先执行 **对象成员**里的**构造函数**, 再执行**类本身**的**构造函数**
  2. 析构时, 先执行**本身**的**析构函数**,再执行 对象成员的构造函数

+ 示例:

  ```c++
  #include <iostream>
  
  using std::cout;
  using std::endl;
  using std::string;
  
  // 一个类的成员 可以是另外一个对象, 这个成员 是一个 对象成员
  class Phone {
  public:
  	string m_Number;
  	// 默认 constructor
  	Phone() {
  		cout << "class Phone默认构造函数" << endl;
  	};
  	// 有参 contructor
  	Phone(string s) {
  		m_Number = s;
  		cout << " class Phone有参构造被调用" << endl;
  	}
  	// 拷贝 constructor
  	Phone(const Phone& p) {
  		m_Number = p.m_Number;
  		cout << " class Phone拷贝构造被调用" << endl;
  	}
  	// destructor
  	~Phone() {
  		cout << " class Phone析构函数被调用" << endl;
  	}
  };
  
  class Person {
  public:
  	
  	// 默认 constructor
  	Person(){
  		cout << "class Person 默认构造函数" << endl;
  	}
  	// 有参 constructor
  	Person(int a,string n):m_Age(a) ,m_Phone(n) {
  		cout << "class Person 有参构造被调用" << endl;
  	}
  	// 拷贝 constructor
  	Person(const Person& p) {
  		m_Age = p.m_Age;
  		m_Phone = p.m_Phone;
  		cout << "class Person 拷贝构造被调用" << endl;
  	}
  	// destructor
  	~Person() {
  		cout << "class Person 析构函数被调用" << endl;
  	}
  	int m_Age;
  	Phone m_Phone;
  
  };
  void test01();
  
  int main() {
  	test01();
  	system("pause");
  	return 0;
  }
  void test01() {
  	Person p(20,"17673942507");
  	// 构造时, 先执行 对象成员里的构造函数, 再执行类本身的构造函数
  	//析构时, 先执行本身的析构函数,再执行 对象成员的构造函数
  	cout << p.m_Age << p.m_Phone.m_Number << endl;
  }
  
  ```

### 4.2.8 静态成员(类js的class, 不过C++ static可以被实例访问)

+ 静态成员就是在成员变量和成员函数前加上关键字static,称之为**静态成员**

+ 静态成员分为:
  + 静态成员变量
    + 所有对象共享同一份数据(可以通过类访问 `ClassName::staticMember`)
    + 在编译阶段分配内存
    + 类内声明,类外初始化
  + 静态成员函数
    + 所有成员共享同一个函数
    + 静态成员函数只能访问静态成员变量
  
+ 静态成员,本质是定义在class上的,只有一份地址, 实力访问修改的都是同一份地址数据. 也和普通成员一样受到public, private,protect等权限修饰符的影响
  
+ 示例: 静态成员变量

  ```c++
  //所有对象共享同一份数据(可以通过类访问 `ClassName::staticMember`)
      //在编译阶段分配内存
      //类内声明, 类外初始化
  class Person {
  public:
  	static int m_Age;// class 内声明
  private:
  	static int m_Width;// static 也会有权限区分
  
  };
  
  
  //class外 初始化
  int Person::m_Age = 20;
  
  void test01();
  
  
  int main() {
  	test01();
  	system("pause");
  	return 0;
  }
  void test01() {
  	//1.int Person::m_Age = 20;// error 当前范围无法定义成员 Person::m_Age
  	Person p;
  	cout <<"p.m_Age: " << p.m_Age << endl;//20
  	Person p2;
  	cout << "p2.m_Age: " << p2.m_Age << endl;//20
  	// 2.静态成员是属于类的私有成员,在对象之间是共享同一份数据的,  和js不同的是,c++中的类示例是可以访问 静态成员的
  	p2.m_Age = 40;
  	cout << "p.m_Age: " << p.m_Age << endl;//40
  
  	//3. class中定义的 static 成员 本质上是定义在 该类上的, 实例对象访问修改的都是同一份数据,可以通过类来访问, 同时 static也是有区分 public,private,protect权限的
  	cout << Person::m_Age << endl;//40
  	//cout << Person::m_Width << endl; static有权限
  
  }
  ```

+ 示例: 静态成员函数

  ```c++
  //所有成员共享同一个函数
  //静态成员函数只能访问静态成员变量
  class Person {
  public:
  	static int a;
  	int b;
  	static void func01(int b) {
  		a = b;
  		// 静态成员只能访问 静态变量, 因为静态成员的数据只存在一份, 而访问 普通变量时,该普通变量是根据类定义的实例来变化的,有多个地址上存在了 该普通变量,肯定是不允许访问和修改的
  		//cout << b << endl;//静态成员函数 不允许读取普通变量
  		//b = 20;//静态成员函数 不允许修改普通变量
  	}
  private:
  	static void func02();// 静态成员和普通成员一样,收到权限修饰符的影响
  };
  
  int Person::a = 20;
  //int Person::func02(){}// 不能访问 private
  
  void test01();
  
  
  int main() {
  	test01();
  	system("pause");
  	return 0;
  }
  void test01() {
  	Person p;
  	cout << "p.a: " << p.a << endl;//20 通过 实力访问
  	cout << "Peson::a :" << Person::a << endl;//20 通过类访问
  
  	// 实例访问 static memeber function
  	p.func01(30);
  	cout << "p.a: " << p.a << endl;//30 通过 实力访问
  	cout << "Peson::a :" << Person::a << endl;//30 通过类访问
  
  	// 类 本身访问 static member function
  	Person::func01(100);
  	cout << "p.a: " << p.a << endl;//100 通过 实力访问
  	cout << "Peson::a :" << Person::a << endl;//100 通过类访问
  }
  ```

  

## 4.3 C++ 对象模型和 this指针

### 4.3.1 成员变量和成员函数分开存储

+  在C++中,类内的成员变量和成员函数分开存储

  + 空class 的空对象占用内存大小为 1byte
  + 非静态成员变量 在实例身上
  + 静态成员变量 不在示例对象身上
  + 非静态成员函数,不在实例对象身上
  + 静态成员函数,不在实例对象身上

+ 只有非静态成员变量才属于类的对象上

+ ```c++
  // C++ 类成员按照以下方式划分,只有一种变量 会存在 类的对象(实例) 身上
  class Person {
  	int m_A;// 非静态成员变量 在实例身上
  	static int m_b;// 静态成员变量 不在示例对象身上
  	int func() { return 0; };// 非静态成员函数,不在实例对象身上
  	static int function2() { return 0; };// 静态成员函数,不在实例对象身上
  };
  void test01() {
  	/*class Person {
  
  	};*/
  	Person p;
  	// 空 class的实例 内存占用大小为1个字节,
  	//C++编译器会给每个空对象也分配一个内存空间,是为了区分空对象占内存的地址,每个空对象的地址也不能相同
  	cout << "size of p: " << sizeof(p) << endl;// 1
  }
  
  void test02() {
  	
  	Person p1;
  	// 一旦 class 不为空, 空对象也就不复存在, 原先占用的 1byte空间也就不会存在,而是按照成员里面的非静态成员变量的大小来计算
  	cout << "size of p1: " << sizeof(p1) << endl;// 4
  }
  int main() {
  	test01();
  	test02();
  	system("pause");
  	return 0;
  }
  ```

### 4.3.2 this指针概念

+ C++ 中成员变量 和成员函数是分开存储的
+ 每一个非静态成员函数只会诞生一份函数实例,也就是说多个同类型的对象会共用一份代码
+ 那么问题是:这一块代码是如何区分哪个对象调用自己的呢?



+ C++ 通过提供特殊的对象指针,this指针,解决上述问题,**this指针指向被调用的成员函数所属的对象**



+ this指针是隐含每一个非静态成员函数内的一种指针
+ this指针不需要定义,直接使用即可



+ this指针的用途:

  + 当形参和成员变量同名时,可用this指针来区分
  + 在类的非静态成员函数中返回对象本身,可使用`return *this`(类似于js ,可以用于 链式调用)

+ 理解:

  ```
  this 指针是一个待定的地址变量(指针), 在class中使用它表示的是 实例对象
  ```

+ [this指针 指向 当前实例化对象的原理](https://blog.csdn.net/qq_43915356/article/details/107406167)

  <img src="E:\Learn\006-cpp\img\this指针工作原理.png" style="zoom:100%;" />

  **类中定义的非静态成员函数，编译器会隐式的添加一个形参this，在调用非静态成员函数时编译器会对this传递当前对象的地址，所以在函数中就可以使用this指代当前对象**

```c++
#include <iostream>

using std::cout;
using std::endl;
using std::string;

// this指针的作用
//1. 用于区分同名的形参和成员变量
//2.可以返回return *this(可用于作为链式调用)

class Person {
public:
	int age;
	Person(int age) {
		this->age = age;
		cout << "有参构造被调用" << endl;
	};
	// 链式调用
	Person& addAge(int age) {
		this->age += age;
		return *this;
	}
	// 一定要返回引用, 类似于 return Person& p2=*this, 如果不反悔引用则等同于返回的是 return Person p1=*this, 相当于使用隐式转换法去新建了一个Person实例返回,age的初始值永远都是构造函数中的10
};

void test01() {
	//Person p1;//error 当class中有有参构造时,编译器不再提供默认构造,所以会报错
	Person p1(10);
	cout << p1.age << endl;//10

	Person p2(10);
	cout << p2.age << endl;//10

	p2.addAge(10).addAge(10).addAge(20);
	cout << p2.age << endl;//50
}

int main() {
	test01();
	system("pause");
	return 0;
}
```

+ 注意: 

  ```c++
  // 链式调用
  	Person& addAge(int age) {
  		this->age += age;
  		return *this;
  	}
  ```

+ 该函数要形成链式调要一定要返回引用, 类似于 `return Person& temp=p2,`,引用返回的是p2; 如果不反悔引用则等同于返回的是 `return Person newObj=p2`, 相当于使用**<a href="#隐式转换法">隐式转换法</a>去新建了一个Person实例返回**,age的**初始值**永远都是构造函数中的10

### 4.3.3 空指针访问成员函数	

+ C++ 中空指针也是可以调用成员函数的**,但是也要注意有没有用到this指针**

+ 如果用到this指针,需要加以判断保证代码的健壮性

+ 示例:

  ```c++
  // 空指针在调用 class中的方法时,不能用this来操作属性,因为空指针上没有该属性
  class Person {
  public:
  	int m_Age;
  	static int m_Height;
  	void showClassName() {
  		cout << "this is a Person class" << endl;
  	}
  	void showAge() {
  		// 空指针上 this指针指向是没有m_Age属性成员的;
  		cout << this->m_Age << endl;
  	}
  	void showHeight() {
  		// 空指针上 this指针指向是没有m_Age属性成员的;
  		cout << this->m_Height << endl;
  	}
  };
  
  void test01() {
  	Person* p = NULL;
  	p->showClassName();
  	//p->showAge();//Error 空指针上 this指针指向是没有m_Age属性成员的;
  	//p->showHeight();
  }
  
  int main() {
  	test01();
  	system("pause");
  	return 0;
  }
  ```

### 4.3.4 const 修饰成员函数

**常函数**

+ 成员函数后加const 后我们成称这个函数为**常函数**
+ 常函数内不可以修改成员属性
+ 成员属性声明加关键字mutable后,在常函数中依然可以修改



**常对象**

+ 声明对象前加const 称该对象为常对象
+ 常对象只能调用常函数



+ 示例:

  ```c++
  //常函数
  class Person {
  public:
  	int m_Age;
  	mutable int m_Height;// mutable 修饰成员属性,来指明这是一个可修改的成员属性, 不受到常函数的影响
  	// this 指针的本质是一个指针常量,指针的指向是不可以改变的,永远指向 实例对象
  	// 但是 this指向的值是可以变的
  	void setAge(int age) {
  		this->m_Age = age;
  	}
  	// 通过const加载函数参数后面来修饰this,  将this指针变成一个 常量指针常量, 使得this指向(实例)里面的值也不可被修改
  	void setHeight(int h)const {
  		//this->m_Age = 20;// error要想修改 成员属性, 必须加上mutable
  		this->m_Height = h;//Error, 要想修改 成员属性, 必须加上mutable
  	}
  };
  // 常对象, 本质还是和this指针一回事, 因为this指针指向的就是常对象
  void test01() {
  	const Person p;// 1. 使用const 来修饰一个常对象,  常对象成员属性不能更改, 除非该成员属性前有mutable修饰符号
  	p.setHeight(20);// 常对象只能调用常函数
  	//p.setAge(20);//常对象不能调用普通函数,因为普通函数可以更改属性成员, 而常对象的非mutable成员属性是不允许被更改的,所以常对象只能调用常函数
  }
  int main() {
  	test01();
  	system("pause");
  	return 0;
  }
  ```
  

## 4.4 友元

生活中你的家有客厅(Public),有你的卧室(Private)

客厅所有来的客人都可以进去,但是你的卧室是私有的,也就是说只有你能进去

但是呢,你也可以允许你的好闺蜜好基友进去



在程序里,有些私有属性 也想让类外特殊的一些函数或者类进行访问,就需要用到友元的技术



友元的目的就是让一个函数或者类 访问另一个类中的私有成员

**友元关键字为friend**

友元的三种实现

+ 全局函数做友元
+ 类做友元
+ 成员函数做友元

### 4.4.1 全局函数做友元

```c++
#include <iostream>
#include<math.h>

using std::cout;
using std::endl;
using std::string;
using std::pow;

// 友元函数 友元函数声明的关键字为 friend
class Pointer {
	friend void calcDistance(Pointer* p);
public:
	Pointer(int x,int y):m_X(x),m_Y(y) {
		cout << "有参构造函数被调用" << endl;
	}
private:
	int m_X;
	int m_Y;
	void getDsitance() {
		cout << "坐标距离原点的直线距离为: " << pow((m_X * m_X + m_Y * m_Y),0.5) << endl;
	}
};
void calcDistance(Pointer* p) {
	p->getDsitance();// 友元函数 访问私有属性
};

int main() {
	Pointer p(3,4);
	calcDistance(&p);//5
	system("pause");
	return 0;
}
```

### 4.4.2 友元类

+ 类的声明:
  `class Home;`

+ ```c++
  // 类做友元
  
  
  //声明类
  class Home;
  class GoodFriend {
  public:
  	Home* home;
  	void visit();
  	GoodFriend();
  };
  class Home {
  	friend class GoodFriend;
  public:
  	string m_LivingRoom;
  	Home();
  private:
  	string m_Bedroom;
  };
  Home::Home() {
  	m_LivingRoom = "客厅";
  	m_Bedroom = "卧室";
  }
  GoodFriend::GoodFriend() {
  	home = new Home;
  }
  void GoodFriend::visit() {
  	cout << "home->m_LivingRoom: " << home->m_LivingRoom << endl;
  	cout << "home->m_Bedroom: " << home->m_Bedroom << endl;
  }
  void test01() {
  	GoodFriend gf;
  	gf.visit();
  }
  
  int main() {
  	test01();
  	system("pause");
  	return 0;
  }
  ```

### 4.4.3  成员函数做友元

```c++
class Home;
class GoodFriend {
public:
	GoodFriend();
	void visit();
	void visit2();
	Home* home;
};
class Home {
	friend void GoodFriend::visit();// 声明一个类的成员函数作为另外一个类的友元函数
public:
	Home();
	string m_LivingRoom;
private:
	string m_BedRoom;
};
Home::Home() {
	m_BedRoom = "卧室";
	m_LivingRoom = "客厅";
}
GoodFriend::GoodFriend() {
	home = new Home;
}
void GoodFriend::visit() {
	cout << "visit函数访问m_Living: " << home->m_LivingRoom << endl;
	cout << "visit函数访问m_Bedroom: " << home->m_BedRoom << endl;
}
void GoodFriend::visit2() {
	cout << "visit2函数访问m_Living: " << home->m_LivingRoom << endl;
	//cout << "visit2函数访问m_Bedroom: " << home->m_BedRoom << endl;// error 同一个类的 visit2函数不是 Home的友元函数不能访问
}

void test01() {
	GoodFriend gf;
	gf.visit();
	gf.visit2();
}
int main() {
	test01();
	system("pause");
	return 0;
}
```

## 4.5 运算符重载

+ 运算符重载概念: 对已有的运算符重新进行定义,赋予其另一种功能,以适应不同的数据类型

+ 运算符重载时, 第一个参数 为重载符号前面的位置,第二个参数为 重载符号 后面的参数,如下:

  ```c++
  int operator+(int param1,double param2);
  // 使用重载 + 时
  int a=1;
  double b=2.13;
  
  cout<< 1+2.13 <<endl;
  ```

  

### 4.5.1 加号运算符重载

+ class 成员函数实现 + 号运算符重载
+ 全局函数实现 + 号运算符重载
+ 运算符可以重载多次,(但不能对已有的数据类型进行重载)

+ 对 + 号运算符号进行重载的本质是对函数名为 `operator+;`的函数进行重载

```c++
using std::cout;
using std::endl;
using std::string;
// 对 + 号运算符进行重载
// 1. class 成员函数 运算符重载
class Home {
public:
	int m_A;
	int m_B;
	Home() :m_A(10), m_B(10) {
		cout << "Home 无参构造被调用, 无参构造创建未被声明时将不能再使用, 但拷贝构造依旧会自动调用" << endl;
	}
	Home(int a, int b) :m_A(a), m_B(b) {
		cout << "Home 有参构造被调用, 无参构造创建未被声明时将不能再使用, 但拷贝构造依旧会自动调用" << endl;
	}
	Home operator+(const Home& h) {
		Home home;
		home.m_A = h.m_A + m_A;
		home.m_B = h.m_B + m_B;
		return home;
	}
};


// 1.调用重载加号运算符的成员函数
void test01() {
	Home h1;
	Home h2;
	Home h3 = h1 + h2;
	// 相当于,  这是一种语法糖
	//Home h3 = h1.operator+(h2)
	cout << h3.m_A << "    " << h3.m_B << endl;// 20  20
}

// 2.调用全局函数 进行运算符重载
Home operator-(const Home& h1, const Home& h2) {
	Home home;
	home.m_A = h1.m_A - h2.m_A;
	home.m_B = h1.m_B - h2.m_B;
	return home;
}

void test02() {
	Home h1(30, 30);
	Home h2(30, 30);
	Home h3 = h1 - h2;
	//相当于
	//Home h3 =operator-(h1,h2);
	cout << h3.m_A << "    " << h3.m_B << endl;// 0  0
}

// 3.对已经重载过的 operaotr- 进行再次重载
Home operator-(const Home& h1, int a) {
	Home home;
	home.m_A = h1.m_A - a;
	home.m_B = h1.m_B - a;
	return home;
}
void test03() {
	Home h1(30, 30);
	Home h3 = h1 -40 ;
	//相当于
	//Home h3 =operator-(h1,h2);
	cout << h3.m_A << "    " << h3.m_B << endl;// -10  -10
}
int main() {
	test01();
	test02();
	test03();
	system("pause");
	return 0;
}
```

### 4.5.2 左移运算符重载

+ cout 是属于 ostream中的一个实例, 全局中只能有 一个ostream实例,所以要使用引用

```c++
using namespace std;

// 左移运算符 重载  可能不适用 于成员函数,使用 全局函数进行重载
class Person {
public:
	int m_A;
	int m_B;
	Person() :m_A(10), m_B(20) {
		cout << "无参构造函数被调用" << endl;
	}
};

// 全局函数重载左移运算符
ostream& operator<<(ostream& cout, Person& p) {
	cout << "p.m_A: " << p.m_A << endl;
	cout << "p.m_B: " << p.m_B << endl;
	// 返回引用, 以便进行链式调用
	return cout;
}

void test01() {
	Person p;
	cout << p << "hello world" << endl;
	// 以上 相当于
	/*ostream& out= cout << p;
	out << "hello world" << endl;*/
}
int main() {
	test01();
	system("pause");
	return 0;
}
```

### 4.5.3 递增运算符重载

+ 作用:  通过重载递增运算符,实现自己的整型数据
+ 前置递增 与 后置递增 的区别
+ 前置递增,`++i`, 先++,再返回
+ 后置递增,`i++`,先返回,再++

```c++
using std::cout;
using std::endl;
using std::string;
using std::ostream;

// 自增(自减运算符 分为 前置 自增,与后置自增, 搞清楚 i++ 与 ++i的区别)
class MyInteger {

	friend ostream& operator<<(ostream& cout, MyInteger myInteger);
public:
	// 默认构造函数
	MyInteger() {
		m_Int = 10;
	};
	// 前置自增运算符 先++ 再返回
	MyInteger& operator++() {
		++m_Int;
		return *this;
        // 返回引用, 是为了防止尾调用失效, MyInteger调用拷贝函数,返回一个新的实例对象
	}
	// 后置自增运算符 先返回当前的数,再执行++ 操作
	MyInteger operator++(int) {
		MyInteger temp = *this;
		m_Int++;
		return temp;
	}
private:
	int m_Int;
};

// 重写 左移<< 运算符,用于输出MyInterger 实例
ostream& operator<<(ostream& cout,MyInteger myInteger) {
	cout << myInteger.m_Int << endl;
	return cout;
}

// 后置 ++
void test01() {
	MyInteger m;
	/*cout << ++m << endl;*/
	cout << m++ << endl;
	cout << m << endl;
}
//前置 ++
void test02() {
	MyInteger m;
	cout << ++(++m) << endl;
	cout << m << endl;
}

int main() {
	test01();
	test02();
	system("pause");
	return 0;
}
```

+ 递减运算符 重载

```c++
using std::cout;
using std::endl;
using std::string;
using std::ostream;

// 递增运算符重载, 分为 前置递减和 后置递减

class MyInteger {
	friend ostream& operator<<(ostream& cout, MyInteger m);
public:
	// 默认构造函数
	MyInteger() {
		m_Int=10;
	}
	/*前置递减,不返回引用的情况
	MyInteger operator--() {
		m_Int--;
		return *this;
	}*/
	// 前置递减 先运算 再返回运算后的结果, 要想链式调用 ,使用引用来操作同一个对象,而不是调用class内部的拷贝构造函数新建一个实例
	MyInteger& operator--() {
		m_Int--;
		return *this;
	}
	// 后置递减
	MyInteger operator--(int) {
		MyInteger temp = *this;
		m_Int--;
		return temp;
	}
private:
	int m_Int;
};

// 重载 << 运算符
ostream& operator<<(ostream& cout, MyInteger m) {
	cout << m.m_Int << endl;
	return cout;
}

// 1. 前置递减, 但不返回引用的情况
void test01() {
	MyInteger m;
	cout << --(--m) << endl;// 8
	cout << m << endl;// 9
}
void test02() {
	MyInteger m;
	cout << --(--m) << endl;// 8
	cout << m << endl;// 8
}

//2.后置递减
void test03() {
	MyInteger m;
	cout << m-- << endl;//10
	cout << m << endl;//9
}
int main() {
	test01();
	test02();
	test03();
	system("pause");
	return 0;
}
```

### 4.5.4 关系运算符 重载

+ 太简单了, 不写了

### 4.5.5 函数调用运算符重载

+ 函数调用运算符`()`,也可以重载
+ 由于重载后使用的方式,非常向函数的调用, 因此称为 `仿函数`
+ 仿函数没有固定写法,非常灵活

```c++
// 函数调用符号 () 进行重载, 这种重载 常用于 STL
class MyString {
public:
	void operator()(string str) {
		cout << str << endl;
	}
};
class MyAdd {
public:
	int operator()(int a,int b) {
		return a + b;
	}
};

void test01() {
	MyString myStr;
	myStr("这是一个重载 () 运算符传入的string的参数");
	// 匿名对象的创建方式
	MyString()("MyString() 创建了一个匿名对象");
}

void test02() {
	MyAdd myAdd;
	cout << myAdd(2, 3) << endl;//5
}

int main() {
	test01();
	test02();
	system("pause");
	return 0;
}
```

## 4.6 继承

+ 继承是面向对象的三大特性之一
+ 有些类与类之间存在特殊的关系,例如下图中

+ 面向对象程序设计中最重要的一个概念是继承。继承允许我们依据另一个类来定义一个类，这使得创建和维护一个应用程序变得更容易。这样做，也达到了重用代码功能和提高执行效率的效果。

+ 当创建一个类时，您不需要重新编写新的数据成员和成员函数，只需指定新建的类继承了一个已有的类的成员即可。这个已有的类称为**基类**，新建的类称为**派生类**。

+ 继承代表了 **is a** 关系。例如，哺乳动物是动物，狗是哺乳动物，因此，狗是动物，等等。
+ <img src="E:\Learn\006-cpp\img\cpp-inheritance-2020-12-15-1.png" style="zoom:50%;" />

###  4.6.1 继承的基本语法

+ 语法:`class 子类:继承方式 父类`
+ 子类 也叫 派生类
+ 父类 也叫 基类

```c++
class Dog {
public:
	void body() {
		cout << "狗有四条腿" << endl;
	}
	void header() {
		cout << "狗都有脑袋" << endl;
	}
};

class BlackDog :public Dog {
public:
	void color() {
		cout << "black dog 的狗毛是黑色的" << endl;
	}
};

class WhiteDog :public Dog {
public:
	void color() {
		cout << "white dog的毛是白色的" << endl;
	}
};

void test01() {
	BlackDog bd;
	bd.header();
	bd.body();
	bd.color();

	WhiteDog wd;
	wd.header();
	wd.body();
	wd.color();
}

int main() {
	test01();
	system("pause");
	return 0;
}
```

### 4.6.2 继承方式

继承方式一共有三种:

+ 公共继承
+ 保护继承
+ 私有继承



![](E:\Learn\006-cpp\img\clip_image002.png)

+ 继承方式 为public 时 `class Son :public Father`,
  + 父类的public成员 被继承到子类 继续 作为 public成员
  + 父类的protected成员 被继承到子类 继续 作为 protected 成员
  + 父类的private成员,实际被继承了,但被编译器隐藏了,不能够访问
+ 继承方式  为 protected时`class Son:protected Father`
  + 父类的public成员, 被继承到子类 作为 protected 成员
  + 父类的protected成员,被继承到子类 作为 protected成员
  + 父类的private成员,实际被继承了,但被编译器隐藏了,不能够访问
+ 继承方式为 private时 `class Son:private Father`,
  + 父类的public成员,被继承到子类 作为 private成员
  + 父类的protected成员,被继承道子类作为 private成员
  + 父类的private成员,实际被继承了,但被编译器隐藏了,不能够访问
+ 总结:
  子类会 继承父类 所有有权限访问的成员, 当继承方式为 public时,继承的父类权限不变, 当继承方式为 protected或者private时,继承的父类成员的权限 在子类中 全部变为 继承方式的权限

```c++
// 继承的三种方式 public protected private
class Father {
public:
	int a;
protected:
	int b;
private :
	int c;
public:
	Father() {
		a = b = c = 1;
	}
};


// 1.public 继承, 继承父类中有权限继承的成员(public, protected),权限在子类中保持不变
class Son1 :public Father {
public:
	int d;
};
void test01() {
	Son1 s1;
	cout << s1.a << endl;//1
	//cout << s1.b << endl;// protected 成员实例无权访问
	//cout << s1.c << endl// private成员 无权访问
}

// 2.protected 继承, 继承父类中有权限继承的成员(public, protected),继承的成员在子类中的权限全部变为protected
class Son2 :protected Father {
public:
	int d;
};
void test02() {
	Son2 s2;
	//cout << s2.a << endl;// protected 成员实例无权访问
	//cout << s2.b << endl;// protected 成员实例无权访问
	//cout << s2.c << endl// private成员 无权访问
}

// 2.private 继承, 继承父类中有权限继承的成员(public, protected),继承的成员在子类中的权限全部变为private
class Son3 :private Father {
public:
	int d;
};
void test03() {
	Son3 s3;
	//cout << s3.a << endl;// private 成员实例无权访问
	//cout << s3.b << endl;// private 成员实例无权访问
	//cout << s3.c << endl// private成员 无权访问
}

int main() {
	test01();
	test02();
	test03();
	system("pause");
	return 0;
}
```

### 4.6.3 继承中的对象模型

问题: 从父类继承过来的成员中,哪些属于子类对象中

+ 示例:

```c++
using std::cout;
using std::endl;
using std::string;

class Base {
	static int f;
public:
	int a;
protected:
	int b;
private:
	int c;
};

class Son :public Base {
public:
	int d;
};
void test01() {
	Son s;
	cout << sizeof(s) << endl;// 16个字节
	// 父类中所有非静态成员属性都会被子类继承下去
	// 父类中的私有成员是被编译器 隐藏了,因此访问不到,但确实被继承下去了
}
int main() {
	test01();
	system("pause");
	return 0;
}
```

+ 父类中所有非静态成员属性都会被子类继承下去.  父类中的私有成员是被编译器 隐藏了,因此访问不到,但确实被继承下去了

### 4.6.4 继承中的构造和析构顺序(和类的嵌套顺序是一样的)

子类继承父类后,当创建子类对象,也会调用父类的构造函数



问题: 父类和子类中的构造和析构顺序谁先谁后



```c++
class Father {
public:
	Father() {
		cout << "父类构造函数执行" << endl;
	}
	~Father() {
		cout << "父类析构函数执行" << endl;
	}
};

class Son :public Father {
public:
	Son() {
		cout << "子类构造函数被执行" << endl;
	}
	~Son() {
		cout << "子类析构函数被执行" << endl;
	}
};

void test01() {
	Father f;
}

void test02() {
	Son s;
	// 父类构造函数执行
	// 子类构造函数被执行
	// 子类析构函数被执行
	// 父类析构函数执行

}
int main() {
	test01();
	test02();
	system("pause");
	return 0;
}
```

### 4.6.5  继承同名成员处理方式

+ 当子类与父类出现同名的成员,如何通过子类,访问到子类或者父类中的数据呢?
+ 访问子类同名成员 直接访问即可
+ 访问父类同名成员 需要加作用域

+ 同名属性的处理

```c++
class Base {
public:
	int m_A;
	Base() {
		m_A = 100;
	}
};

class Son :public Base {
public:
	int m_A;
	Son() {
		m_A = 200;
	}
};
class Son2 :public Base {
	int m_A;
public:
	Son2() {
		m_A = 10;
	}
};

class Son3 :public Base {
public:
	int m_A;
	Son3() {
		m_A = 20;
	}
};

class Son4 :public Son3 {
public:
	int m_A;
	Son4() {
		m_A = 40;
	}
};

void test01() {
	Son s;
	cout << s.m_A << endl;// 200
	cout << s.Base::m_A << endl;// 100
}

void test02() {
	Son2 s;
	//cout << s.m_A << endl;// 不可访问
	cout << s.Base::m_A << endl;//100
}
void test03() {
	Son4 s;
	cout << s.m_A << endl;// 40
	cout << s.Son3::m_A << endl;// 20
	cout << s.Son3::Base::m_A << endl;// 100
	cout << s.Base::m_A << endl;// 100 和上一种方法一样
}
int main() {
	test01();
	test02();
	test03();
	system("pause");
	return 0;
}
```

+ 同名函数以及发生函数重载时的处理

```c++
using std::cout;
using std::endl;
using std::string;
// 当父子类中有相同的 同名函数时

class Base {
public:
	void func1() {
		cout << "Base类 func1" << endl;
	}
	void func1(int a) {
		cout << "Base类 func1(int a)" << endl;
	}
};

class Son :public Base {
public:
	void func1() {
		cout << "Son类 func1" << endl;
	}
	// 子类有同名重载函数时
	void func1(int a) {
		cout << "Son类 func1(int a)" << endl;
	}
};
void test01() {
	Son s;
	s.func1();// Son类 func1
	s.Base::func1();// Base类 func1
	// 运行重载函数
	s.func1(2);// Son类 func1(int a)
	s.Base::func1(100);//Base类 func1(int a)
}
int main() {
	test01();
	system("pause");
	return 0;
}
```

### 4.6.6 继承静态成员处理方式

问题: 继承中同名的静态成员在子类对象上如何访问?

静态成员和非静态成员出现同名,处理方式一致



+ 访问子类成员,直接访问即可
+ 访问父类同名成员,需要加作用域



```c++
using std::cout;
using std::endl;
using std::string;

// 同名静态属性和静态函数的访问
//静态成员属性
//1.在编译阶段分配内存
//2.类内声明, 类外初始化
//静态成员函数  
//1.静态成员只能访问 静态变量, 因为静态成员的数据只存在一份, 而访问 
//2.普通变量时,该普通变量是根据类定义的实例来变化的,有多个地址上存在了 该普通变量,肯定是不允许访问和修改的

class Base {
public:
	static int m_A;
	static void func1() {
		cout << "Base static void func1()" << endl;
	};
	static void func1(int a) {
		cout << "Base static void func1(int a)" << endl;
	}
};

class Son :public Base {
public:
	static int m_A;
	static void func1() {
		cout << "Son static void func1()" << endl;
	}
};
int Base::m_A = 100;
int Son::m_A = 200;

void test01() {
	Son s;
	cout << s.m_A << endl;// 200
	cout << s.Base::m_A << endl;// 100
	cout << Son::m_A << endl;// 200
	cout << Son::Base::m_A << endl;//100
	Son::func1();// Son static void func1()
	Son::Base::func1();//Base static void func1()
	Son::Base::func1(100);//Base static void func1(int a)
}

int main() {
	test01();
	system("pause");
	return 0;
}
```

### 4.6.7 	多继承语法

C++ 允许一个类继承多个类

语法:`class 子类名:继承方式 父类1, 继承方式 父类2...`

多继承可能会引发父类中有同名成员出现,需要加作用域区分

**C++ 实际开发中不建议用多继承**



示例:

```c++
// 一个子类可以同时继承多个父类
class Base1 {
public:
	int m_A;
	Base1() {
		m_A = 10;
	}
};

class Base2 {
public:
	int m_A;
	Base2() {
		m_A = 20;
	}
};

class Son :public Base1, public Base2 {
public:
	int m_B;
	int m_C;
};

void test01() {
	Son s;
	//cout << s.m_A << endl;//error Son::m_A不明确
	//继承的多个父类中有同名成员时,访问这些成员时需要加作用域进行区分
	cout << s.Base1::m_A << endl; // 10
	cout << s.Base2::m_A << endl; // 20
}
int main() {
	test01();
	system("pause");
	return 0;
}
```

### 4.6.8 菱形继承问题以及解决方法

**菱形继承概念**

​	两个派生类继承同一个类

又有某个类同时继承这两个派生类

这种继承被称为菱形继承,或者派生继承

**典型的菱形继承案例**:

![](E:\Learn\006-cpp\img\clip_image002.jpg)

**菱形继承问题**

1. 羊继承了动物的数据,驼同样也继承了动物的数据,当羊驼使用数据时,就会产生二义性
2. 羊驼继承自动物的数据继承了两份,但其实这份数据只要一份就够了

**解决方法:**

+ 利用虚继承 解决菱形继承问题

+ 继承之前 加上关键字 virtual 变为虚继承

  ```c++
  // 动物类
  class Animal{
    public:
    	  int m_Age;  
  };
  // 羊类
  class Sheep: virtual public Animal{};
  
  // 驼类
  class Camel: virtual public Animal{};
  
  // 羊驼类
  class Alpaca:public Sheep,public Camel{};
  
  ```

  **其中 `Animal`类被称为<mark>虚基类</mark>>**

```c++
class Animal {
public:
	int m_Age;
	Animal() {
		m_Age = 100;
	}
};

class Sheep : virtual public Animal {
public:
	Sheep() {
		cout << "Sheep 的构造函数执行,m_Age被改变之前的值为:" << m_Age << endl;//100
		m_Age = 20;
	}
};

class Camel :virtual public Animal {
public:
	Camel() {
		cout << "Camel 的构造函数执行,m_Age被改变之前的值为:" << m_Age << endl;//20
		m_Age = 80;
	}
};

class Alpaca :public Sheep, public Camel {
public:
	int m_B;
};

class Alpaca2 :public Camel,public Sheep  {
public:
	int m_B;
};
void test01() {
	Alpaca a;
	Alpaca2 a2;
	//cout << a.m_Age << endl;// 二义性,语义不明确,通过作用域解决
	//cout << a.Sheep::m_Age << endl; //20
	//cout << a.Camel::m_Age << endl; //80
	//通过定义 虚基类 来继承 Animal的 m_Age,

	cout << a.m_Age << endl;// 80
	// Animal 和 Sheep ,Camel 类 改动的m_Age 是在一个 虚基类表上的一个地址,多继承的顺序会影响构造函数的执行,先是通过Animal的构造函数让m_Age=100,然后是改造成20,最后是80
	cout << a2.m_Age << endl;// 20
	// Animal 和 Sheep ,Camel 类 改动的m_Age 是在一个 虚基类表上的一个地址,先是通过Animal的构造函数让m_Age=100,然后是改造成80,最后是20
		
		// 总的打印验证结果如下
		//Sheep 的构造函数执行, m_Age被改变之前的值为:100
		//Camel 的构造函数执行, m_Age被改变之前的值为 : 20
		//Camel 的构造函数执行, m_Age被改变之前的值为 : 100
		//Sheep 的构造函数执行, m_Age被改变之前的值为 : 80
		//80
		//20
}

int main() {
	test01();
	system("pause");
	return 0;
}
```





## 4.7 多态

### 4.7.1 多态的基本概念

**多态是C++面向对象三大特性之一**

+ 多态分为两类

  + 静态多态: 函数重载 和运算符重载 属于静态多态,复用函数名
  + 动态多态:派生类 和 虚函数实现运行时多态

+ 静态多态和动态多态的区别

  + 静态多态的函数地址早绑定 - 编译阶段确定函数地址
  + 动态多态的函数地址晚绑定 - 运行阶段确定函数地址

+ 下面通过案例讲解多态:

  ```c++
  #include <iostream>
  
  using std::cout;
  using std::endl;
  using std::string;
  // 静态多态
  // 函数重载 和 运算符重载
  // 编译阶段确定函数地址 - 早绑定
  
  //动态多态
  // 派生类 和 虚函数
  // 运行阶段确定函数地址 - 晚绑定
  
  
  class Animal {
  public:
  	// 函数前加 virtual 加修饰符表示 虚函数
  	virtual void speak() {
  		cout << "Animal speak" << endl;
  	}
  };
  
  class Cat:public Animal {
  public:
  	void speak() {
  		cout << "Cat speak" << endl;
  	}
  };
  
  class Dog:public Animal {
  public:
  	virtual void speak() {
  		cout << "Dog speak" << endl;
  	}
  	// 派生类中的 虚函数修饰符可加可不加
  };
  
  
  void doSpeak(Animal& a) {
  	a.speak();
  }
  
  void test01() {
  	Cat c;
  	Dog d;
  	// Dog 和 Cat 类中的对于父类的 speak函数都进行了重写
  
  	// 重载 : 函数参数或者返回值不同
  	// 重写 : 函数参数和返回值 和原函数一样
  	doSpeak(c);
  	doSpeak(d);
  }
  
  int main() {
  	test01();
  	system("pause");
  	return 0;
  }
  ```

+ 动态多态满足条件
  + 1. 有继承关系
    2. 子类重写父类的虚函数
+ 动态多态的使用
  + 父类的指针或者引用指向子类对象 `Animal& animal = cat`

<img src="E:\Learn\006-cpp\img\virtual_function_table.png" style="zoom:50%;" />

![](E:\Learn\006-cpp\img\mulptiple_state.png)

### 4.7.2 多态案例 计算器类

案例描述:

分别利用普通写法和多态技术,设计实现两个操作数进运算的计算器类



多态的优点:

+ 代码组织结构清晰
+ 可读性强
+ 利用扩展和维护 (在真实开发中,提倡开闭原则, 对扩展进行进行开发, 对修改(源码)进行关闭)



示例:

```c++
// 多态 符合 开闭原则, 不去修改老代码, 在老代码的基础上进行开发

// 利用 一个 多态 开发一个具有扩展性的计算器,实现 整型的四则运算

// 1.实现一个计算器的抽象类
class AbstractCalculator {
public:
	int m_A;
	int m_B;
	virtual int getResult() {
		return 0;
	}
};

class AddCalculator:public AbstractCalculator {
public:
	int getResult() {
		return m_A + m_B;
	}
};

class SubCalculator :public AbstractCalculator {
public:
	int getResult() {
		return m_A - m_B;
	}
};

class MulCalculator :public AbstractCalculator {
public:
	int getResult() {
		return m_A*m_B;
	}
};

class DivCalculator :public AbstractCalculator {
public:
	int getResult() {
		return m_A/m_B;
	}
};

void test01() {
	AbstractCalculator* abc=new AddCalculator;
	// 重写基类中的 虚函数, 需要将 基类指针的指向设为 对应的子类实例地址,达到动态对函数进行函数的地址赋值
	abc->m_A = 10;
	abc->m_B = 20;
	cout <<"+: " << abc->getResult() << endl;//30

	delete abc;// 清空add

	abc = new SubCalculator;
	abc->m_A = 10;
	abc->m_B = 20;
	cout << "+: " << abc->getResult() << endl;//-10
	delete abc;

	abc = new MulCalculator;
	abc->m_A = 10;
	abc->m_B = 20;
	cout << "+: " << abc->getResult() << endl;//200
	delete abc;

	abc = new DivCalculator;
	abc->m_A = 100;
	abc->m_B = 20;
	cout << "+: " << abc->getResult() << endl;//5
	delete abc;

}

int main() {
	test01();
	system("pause");
	return 0;
}
```

### 4.7.3 纯虚函数和抽象类

在多态中,通常父类中的虚函数的实现是无意义的,主要都是调用子类重写的内容

因此可以将虚函数改为纯虚函数

纯虚函数语法:`virtual 返回值类型 函数名 (参数列表) = 0 ;`

当类中有了纯虚函数,这个类也称为抽象类



**抽象类特点**

+ 无法实例化对象
+ 子类必须重写抽象类中的纯虚函数,否则也属于抽象类



示例:

```c++
class Base {
public:
	// 纯虚函数
	// class 中只要有一个纯虚函数, 这个类就被称为 抽象类
	// 抽象类的特点:
	// 1.无法实例化对象
	// 2. 抽象类的子类必须重写 父类中的 纯虚函数, 否则也会被视为一个 抽象类,同样不能被实例化
	virtual void speak() = 0;

};

class Son :public Base {

};

class Son2 :public Base {
public:
	void speak() {
		cout << "重写纯虚函数" << endl;
	}
};

void test01() {
	//Base base;// 拥有 纯虚函数的抽象类 不能被实例化
	// Son son;// 继承抽象类,但是没有重写基类中的纯虚函数的派生类, 同样无法实例化
	Son2 *s=new Son2;
	s->speak();
}

int main() {
	test01();
	system("pause");
	return 0;
}
```

### 4.7.4 多态案例二-制作饮品

案例描述:

制作饮品的大致流程为: 煮水 - 冲泡 - 倒入杯中 - 加入辅料

利用多态技术实现本案例, 提供抽象制作饮品基类, 提供子类制作咖啡和茶叶

示例:
```c++
// 制作饮品过程 煮水 - 冲泡 - 倒入杯中 - 加入辅料
class MakeDrink {
public:
	// 煮水
	virtual void boil() = 0;
	//冲泡
	virtual void brew() = 0;
	//倒入杯中
	virtual void pour() = 0;
	//加入辅料
	virtual void material() = 0;

	// 制作
	void make() {
		boil();
		brew();
		pour();
		material();
	}
};

// 制作咖啡
class Coffee :public MakeDrink {
public:
	void boil() {
		cout << "加入农夫山泉" << endl;
	}
	void brew() {
		cout << "冲泡可可粉" << endl;
	}
	void pour() {
		cout << "导入玻璃杯中" << endl;
	}
	void material() {
		cout << "加入糖和玛莎拉" << endl;
	}
};

// 制作乌龙茶
class Tea :public MakeDrink {
public:
	void boil() {
		cout << "煮康师傅" << endl;
	}
	void brew() {
		cout << "冲泡龙井" << endl;
	}
	void pour() {
		cout << "导入茶杯中" << endl;
	}
	void material() {
		cout << "加入玛莎拉,多少带点臭" << endl;
	}
};

void doWorker(MakeDrink* drink) {
	drink->make();
	delete drink;
}


void test01() {
	doWorker(new Coffee);
	doWorker(new Tea);
}

int main() {
	test01();
	system("pause");
	return 0;
}
```





### 4.7.5 虚析构 和 纯虚析构

多态使用时,如果子类中有属性开辟到堆区, 那么父类指针在释放时无法调用到子类的析构代码



解决方法: 将父类中的析构函数改为**虚析构**或者 **纯虚析构**



虚析构和纯虚析构共性:

+ 可以解决父类指针释放子类对象
+ 都需要有具体的函数实现

虚析构和纯虚析构的区别:

+ 如果是纯虚析构,该类属于抽象类,无法实例化对象



虚析构语法:

`virtual ~类名(){};`

纯虚析构语法:

`virtual ~类名() = 0;`

`类名::~类名(){};	`



```c++
class Animal {
public:
	Animal() {
		cout << "Animal constructor func execute" << endl;
	}
	/*~Animal() {
		cout << "Animal destructor func execute" << endl;
	}*/
	// 析构函数前加上 virtual 编程虚析构函数
	/*virtual ~Animal() {
		cout << "Animal virtual destructor func execute" << endl;
	}*/
	// 纯虚析构函数, 需要在类外具体声明
	virtual ~Animal() = 0;
	virtual void speak() = 0;
};
// 纯虚函数 需要在类外声明
Animal::~Animal() {
	cout << "Animal pure virtual destructor func execute" << endl;
}
//和包含普通纯虚函数的类一样，包含了纯虚析构函数的类也是一个抽象类。不能够被实例化。

class Cat :public Animal {
public:
	string* m_Name;
	Cat(string str) {
		m_Name = new string(str);
		cout << "Cat constructor func execute" << endl;
	}
	virtual void speak() {
		cout << *m_Name << "在说话" << endl;
	}
	~Cat() {
		if (m_Name != NULL) {
			delete m_Name;
			cout << "Cat destructor func execute" << endl;
		}
	}
};


void test01() {
	Animal* cat = new Cat("TOM");
	cat->speak();
	
	// 基于 基类创建的实例, 在delete 堆区数据时, 不会执行子类的析构函数, 这样会导致子类中的m_Name的堆区数据未被删除,从而导致空间浪费,内存泄露
	//通过父类指针去释放，会导致子类对象可能清理不干净，造成内存泄漏
	//怎么解决？给基类增加一个虚析构函数,  这样便可使得 Cat中的析构函数执行
	//虚析构函数就是用来解决通过父类指针释放子类对象
	delete cat;
};

int main() {
	test01();
	system("pause");
	return 0;
}
```

总结：

​	1. 虚析构或纯虚析构就是用来解决通过父类指针释放子类对象

​	2. 如果子类中没有堆区数据，可以不写为虚析构或纯虚析构

​	3. 拥有纯虚析构函数的类也属于抽象类

### 4.7.6 多态案例三-电脑组装

案例描述:

电脑主要组成部件为 CPU（用于计算），显卡（用于显示），内存条（用于存储）

将每个零件封装出抽象基类，并且提供不同的厂商生产不同的零件，例如Intel厂商和Lenovo厂商

创建电脑类提供让电脑工作的函数，并且调用每个零件工作的接口

测试时组装三台不同的电脑进行工作



```c++
//  CPU ,显卡, 内存条的抽象类, 分别实现class 纯虚函数

class CPU {
public:
	virtual void calculate() = 0;

};

class GraphCard {
public:
	virtual void display() = 0;

};

class MemoryBlock {
public:
	virtual void storage() = 0;
};

// 电脑, 提供工作函数
class Computer {
public:
	Computer(CPU* cpu,GraphCard* gc,MemoryBlock* mb) {
		m_cpu = cpu;
		m_gc = gc;
		m_mb = mb;

	}
	void work() {
		m_cpu->calculate();
		m_gc->display();
		m_mb->storage();
	}
	~Computer() {
		if (m_cpu != NULL) {
			delete m_cpu;
		}
		if (m_gc != NULL) {
			delete m_gc;
		}
		if (m_mb != NULL) {
			delete m_mb;
		}
		cout << "Computer destructor func execute" << endl;
	}

private:
	CPU* m_cpu;
	GraphCard* m_gc;
	MemoryBlock* m_mb;
};

// Intel CPU 派生类
class IntelCPU :public CPU {
public:
	virtual void calculate() {
		cout << "Intel CPU has run" << endl;
	}
};

// Amd CPU 派生类
class AmdCPU :public CPU {
public:
	virtual void calculate() {
		cout << "Amd CPU has run" << endl;
	}
};

// Nvidia GPU 派生类
class NvidiaGPU :public GraphCard {
public:
	virtual void display() {
		cout << "NvidiaGPU has run" << endl;
	}
};

// AMD GPU 派生类
class AmdGPU :public GraphCard {
public:
	virtual void display() {
		cout << "AmdGPU has run" << endl;
	}
};

// Samsung Memory Block 派生类
class SamsungMemoryBlock :public MemoryBlock{
public:
	 void storage () {
		cout << "Samsung MemoryBlock has storage" << endl;
	}
};

// ZhiTai Memory Block 派生类
class ZhiTaiMemoryBlock :public MemoryBlock {
public:
	void storage() {
		cout << "ZhiTai MemoryBlock has storage" << endl;
	}
};

void test01() {
	CPU* cpu = new IntelCPU;
	GraphCard* gc = new AmdGPU;
	MemoryBlock* mb = new SamsungMemoryBlock;

	Computer* c = new Computer(cpu, gc, mb);
	c->work();
}

int main() {
	test01();
	system("pause");
	return 0;
}
```







# 5. 文件操作

## 5.1文本文件

###  5.1.1 写文件

### 5.1.2 读文件



## 5.2 二进制文件

