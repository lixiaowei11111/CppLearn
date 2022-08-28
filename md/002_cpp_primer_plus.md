# 1. #include 和 using namespace 的作用

## 1.1 #include

+ `#include <iostream>`

  + 该条编译指令会使得 预处理器将 iostream 文件添加到程序中, #include 用于引入头文件

  ```c++
  // 引入系统的头文件
  #include<iostream>
  
  // 引入自定义头文件
  #include "swap.h"
  ```

  +  像iostream 这样的文件被叫做包含文件(include file), 也叫做头文件(header file), C/C++ 自带了很多预处理函数在头文件中,头文件命名规则如下:

| 头文件类型   | 约定                 | 示例       | 说明                                                     |
| ------------ | -------------------- | ---------- | -------------------------------------------------------- |
| C++ 旧式风格 | .h 结尾              | iostream.h | C++ 程序可以使用                                         |
| C旧式风格    | .h结尾               | math.h     | C, C++ 都可以使用                                        |
| C++ 新式风格 | 没有扩展名           | iostream   | C++ 程序可以使用, 使用 namespace std                     |
| 转换后的C    | 加上前缀C,没有扩展名 | cmath      | C++ 程序可以使用,可以使用不是c的特性,如:  namespace std; |

## 1.2 using namespace std 命名空间,  用于区分 不同文件的相同方法名(类似ts,   用于环境隔离)

+ 如果使用 `iostream`而不是`iostream.h`,则应使用下面的名称空间编译指令来使iostream中的定义对程序可用:

  ```c++
  using namespace std; // std 表示的是某一个类或者方法的名字
  ```

+ 这叫`using编译指令`

+ 命令空间支持是一项C++特性,旨在编写大型程序时以及将多个代码组合起来的程序时更容易,它还有助于组织程序.  一个潜在的问题是,可能已使用两个已封装好的产品, 而他们都包含一个名为 wanda()的函数. 在这种情况下使用 wanda() 函数时, 编译器不知道 指的是哪个版本. 命令空间能让 厂商把 产品 封装在 一个叫 `namespace`的单元中, 这样就可以 用`namespace`的名称来指出 想使用哪个厂商的产品.  比如:  Microflop Industries 可以将定义放在一个名为 Microflop的namespace中. 其中, 其wanda() 函数的全称为 `Microflop::wanda()`; 同样 Piscine公司的 wanda() 版本可以表示为 `Piscine::wanda()`. 这样,程序就可以使用 namespace 来区分不同的版本了

  ```c++
  Microflop::wanda("go dancing"); //use Microflop namespace version
  Piscine::wanda("a fish name Desire"); // use Piscine namespace version
  ```

+ 按照这种方式, 类, 函数,变量便是C++编译器的标准组件, 他们都被放置在 namespace std中.  <mark>仅在当头文件没有扩展名 .h时,情况才是如此</mark>. 这意味着在 `iostream`中定义的用于输出的cout变量实际上是 `std::cout`, 而endl 实际上是`std::endl`; 因此, 可以省略编译指令using, 以下述方式进行编码输出

  ```c++
  std::out <<"come on";
  std::cout<<std::endl;
  ```

+ 然而, 使用 iostream.h和cout 转为 iostream和std::out,  于是using指令由此而生.  下面的代码表明,可以使用std 命名空间中定义的名称, **而不必使用std::前缀**:

  ```c++
  using namespace std;
  ```

+ 这个编译指令使得std名称空间中所有名称可用.   这是一种偷懒的做法,在大型项目中一个潜在的问题. 更好的方法是, 只使所需名称即可, 通过using来实现:

  ```c++
  using std::cout;// make cout available
  using std::endl;// make endl available
  using std::cin; // make cin available

+ 用上述编译代替后`using namespace std`后, 便可以使用 cin 和 cout, 而不必加上std::前缀
+ 然而, 要使用iostream中的其他名称, 必须分别再加入单个名称

+ 示例代码:

  ```c++
  #include<iostream>
  
  
  //using namespace std;// 可以使用下述三种 指令替代
  using std::string;
  using std::cout;
  using std::endl;
  
  // 1.定义 英雄 结构体
  struct Hero {
  	string name;
  	int age;
  	string sex;
  };
  
  
  // 3. 声明录入信息的函数
  void importInfo(Hero heroArr[], int length);
  int main() {
  	// 2. 创建英雄结构体 数组变量
  	Hero heroArr[5] = {
  		{"刘备",23,"男"},
  		{"关羽",22,"男"},
  		{"张飞",20,"男"},
  		{"赵云",21,"男"},
  		{"貂蝉",19,"女"},
  	};
  	int len = sizeof(heroArr) / sizeof(heroArr[0]);
  	importInfo(heroArr,len);
  	system("pause");
  	return 0;
  }
  
  // 4. 定义导入信息的函数, 进行冒泡排序
  void importInfo(Hero heroArr[], int length) {
  	for (size_t i = 0; i < length-1; i++)
  	{
  		for (size_t j = 0; j < length-i - 1; j++)
  		{
  			if (heroArr[j].age > heroArr[j + 1].age) {
  				Hero temp = heroArr[j + 1];
  				heroArr[j + 1] = heroArr[j];
  				heroArr[j] = temp;
  			}
  		}
  	}
  	for (size_t i = 0; i < length; i++)
  	{
  		cout << "姓名: " << heroArr[i].name << "\t 年龄: " << heroArr[i].age << "\t性别: " << heroArr[i].sex << endl;
  	}
  }
  ```



# 2. cout 语句

## 2.1 << 插入运算符

```c++
cout << "string"<<endl;
```

+ 这段代码的含义是 将字符串 插入到 输出流中
+ <img src="E:\Learn\006-cpp\img\cout输出流.png" style="zoom:50%;" />
+ cout 右边的 `<<` 叫做 **插入运算符**,    <mark>实际上是 左移运算符`<<`</mark>的重载

## 2.2 控制符 endl;

​	endl 是一个特殊的 C++ 符号, 表示一个重要的概念: 重启一行