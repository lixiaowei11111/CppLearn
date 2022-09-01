# 1. 基础知识

## 1. main函数

+ 一个项目中只能有一个main主函数, 程序从这里开始执行
+ **``#include`  ``#define` 后不能够加 ; 分隔符,否则会产生难以预估的错误**

### 2. 变量

+ 用于内存空间管理
+ 定义方法 `类型 变量名称 = 变量值`

```c++
int a = 10;
```

### 3.常量

+ 用于记录程序中不可修改的数据

#### 1.定义常量的两种方法

##### 1.#define

+ define 宏常量 : `#define 常量名 常量值 `
+ 通常在文件上方定义,表示一个常量

##### 2. const

+ const 修饰的变量: `const 数据类型 常量名 = 常量值`

+ 通常在**变量定义前**加关键字const,修饰该变量为常量,不可修改

  

## 4. C++ 中的保留关键字

https://www.runoob.com/w3cnote/cpp-keyword-intro.html

| if   | else  | while    | signed   | throw  | union    | this      |
| ---- | ----- | -------- | -------- | ------ | -------- | --------- |
| int  | char  | dobule   | unsigned | const  | goto     | virtual   |
| for  | float | break    | auto     | class  | operator | case      |
| do   | long  | typedef  | static   | friend | template | default   |
| new  | void  | register | extern   | return | enum     | inline    |
| try  | short | continue | sizeof   | switch | private  | protected |
| asm  | while | catch    | delete   | public | volatile | struct    |

<img src="E:\Learn\006-cpp\img\001-cpp关键字.png" alt="image-20220824205100210" style="zoom:50%;" />

## 5. 标识符命名规则

+ 标识符不能是关键字
+ 标识符只能由字母数字下划线组成
+ 第一个字母必须为字母或者下划线
+ 标识符中字母区分大小写

# 2. 数据类型

+  c++ 规定在创建一个变量或者常量时, 必须要指出相应的数据类型,**否则无法给变量分配内存**
+ 七种基本的C++ 数据类型

| 类型     | 关键字  |
| :------- | :------ |
| 布尔型   | bool    |
| 字符型   | char    |
| 整型     | int     |
| 浮点型   | float   |
| 双浮点型 | double  |
| 无类型   | void    |
| 宽字符型 | wchar_t |

其实 wchar_t 是这样来的：

```
typedef short int wchar_t;
```

所以 wchar_t 实际上的空间是和 short int 一样。

一些基本类型可以使用一个或多个类型修饰符进行修饰：

- signed
- unsigned
- short
- long

下表显示了各种变量类型在内存中存储值时需要占用的内存，以及该类型的变量所能存储的最大值和最小值。

**注意：**不同系统会有所差异，一字节为 8 位。

**注意：**默认情况下，int、short、long都是带符号的，即 signed。

**注意：**long int 8 个字节，int 都是 4 个字节，早期的 C 编译器定义了 long int 占用 4 个字节，int 占用 2 个字节，新版的 C/C++ 标准兼容了早期的这一设定。

| 类型               | 空间(byte)    | 范围                                                         |
| :----------------- | :------------ | :----------------------------------------------------------- |
| char               | 1 个字节      | -128 到 127 或者 0 到 255                                    |
| unsigned char      | 1 个字节      | 0 到 255                                                     |
| signed char        | 1 个字节      | -128 到 127                                                  |
| int                | 4 个字节      | -2147483648 到 2147483647                                    |
| unsigned int       | 4 个字节      | 0 到 4294967295                                              |
| signed int         | 4 个字节      | -2147483648 到 2147483647                                    |
| short int          | 2 个字节      | -32768 到 32767                                              |
| unsigned short int | 2 个字节      | 0 到 65,535                                                  |
| signed short int   | 2 个字节      | -32768 到 32767                                              |
| long int           | 8 个字节      | -9,223,372,036,854,775,808 到 9,223,372,036,854,775,807      |
| signed long int    | 8 个字节      | -9,223,372,036,854,775,808 到 9,223,372,036,854,775,807      |
| unsigned long int  | 8 个字节      | 0 到 18,446,744,073,709,551,615                              |
| float              | 4 个字节      | 精度型占4个字节（32位）内存空间，+/- 3.4e +/- 38 (~7 个数字) |
| double             | 8 个字节      | 双精度型占8 个字节（64位）内存空间，+/- 1.7e +/- 308 (~15 个数字) |
| long double        | 16 个字节     | 长双精度型 16 个字节（128位）内存空间，可提供18-19位有效数字。 |
| wchar_t            | 2 或 4 个字节 | 1 个宽字符                                                   |

## 2.1 整型 short, int, long ,long long

+ 作用: 整型变量表示的是整数类型的数据

+ c++中能够表示整数的类型有以下四种, 区别在于所占的 **内存空间** 不同

  | 数据类型             | 占用空间                                              | 取值范围      |
  | -------------------- | ----------------------------------------------------- | ------------- |
  | short(短整型)        | 2字节                                                 | -2^15 ~2^15-1 |
  | int(整型)            | 4字节                                                 | -2^31~2^31-1  |
  | long(长整型)         | Windows为4字节,Linux为4字节(32位系统),8字节(64位系统) | -2^31~2^31-1  |
  | long long (长长整型) | 8字节                                                 | -2^63~2^63-1  |

  

+ 存储空间单位复习
  + 字节 byte      1byte = 8bit 
  + 位 bit    代表 0 和 1
  + byte或者char 1个字节               8位    2^8      -128~127            // 都包括0,下面的都会-1
  + short                2个字节            16位    2^16    -2^15 ~2^15-1
  + ...
+ 示例:

```c++

#include<iostream>
using namespace std;
int main() {
	// 1. 短整型
	short num1 = 32768;// 超过最大值会把从负数开始算超过的部分
	//short num1 = 123;
	// 2. 整型
	int num2 = 32768;
	// 3. 长整型
	long num3 = 32768;
	// 4. 长长整型
	long long num4 = 32768;
	cout << "短整型num1" << num1 << endl;
	cout << "整型num2" << num2 << endl;
	cout << "长整型num3" << num3 << endl;
	cout << "长长整型num4" << num4 << endl;
	system("pause");
		return 0;
}
```



## 2.2 sizeof 关键字

+ 作用: 利用sizeof 关键字统计数据类型所占内存大小, 单位为byte
+ 语法: `sizeof(数据类型/变量)`
+ 示例

```c++
int main() {
	cout << "short占用内存空间为" << sizeof(short) <<"byte"<< endl;
	cout << "int占用内存空间为" << sizeof(int) << "byte" << endl;
	cout << "long占用内存空间为" << sizeof(long) <<"byte" << endl;
	cout << "long long占用内存空间为" << sizeof(long long) <<"byte" << endl;
	system("pause");
	return 0;
}
```

## 2.3 typedef 关键字 (类似于ts中的 类型别名 type)

+ 作用:使用 **typedef** 为一个已有的类型取一个新的名字。
+ 语法: `typedef int newTypeName`
+ 示例:

```c++
int main() {

	// 1. typedef 类似于ts中type关键字,类型别名, 类型宏定义
	typedef int newInt;
	newInt a = 2;// 合法
	system("pause");
	return 0;
}
```



## 2.4 实数类型 flaot ,double  (实型 || 浮点型)

+ 作用: 用于表示小数
+ 浮点型变量分为两种
  + 单精度float   定义 float时, 需要在 数字后面加个f 否则可能被编译器识别为double
  + 双精度double
+ `float`和`double`区别在于 表示的有效数字范围不同

| 数据类型 | 占用空间 | 有效数字范围    |
| -------- | -------- | --------------- |
| float    | 4字节    | 7位有效数字     |
| double   | 8字节    | 15~16位有效数字 |

+ 示例

```c++
int main() {
	
	// 1. float 声明变量时, 最好在值后面添加 字母 f或者F
	float f1 = 3.14; // 被编译器默认识别为了 double
	float f2 = 3.14f;// 识别为 float
	double d1 = 3.14;
	// 2. float 和 double 默认只会显示出6位 有效数字
	float f3 = 3.1415926f;
	double d2 = 3.1415926;

	cout << "f3:"<< f3 << endl; // 打印结果为3.14159
	cout << "d2:"<< d2 << endl; // 打印结果为3.14159

	// 3. float 和 double 类型 变量的占用空间
	cout << "float占用的空间为" << sizeof(float) << "byte" << endl;
	cout << "double占用的空间为" << sizeof(double) << "byte" << endl;
	cout << "float类型变量 f3占用的空间为" << sizeof(f3) << "byte" << endl;
	cout << "double类型变量 d2占用的空间为" << sizeof(d2) << "byte" << endl;

	// 4. 科学计数法表示
	cout << 3e2 << endl;// 3 x 10^2         300
	cout << 3e-2 << endl;// 3 x 0.1 x 10^2  0.03
	system("pause");
	return 0;
}
```

## 2.5 字符型 char   (单个字符 和字符串区分开来)

+ 作用: 字符型变量用于显示单个字符
+ 语法: `char 变量名 = 'a'`  ; 
  + 一定要是 单引号 `''`, 用于区别字符串中的`"a"`
  + 只能是单个字符, 不能是字符串
+ c/c++ 中 char型变量只占用 1 byte
  + 字符型变量并不是把 字符本身放到内存中存储, 而是将对应的`ASCII`编码放入到存储单元
+ **强制转化类型语法**: `int(variable)`
+ 示例

```c++
int main() {
	// 1. 定义字符型 变量
	char ch = 'a';
	char ch4 = 'A';
	cout << ch << endl;
	//2. 整型占用空间大小
	cout << "char 类型占用的空间大小为" << sizeof(ch) << "byte"<<endl;
	// 3. 整型常见错误
	//char ch2 = "a"; 报错不能编译
	char ch3 = 'abc';
	// 4. 强制类型转化, 字母 对应的ASCII编码
	cout << int(ch) << endl; // a ==> 97
	cout << int(ch4) << endl;// A ==> 65
	system("pause");
	return 0;
}
```

## 2.6 转义字符(escape character)

+ 作用 : 用于表现一些 **不能显示出来的ASCII字符**
+ 常用转义字符有:`\n ` `\\`  ` \t`

| 转义序列   | 含义                       |
| :--------- | :------------------------- |
| \\         | \ 字符                     |
| \'         | ' 字符                     |
| \"         | " 字符                     |
| \?         | ? 字符                     |
| \a         | 警报铃声                   |
| \b         | 退格键                     |
| \f         | 换页符                     |
| \n         | 换行符                     |
| \r         | 回车                       |
| \t         | 水平制表符                 |
| \v         | 垂直制表符                 |
| \ooo       | 一到三位的八进制数         |
| \xhh . . . | 一个或多个数字的十六进制数 |

+ 示例代码:

```c++
int main() {

	// 转义字符
	cout << "转义字符换行符\\n:\n  转移字符制表符\\t:\t1111" << endl;
	system("pause");
	return 0;
}
```

## 2.7 字符串(string)

+ 作用: 用于表示一串字符

+ 两种风格:

### 2.7.1 C风格字符串: `char variable[] = "stringvalue"`

`字符串其实也是一个数组`

+ 示例代码   **获取string类型的长度 strlen(charVariable)**

```c
	// 4. 获取 char类型数组长度的方法  获取字符串长度的方法 strlen(char)
	 char char1[] ="adadadsaddada";
	 cout << "use strlen function get string length is :" << strlen(char1);
```

+ C  风格的字符串 必须要用 **双引号**括起来

### 2.7.2 C++ 风格字符串: `string variable = "字符串值"`

+ 示例代码:

```c++
int main() {
	// 1. C语言风格字符串, 把字符串 看成一个 字符数组
	/*
	*注意事项
	* 1.必须使用 双引号
	* 2. 定时时同样使用char 关键字, 但是变量后面跟一个 []表示数组
	*/
	char ch[] = "abc";
	cout << "C语言风格字符串" << ch << endl;

	//2. C++ 风格字符串, 定义为string即可
	// 可能需要引入头文件 #include<string>
	string ch2 = "abc";
	cout << "C++ 风格的字符串" << ch2 << endl;

	system("pause");
	return 0;

}
```

+ C++ 使用string, 需要引入头文件 string  #include<string>

## 2.8 布尔类型 bool

+ 作用: 布尔数据类型代表真或者假的值
+ bool类型只有两个值:
  + true --- 真 1
  + false ---假 0
+ **bool类型占 <mark>1个字节</mark>大小**

+ 示例代码:

```c++
int main() {
	bool flag = false;
	cout << flag << endl; // 0
	flag = true;
	cout << flag << endl; // 1
	cout << "bool类型的占用空间大小" << sizeof(flag) <<"byte" << endl;// 1
	system("pause");
	return 0;
}
```

## 2.9 数据输入cin(数据输出 cout )

+ 作用: 用于从键盘获取输入
+ 关键字:cin
+ 语法: `cin >> 变量`     , 给一个值用于接收变量
+ 示例:

```c++
int main() {
	// 1.int输入
	int v1 = 2;
	cout << "int类型的初始值为" << v1 << endl;
	cin >> v1;
	cout << "你输入的整型值为:" << v1 << endl;
	// 2.float输入
	float v2 = 2.14f;
	cout << "float类型的初始值为" << v2 << endl;
	cin >> v2;
	cout << "你输入的float值为:" << v2 << endl;
	// 3.char输入
	char v3 = 'a';
	cout << "char类型的初始值为" << v3 << endl;
	cin >> v3;
	cout << "你输入的整型值为:" << v3 << endl;
	// 4.string 输入
	string v4 = "121321";
	cout << "int类型的初始值为" << v4 << endl;
	cin >> v4;
	cout << "你输入的整型值为:" << v4 << endl;
	// 5.bool 输入
	bool v5 = false;
	cout << "int类型的初始值为" << v5 << endl;
	cin >> v5;
	cout << "你输入的整型值为:" << v5 << endl;

	system("pause");
	return 0;
}
```

# 3. 运算符

+ 运算符是一种告诉编译器执行特定的数学或逻辑操作的符号。C++ 内置了丰富的运算符，并提供了以下类型的运算符：
  - 算术运算符
  - 关系运算符
  - 逻辑运算符
  - 位运算符
  - 赋值运算符
  - 杂项运算符

| 运算符类型 | 作用                                    |
| ---------- | --------------------------------------- |
| 算术运算符 | 用于处理四则运算                        |
| 赋值运算符 | 用于将表达式的值赋给变量                |
| 比较运算符 | 用于表达式的比较,并返回一个真值 或 假值 |
| 逻辑运算符 | 用于根据表达式的值 返回真值 或 假值     |

## 3.1 算术运算符 和 js一摸一样跳过

假设变量 A 的值为 10，变量 B 的值为 20，则：

| 运算符 | 描述                                                         | 实例             |
| :----- | :----------------------------------------------------------- | :--------------- |
| +      | 把两个操作数相加                                             | A + B 将得到 30  |
| -      | 从第一个操作数中减去第二个操作数                             | A - B 将得到 -10 |
| *      | 把两个操作数相乘                                             | A * B 将得到 200 |
| /      | 分子除以分母                                                 | B / A 将得到 2   |
| %      | 取模运算符，整除后的余数                                     | B % A 将得到 0   |
| ++     | [自增运算符](https://www.runoob.com/cplusplus/cpp-increment-decrement-operators.html)，整数值增加 1 | A++ 将得到 11    |
| --     | [自减运算符](https://www.runoob.com/cplusplus/cpp-increment-decrement-operators.html)，整数值减少 1 | A-- 将得到 9     |

+ **注意 `x++` 和`++x`的区别**(`x--`和`--x`同理)
  + `x++`的返回值 是 `x`
  + `++x`的返回值是`x+1`

## 3.2 关系运算符

假设变量 A 的值为 10，变量 B 的值为 20，则：

| 运算符 | 描述                                                         | 实例              |
| :----- | :----------------------------------------------------------- | :---------------- |
| ==     | 检查两个操作数的值是否相等，如果相等则条件为真。             | (A == B) 不为真。 |
| !=     | 检查两个操作数的值是否相等，如果不相等则条件为真。           | (A != B) 为真。   |
| >      | 检查左操作数的值是否大于右操作数的值，如果是则条件为真。     | (A > B) 不为真。  |
| <      | 检查左操作数的值是否小于右操作数的值，如果是则条件为真。     | (A < B) 为真。    |
| >=     | 检查左操作数的值是否大于或等于右操作数的值，如果是则条件为真。 | (A >= B) 不为真。 |
| <=     | 检查左操作数的值是否小于或等于右操作数的值，如果是则条件为真。 | (A <= B) 为真。   |

+ 注意: 关系运算符比较时,不能与字符串进行比较

## 3.3 逻辑运算符 和 js一样

假设变量 A 的值为 1，变量 B 的值为 0，则：

| 运算符 | 描述                                                         | 实例                 |
| :----- | :----------------------------------------------------------- | :------------------- |
| &&     | 称为逻辑与运算符。如果两个操作数都 true，则条件为 true。     | (A && B) 为 false。  |
| \|\|   | 称为逻辑或运算符。如果两个操作数中有任意一个 true，则条件为 true。 | (A \|\| B) 为 true。 |
| !      | 称为逻辑非运算符。用来逆转操作数的逻辑状态，如果条件为 true 则逻辑非运算符将使其为 false。 | !(A && B) 为 true。  |

+ ! 不能对 string 类型使用

  + ```c++
    string r = "string";
    cout <<!r<<endl;// vs2022报错, !不能对class使用
    ```

## 3.4 位运算符

+ 位运算符作用于位，并逐位执行操作。&、 | 和 ^ 的真值表如下所示：

| p    | q    | p & q | p \| q | p ^ q |
| :--- | :--- | :---- | :----- | :---- |
| 0    | 0    | 0     | 0      | 0     |
| 0    | 1    | 0     | 1      | 1     |
| 1    | 1    | 1     | 1      | 0     |
| 1    | 0    | 0     | 1      | 1     |

+ 假设如果 A = 60，且 B = 13，现在以二进制格式表示，它们如下所示：

  ```
  A = 0011 1100
  
  B = 0000 1101
  
  \-----------------
  
  A&B = 0000 1100
  
  A|B = 0011 1101
  
  A^B = 0011 0001
  
  ~A = 1100 0011
  ```

  

+ 下表显示了 C++ 支持的位运算符。假设变量 A 的值为 60，变量 B 的值为 13，则：

| 运算符 | 描述                                                         | 实例                                                         |
| :----- | :----------------------------------------------------------- | :----------------------------------------------------------- |
| &      | 按位与操作，按二进制位进行"与"运算。运算规则：`0&0=0;    0&1=0;     1&0=0;      1&1=1;` | (A & B) 将得到 12，即为 0000 1100                            |
| \|     | 按位或运算符，按二进制位进行"或"运算。运算规则：`0|0=0;    0|1=1;    1|0=1;     1|1=1;` | (A \| B) 将得到 61，即为 0011 1101                           |
| ^      | 异或运算符，按二进制位进行"异或"运算。运算规则：`0^0=0;    0^1=1;    1^0=1;   1^1=0;` | (A ^ B) 将得到 49，即为 0011 0001                            |
| ~      | 取反运算符，按二进制位进行"取反"运算。运算规则：`~1=-2;    ~0=-1;` | (~A ) 将得到 -61，即为 1100 0011，一个有符号二进制数的补码形式。 |
| <<     | 二进制左移运算符。将一个运算对象的各二进制位全部左移若干位（左边的二进制位丢弃，右边补0）。 | A << 2 将得到 240，即为 1111 0000                            |
| >>     | 二进制右移运算符。将一个数的各二进制位全部右移若干位，正数左补0，负数左补1，右边丢弃。 | A >> 2 将得到 15，即为 0000 1111                             |

+ c/c++ 书写 16/8/2 禁止

  ```c++
  int a=101;// 10进制
  int b=0xEA;// 16进制
  int c=077;//8进制
  int d=0b0010;// c++ 14 开始支持2进制
  ```

+ 异或:  **同为0, 异为1**

2^1 2 0000 0010

2^2 4 0000 0100

2^3 8 0000 1000

2^4 16  0001 0000

2^5 32 0010 0000

2^6 64 0100 0000     60为 2^6-2^2= 0011 1100



## 3.5 赋值运算符

| 运算符 | 描述                                                         | 实例                            |
| :----- | :----------------------------------------------------------- | :------------------------------ |
| =      | 简单的赋值运算符，把右边操作数的值赋给左边操作数             | C = A + B 将把 A + B 的值赋给 C |
| +=     | 加且赋值运算符，把右边操作数加上左边操作数的结果赋值给左边操作数 | C += A 相当于 C = C + A         |
| -=     | 减且赋值运算符，把左边操作数减去右边操作数的结果赋值给左边操作数 | C -= A 相当于 C = C - A         |
| *=     | 乘且赋值运算符，把右边操作数乘以左边操作数的结果赋值给左边操作数 | C *= A 相当于 C = C * A         |
| /=     | 除且赋值运算符，把左边操作数除以右边操作数的结果赋值给左边操作数 | C /= A 相当于 C = C / A         |
| %=     | 求模且赋值运算符，求两个操作数的模赋值给左边操作数           | C %= A 相当于 C = C % A         |
| <<=    | 左移且赋值运算符                                             | C <<= 2 等同于 C = C << 2       |
| >>=    | 右移且赋值运算符                                             | C >>= 2 等同于 C = C >> 2       |
| &=     | 按位与且赋值运算符                                           | C &= 2 等同于 C = C & 2         |
| ^=     | 按位异或且赋值运算符                                         | C ^= 2 等同于 C = C ^ 2         |
| \|=    | 按位或且赋值运算符                                           | C \|= 2 等同于 C = C \| 2       |



## 3.1, 3.2,3.3,3.4,3.5的代码示例

```c++
#include<iostream>
using namespace std;

int main() {
	//1.算术运算符       cpp 中的四则运算
	int a = 1, b = 2;
	char c = 'a';
	double f = static_cast<double>(1) / 2;
	std::cout << 0.1+0.2 << a << b <<"\nchar:"<< c << "\nfloat:" << std::endl;
	std::cout << 30 - 1 << "\n" << 0.2 - 0.1 << std::endl;
	std::cout << 2 * 3 <<"\n" << 02. * 0.3 << std::endl;
	std::cout << f << "\n" << 0.1 / 0.2 << std::endl;
	std::cout << b%a << std::endl;
	int h = 2;
	int i = 2;
	std::cout << h++ << ++i << std::endl;
	int j = 3;
	int k = 3;
	std::cout << j-- << --k <<endl;

	//2.关系运算符
	int l = 10;
	short o = 11;
	string n = "ada";
	bool m = o == l;
	cout << m << endl;
	if (l==o) {
		cout << "o 等于 l" << endl;
	}
	if (l != 0) {
		cout << "o 不等于 l" << endl;
	}
	if (l > 0) {
		cout << "o 大于 l" << endl;
	}
	if (l < 0) {
		cout << "o 小于 l" << endl;
	}
	if (l >=0) {
		cout << "o 大于等于 l" << endl;
	}
	if (l <= 0) {
		cout << "o 小于等于 l" << endl;
	}

	// 3. 逻辑运算符
	int t = 1;
	bool q = false;
	string r = "string";

	cout << "!t:" << !t << endl;// 0
	cout << "!q:" << !q << endl;// 1
	//cout << "!r:" << !r << endl;// string类型不能被强转;
	int x = 1 && 2;
	int y = 1 || 2;
	int z = 10 || 0;
	cout << x<<y<<z<<endl;// 1 1 1

	// 4. 位运算符
	int aA = 60; //0011 1100
	int bB = 13; //0000 1101
	int cC = 0b1000;
	// 4.1 二进制 与 运算 &
	int dD = aA & bB;
	cout <<"二进制 与 运算 & :" << dD << endl;//12 0000 1100
	// 4.2 二进制 或 运算 |
	int eE = aA | bB;
	cout <<" 二进制 或 运算 | :" << eE << endl;//61  0011 1101
	// 4.3 二进制 非 运算 ~
	cout <<"二进制 非 运算 ~ :" << ~cC << endl;// -9 
	// 4.4 二进制 异或 运算 ^
	int fF = aA ^ bB;
	cout <<"二进制 异或 运算 ^ :" << fF << endl;// 49
	// 4.5 二进制左移运算符 << 将一个运算对象的各二进制位全部左移若干位（左边的二进制位丢弃，右边补0）
	int gg = 0b1000 << 2;
	cout << "二进制左移运算符 << :" << gg << endl;//32 100000
	// 4.6 二进制右移运算符 >> 将一个数的各二进制位全部右移若干位，正数左补0，负数左补1，右边丢弃。
	int hh = 0b1000 >> 2;
	cout <<"二进制右移运算符 >> :" << hh << endl;//2 0010

	system("pause");
	return 0;
}
```

## 3.6 杂项运算符

下表列出了 C++ 支持的其他一些重要的运算符。

| 运算符               | 描述                                                         |
| :------------------- | :----------------------------------------------------------- |
| sizeof               | [sizeof 运算符](https://www.runoob.com/cplusplus/cpp-sizeof-operator.html)返回变量的大小。例如，sizeof(a) 将返回 4，其中 a 是整数。 |
| Condition ? X : Y    | [条件运算符](https://www.runoob.com/cplusplus/cpp-conditional-operator.html)。如果 Condition 为真 ? 则值为 X : 否则值为 Y。 |
| ,                    | [逗号运算符](https://www.runoob.com/cplusplus/cpp-comma-operator.html)会顺序执行一系列运算。整个逗号表达式的值是以逗号分隔的列表中的最后一个表达式的值。 |
| .（点）和 ->（箭头） | [成员运算符](https://www.runoob.com/cplusplus/cpp-member-operators.html)用于引用类、结构和共用体的成员。 |
| Cast                 | [强制转换运算符](https://www.runoob.com/cplusplus/cpp-casting-operators.html)把一种数据类型转换为另一种数据类型。例如，int(2.2000) 将返回 2。 |
| &                    | [指针运算符 &](https://www.runoob.com/cplusplus/cpp-pointer-operators.html) 返回变量的地址。例如 &a; 将给出变量的实际地址。 |
| *                    | [指针运算符 *](https://www.runoob.com/cplusplus/cpp-pointer-operators.html) 指向一个变量。例如，*var; 将指向变量 var。 |

## [3.7 运算符优先级](https://www.runoob.com/cplusplus/cpp-operators.html)

运算符的优先级确定表达式中项的组合。这会影响到一个表达式如何计算。某些运算符比其他运算符有更高的优先级，例如，乘除运算符具有比加减运算符更高的优先级。

例如 x = 7 + 3 * 2，在这里，x 被赋值为 13，而不是 20，因为运算符 * 具有比 + 更高的优先级，所以首先计算乘法 3*2，然后再加上 7。

下表将按运算符优先级从高到低列出各个运算符，具有较高优先级的运算符出现在表格的上面，具有较低优先级的运算符出现在表格的下面。在表达式中，较高优先级的运算符会优先被计算。

| 类别       | 运算符                            | 结合性   |
| :--------- | :-------------------------------- | :------- |
| 后缀       | () [] -> . ++ - -                 | 从左到右 |
| 一元       | + - ! ~ ++ - - (type)* & sizeof   | 从右到左 |
| 乘除       | * / %                             | 从左到右 |
| 加减       | + -                               | 从左到右 |
| 移位       | << >>                             | 从左到右 |
| 关系       | < <= > >=                         | 从左到右 |
| 相等       | == !=                             | 从左到右 |
| 位与 AND   | &                                 | 从左到右 |
| 位异或 XOR | ^                                 | 从左到右 |
| 位或 OR    | \|                                | 从左到右 |
| 逻辑与 AND | &&                                | 从左到右 |
| 逻辑或 OR  | \|\|                              | 从左到右 |
| 条件       | ?:                                | 从右到左 |
| 赋值       | = += -= *= /= %=>>= <<= &= ^= \|= | 从右到左 |
| 逗号       | ,                                 | 从左到右 |

# 4. 程序流程结构

+ c/c++ 支持的三种最基本的程序运行结构: <mark>顺序结构, 选择结构, 循环结构</mark>
  + 顺序结构: 程序按照顺序执行, 不发生跳转
  + 选择结构:依据条件是否满足, 有选择的执行相应功能
  + 循环结构:依据条件是否满足,循环多次某段代码

## 4.1 选择结构

### 4.1.1 if语句  ( 和 js的es6写法一样)

+ 作用: 执行满足条件的语句

+ if 条件的三种形式

  + 单行格式 if语句 if(条件){满足条件时,执行的语句}
  + 多行格式 if语句 if(条件满足){条件满足时执行的i语句}else{条件不满足时,执行的if语句}
  + 多条件的 if语句 if(a===1){cout<<a<<endl;}esle if(a===2){cout<<a+2<<endl;}else{}

+ 示例代码: 

  ```c++
  int main() {
  
  
  	// 判断输入的三个数字谁最大
  	int a = 0;
  	int b = 0;
  	int c = 0;
  	cout << "请输如三个最大的数字" << endl;
  	cout << "请输入数字a" << endl;
  	cin >> a;
  	cout << "请输入数字b" << endl;
  	cin >> b;
  	cout << "请输入数字C" << endl;
  	cin >> c;
  	if (a > b) {
  		if (a > c) {
  			cout << "a是这三个数字中最大的" << endl;
  		}else if(a == c){
  			cout << "a和c相等,都比b大" << endl;
  		}
  		else {
  			cout << "c是这三个数中最大的" << endl;
  		}
  	}
  	else if (a == b) {
  		if (a > c) {
  			cout << "a和b相等且是这三个数字中最大的" << endl;
  		}
  		else if (a == c) {
  			cout << "a和b和c相等" << endl;
  		}
  		else {
  			cout << "c是这三个数中最大的" << endl;
  		}
  	}
  	else {
  		if (b > c) {
  			cout << "b是这三个数字中最大的" << endl;
  		}
  		else if (b == c) {
  			cout << "b和c相等,都比a大" << endl;
  		}
  		else {
  			cout << "c是这三个数中最大的" << endl;
  		}
  	}
  
  
  	system("pause");
  	return 0;
  }
  ```

### 4.1.2 三目运算符 和 js的三目运算符一样

+ 作用: 通过三目运算符实现简单的判断

+ 语法: `表达式1?表达式2:表达式3`

+ 解释:

  + 如果表达式1的值为真, 执行表达式2,并返回表达2的结果
  + 如果表达式1的值为假,执行表达式2,并返回表达式2的结果

+ 示例代码:

  ```c++
  int main() {
  	int a = 1;
  	int b = 2;
  	bool c = true;
  	cout << (c ? b * 2 : a - 1) << endl;//4
  	system("pause");
  	return 0;
  }
  ```

### 4.1.3 switch 语句 和 js一摸一样

+ 作用: 执行多条件分支语句

+ 语法:

  ```c++
  switch(表达式){
      case 结果1:执行语句;break;
      case 结果2:执行语句;break;
      ......
      default:执行语句;break;
  }
  ```

+ 示例代码:

  ```c++
  //太简单了, 懒得写了 和js 一摸一样
  int main() {
  	int score;
  	cout << "请给这部电影打分" << endl;
  	cin >> score;
  	cout << "您输入的分数为" << score << endl;
  	switch (score) {
  		case 10:
  			cout << "您认为这部电影很优秀" << endl;
  		break;
  		case 9:
  			cout << "您认为这部电影很优秀" << endl;
  			break;
  		case 8:
  			cout << "您认为这部电影很优秀" << endl;
  			break;
  		case 7:
  			cout << "您认为这部电影比较优秀" << endl;
  			break;
  		default:
  			cout << "这部电影很烂!" << endl; break;
  	}
  	system("pause");
  	return 0;
  }
  ```



## 4.2 循环结构

### 4.2.1 while 循环语句 和js一样

+ 作用: 满足循环条件,执行循环语句
+ 语法:`while(循环条件){循环语句}`
+ 解释:<mark>只要循环的结果为真,就执行循环语句</mark>

+ 示例代码:

  ```c++
  int main() {
  	
  	short a = 0;
  	while (a < 100) {
  		cout << "当前a的值为" << a << endl;// 循环打印a100次
  		a = a + 1;
  	}
  	system("pause");
  	return 0;
  }
  ```

+ [c++ 生成随机数的 一个函数](https://blog.csdn.net/YF_Li123/article/details/75220786)

  + rand() 函数
    + 说明:该函数是一个随机发生器，返回一个随机数值，范围在[0, RAND_MAX]之间。RAND_MAX定义在stdlib.h头文件中，C++中可以使用cstdlib头文件。
  + srand() 函数 
    + 说明:**为了避免<mark>rand()函数</mark>每次生成固定的随机数**，引进srand()函数。该函数的功能是初始化随机数发生器，利用当前系统时间来生成随机数,同样在头文件cstdlib中。

+ 示例代码

  ```c++
  #include<iostream>
  #include<time.h>
  #include<cstdlib>
  
  using namespace std;
  
  int main() {
  
  	//1. 生成一个 0-100的随机数
  	// rand() 会产生一个固定的随机数, 使用srand函数来重置
  	srand((unsigned)time(NULL));
  	int randomNumber = rand() % 100;// 取模100 生成 0-99的1整数
  	int inputNumber;
  	cout << "系统生成了一个随机数,请输入一个0-100的整数" <<randomNumber <<endl;
  	cin >> inputNumber;
  	while (inputNumber != randomNumber) {
  		if (inputNumber > randomNumber) {
  			cout << "你输入的数比系统生成的随机数要大" << endl;
  		}
  		else {
  			cout << "你输入的数比系统生成的随机数要小" << endl;
  		}
  		cin >> inputNumber;
  	}
  	cout << "恭喜你猜对了" << endl;
  	system("pause");
  	return 0;
  }
  ```

### 4.2.2 do...while 语句

+ 作用: 满足循环条件,执行循环语句

+ 语法:`do{循环语句}while{循环条件}`

+ 注意:与 `while`的区别在于 <mark>do...while会先执行一次循环语句</mark>,再判断循环条件;

+ 示例代码:

  ```c++
  int main() {
  	// 打印 0~9
  	int a = 0;
  	do
  	{
  		cout << "当前a的值为:" << a << endl;
  		a = a + 1;
  	} while (a<10);
  	system("pause");
  	return 0;
  }
  ```

+ 水仙花数求值, 求一个三位数的水仙花数

  ```c++
  int main() {
  	// 求出 三位数中第一个的水仙花数
  	int a = 100;
  
  	// 取出a的个位数, 十位数, 和百位数
  	
  	do
  	{
  		int ge = a % 10;
  		int shi = a / 10 % 10;
  		int bai = a / 100;
  		int total = ge * ge * ge + shi * shi * shi + bai * bai * bai;
  		if (total == a) {
  			cout << "水仙花数:" << total << endl;
  		}
  		a = a + 1;
  	} while (a<1000);
  	system("pause");
  	return 0;
  }

###    4.2.3 for循环语句  和js一样

+ 作用:满足循环条件,执行循环语句

  + 语法:for(起始表达式;条件表达式;末尾表达式){循环语句;}

+ 示例代码

  ```c++
  int main() {
  	// 1-100中,找出个位数含有7,或者10位数含有7,或者是7的倍数的,打印敲桌子;
  	for (int i = 1; i < 100; i++) {
  		if (i / 10 ==  7 || i % 10 ==  7 || i % 7 == 0) {
  			cout << "敲桌子" << i << endl;
  		}
  	}
  	system("pause");
  	return 0;
  }
  ```

  

### 4.2.4 嵌套循环

+ 作用:在循环体中再嵌套一层循环,解决一些实际问题

+ 示例代码:

  ```c++
  #include<iostream>
  
  using namespace std;
  
  int main() {
  	// 打印1个 10*10的 矩阵*图
  	for (int i = 0; i < 10; i++) {
  		for (int c = 0; c < 10; c++) {
  			cout << "*  ";
  		}
  		cout << "\n";
  	}
  	system("pause");
  	return 0;
  }
  ```

+ 打印 99 乘法表

  ```c++
  int main() {
  	// 1.打印1个 10*10的 矩阵*图
  	for (int i = 0; i < 10; i++) {
  		for (int c = 0; c < 10; c++) {
  			cout << "*  ";
  		}
  		cout << "\n";
  	}
  	// 2.打印 99乘法表
  	for (int i = 1; i < 10; i++) {
  		for (int c = 1; c <= i; c++) {
  			cout << i << "x" << c << "=" << i * c << "   ";
  		}
  		cout << "\n";
  	}
  	system("pause");
  	return 0;
  }
  ```

  

## 4.3 跳转语句

### 4.3.1 break语句   和js一样

+ 作用:用于跳出选择结构 或者 循环结构

+ break使用的时机:

  + 出现在switch条件语句中,作用是终止case并跳出switch
  +  出现在循环语句中, 作用是跳出当前的循环语句
  + 出现在嵌套循环中**,跳出最近的内层循环**

+ 示例代码:

  ```c++
  ```

### 4.3.2 continue语句

+ 作用:在循环语句中,跳过本次循环中余下未执行的语句,继续执行下一次循环

### 4.3.3 goto 语句

+ 可以无条件跳转语句
+ 语法:`goto 标记`
+ 解释: 如果标记的名称存在,执行到goto语句时,会跳转到指定位置
+ **用于跳出深层嵌套**

### 4.3.4 循环控制语句

循环控制语句更改执行的正常序列。当执行离开一个范围时，所有在该范围中创建的自动对象都会被销毁。

C++ 提供了下列的控制语句。点击链接查看每个语句的细节。

| 控制语句                                                     | 描述                                                         |
| :----------------------------------------------------------- | :----------------------------------------------------------- |
| [break 语句](https://www.runoob.com/cplusplus/cpp-break-statement.html) | 终止 **loop** 或 **switch** 语句，程序流将继续执行紧接着 loop 或 switch 的下一条语句。 |
| [continue 语句](https://www.runoob.com/cplusplus/cpp-continue-statement.html) | 引起循环跳过主体的剩余部分，立即重新开始测试条件。           |
| [goto 语句](https://www.runoob.com/cplusplus/cpp-goto-statement.html) | 将控制转移到被标记的语句。但是不建议在程序中使用 goto 语句。 |

# 5. 数组

## 5.1 概述

+ 所谓数组, 就是一个集合,里面存放了相同类型的数据元素
+ 特点:
  + 1.数组中的每个<mark>数据元素都是相同的数据类型</mark>
  + 2.数组是由<mark>连续的内存</mark>位置组成

## 5.2 一维数组

### 5.2.1 一维数组定义方式

+ 一维数组定义的三种方式:

  + 1.`数据类型 数组名[数组长度]`;
  + 2.`数据类型 数组名[数组长度]={值1,值2,....}`;
  + 3.`数据类型 数组名[]={值1,值2,...}`;

+ 声明数组:

  + 在 C++ 中要声明一个数组，需要指定元素的类型和元素的数量，如下所示：

    ```
    type arrayName [ arraySize ];
    ```

  + 这叫做一维数组。**arraySize** 必须是一个大于零的整数常量，**type** 可以是任意有效的 C++ 数据类型。例如，要声明一个类型为 double 的包含 10 个元素的数组 **balance**，声明语句如下：

    ```
    double balance[10];
    ```

  + 现在 *balance* 是一个可用的数组，可以容纳 10 个类型为 double 的数字。

+ 初始化数组

  + 在 C++ 中，您可以逐个初始化数组，也可以使用一个初始化语句，如下所示：

    ```
    double balance[5] = {1000.0, 2.0, 3.4, 7.0, 50.0};
    ```

  + 大括号 { } 之间的值的数目**不能大于**我们在数组声明时在方括号 [ ] 中**指定的元素数目**。

    如果您省略掉了数组的大小，数组的大小则为初始化时元素的个数。因此，如果：

    ```
    double balance[] = {1000.0, 2.0, 3.4, 7.0, 50.0};
    ```

  + 您将创建一个数组，它与前一个实例中所创建的数组是完全相同的。下面是一个为数组中某个元素赋值的实例：

    ```
    balance[4] = 50.0;
    ```

  + 述的语句把数组中第五个元素的值赋为 50.0。所有的数组都是以 0 作为它们第一个元素的索引，也被称为基索引，数组的最后一个索引是数组的总大小减去 1。以下是上面所讨论的数组的的图形表示：

    ![](E:\Learn\006-cpp\img\array_presentation.jpg)

+ 访问数组元素  (和 js一样)

  + 数组元素可以通过数组名称加索引进行访问。元素的索引是放在方括号内，跟在数组名称的后边。例如：

    ```
    double salary = balance[9];
    ```

    

+ 代码示例:

  ```c++
  int main() {
  	// 1.数组初始化定义 方式1
  	double array1[10];
  
  	//2. 数组的初始化 方式2
  	double array2[] = { 1,2,3,4,5,6,7 };
  	cout << "数组array占用1的内存空间未:" << sizeof(array2)<<"byte" << array2 << endl;
  
  	// 3. 数组的初始化 方式3
  	double array3[3] = { 1,2,3 };
  
  	// 4. 获取字符串长度的方法 strlen(char)
  	 char char1[] ="adadadsaddada";
  	 cout << "use strlen function get string length is :" << strlen(char1);//13
  
  	 // 5. 获取数组类型的方法
  	 string array4[] = { "1","2","3","4" };
  	 cout << "string 类型数组的占用内存空间大小为" << sizeof(array4) << "\n" << sizeof(string) << endl;
  
  
  	 // 6. c++ 中计算数组的长度, 利用sizeof
  	 for (int i = 0; i < sizeof(array4) / sizeof(array4[0]); i++) {
  		 cout << array4[i] << endl;
  	 }
  
  	system("pause");
  	return 0;
  }
  ```


### 5.2.2 一维数组数组名   (c++ 利用sizeof 获取数组长度)

+ 一维数组名称的用于:

  1. 可以用于统计整个数组在内存中的长度
  2. 可以获取数组在内存库中的首地址
  3. **数组名就是数组的首地址**

+ 示例代码:

  ```c++
  	 double array5[] = { 1,2,3,4,5,6,7 };
  	 int a = sizeof(array5); // array5整个数组的长度
  	 int b = sizeof(array5[0]); // 数组单个元素的长度,也可以用array5[1]来替代
  	 int b1 = sizeof(array5[1]);
  	 cout << "array5的数组长度为:" << (a / b) << endl;// 7
  	 cout << "array5数组的长度为" << (a / b1) << endl;// 7
  ```



### 5.2.3 冒泡排序

+  最常用的排序算法,对数组内元素进行排序

  1. 比较相邻的元素.如果第一个比第二个大,就交换他们两个
  2. 对每一个相邻元素做同样的工作,执行完毕后,找到第一个最大值
  3. 重复以上的步骤,每次比较次数 减 1,直到不需要比较

+ 示例代码:

  ```c++
  int main() {
  
  	// 1. 排序前
  	int array1[] = { 3,5,1,0,3,4,7,6,9 };
  	int length = sizeof(array1) / sizeof(array1[0]);
  	for (size_t i = 0; i < length; i++)
  	{
  		cout << array1[i] << " ";
  	}cout << endl;
  
  	// 2.冒泡排序
  	for (int i = 0; i < length - 1; i++) {
  		for (int j = 0; j < length - i - 1; j++) {
  			if (array1[j] > array1[j + 1]) {
  				int temp = array1[j];
  				array1[j] = array1[j + 1];
  				array1[j + 1] = temp;
  			}
  		}
  	}
  
  	//3.排序后
  	for (size_t i = 0; i < length; i++)
  	{
  		cout << array1[i] << " ";
  	}cout << endl;
  
  
  	system("pause");
  	return 0;
  }
  ```

  

## 5.3 二位数组 (多维数组)

+ C++ 支持多维数组。多维数组声明的一般形式如下：

  ```c++
  type name[size1][size2]...[sizeN];
  ```

+ 例如，下面的声明创建了一个三维 5 . 10 . 4 整型数组：

  ```c++
  int threedim[5][10][4];
  ```

### 5.3.1 二维数组

+ 多维数组最简单的形式是二维数组。一个二维数组，在本质上，是一个一维数组的列表。声明一个 x 行 y 列的二维整型数组，形式如下：

```c++
type arrayName [ x ][ y ];
```

+ 其中，**type** 可以是任意有效的 C++ 数据类型，**arrayName** 是一个有效的 C++ 标识符。

  一个二维数组可以被认为是一个带有 x 行和 y 列的表格。下面是一个二维数组，包含 3 行和 4 列：

  ![](E:\Learn\006-cpp\img\two_dimensional_arrays.jpg)

+ 初始化二维数组

+ 多维数组可以通过在括号内为每行指定值来进行初始化。下面是一个带有 3 行 4 列的数组。

  ```c++
  int a[3][4] = {  
   {0, 1, 2, 3} ,   /*  初始化索引号为 0 的行 */
   {4, 5, 6, 7} ,   /*  初始化索引号为 1 的行 */
   {8, 9, 10, 11}   /*  初始化索引号为 2 的行 */
  };
  ```

+ 内部嵌套的括号是可选的，下面的初始化与上面是等同的：

  ```c++
  int a[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};
  ```

+ 访问 二维数组元素

  + 二维数组中的元素是通过使用下标（即数组的行索引和列索引）来访问的。例如：

  ```c++
  int val = a[2][3];
  ```

+ 二维数组的四种定义方式:

  1. `数据类型 数组名[行数][列数]`;

  2. `数据类型 数组名[行数][列数]={{数据1,数据2},{数据3,数据4}}`;
  3. `数据类型 数组名[行数][列数]={数据1,数据2,数据3,数据4}`;
  4. `数据类型 数组名[][列数]`={数据1,数据2,数据3,数据4};

### 5.3.2 二维数组的数组名称

+ 查看二位数组所占用的空间大小

+ 获取二位数组首地址

+ 5.3.1 和 5.3.2的示例代码:\

  + 二维数组的变量占用的空间
  + 二维数组单个占用的空间
  + 二维数组一行占用的空间
  + 二维数组的行数  总占用空间/一行占用的空间 == 行数
  + 一行占用空间/一个占用的空间 == 列数
  + 取址符 & 的使用

  ```c++
  int main() {
  
  	// 1. 二维数组的四种定义方式
  
  
  	//1. 数据类型 数组名[行数][列数]
  	int arr[2][2];
  	arr[0][0] = 1;
  	arr[0][1] = 2;
  	arr[1][0] = 3;
  	arr[1][1] = 4;
  
  	// 2. 数据类型 数组名[行数][列数]={{数据1,数据2},{数据3,数据4}}
  	int arr2[2][2] = { {1,2},{3,4} };
  
  	// 3. 数据类型 数组名[行数][列数]={数据1,数据2,数据3,数据4}
  	int arr3[2][2] = { 1,2,3,4 };
  
  	// 4.数据类型 数组名[][列数]={数据1,数据2,数据3,数据4}
  	int arr4[][2] = { 1,2,3,4 };
  
  	// 5.二维数组大小
  	cout << "二维数组arr 所占用的内存大小:" << sizeof(arr) << endl; //16
  
  	//6. 二维数组 一行所占用的大小
  	cout << "二维数组arr 第一行所占用的内存大小:" << sizeof(arr[0]) << endl;// 8
  
  	//7. 二维数组单个元素 占用空间大小
  	cout << "二维数组arr 第一个元素所占用的内存大小:" << sizeof(arr[0][0]) << endl;//4
  
  	// 8. 二维数组打印 首地址
  	cout << "二维数组arr 地址 16进制:" << arr << endl; //00000004C26FF618
  	cout << "二维数组arr 地址 10进制:" << (unsigned int)arr << endl;//3076389272
  
  	// 9. 二维数组的行数  总占用空间/一行占用的空间 == 行数
  	cout << "二位数组arr的行数为:" << (sizeof(arr) / sizeof(arr[0])) << endl; //2
  	//10. 二维数组的列数 一行占用空间/一个占用的空间 == 列数
  	cout << "二位数组arr的列数为:" << (sizeof(arr[0]) / sizeof(arr[0][0])) << endl; //2
      	// 11. 第一行首地址 和 第二行首地址
  	cout << "arr第一行首地址" << (unsigned long)arr[0]<<"\n" << "arr第二行首地址" << (unsigned long)arr[1] << endl;
  	// 3551524568 3551524576  // 相差12个byte  正好是对应的3 个int 元素
  	//12. 查看第一个元素的地址, 使用 取址符 &
  	cout << "arr 第一个元素的地址" << (int)&arr[0][0] << endl;// 611710696 ,不适用取址符得到的结果是 1
  	system("pause");
  	return 0;
  }
  ```

### 5.3.3 总分最高的

```c++
int main() {
	//计算二维数组中的最大值
	int arr[3][3] = { {100,100,100},{90,500,100} , {30,100,40} };
	//1. 计算arr的 行长度
	int rowCount = sizeof(arr) / sizeof(arr[0]);
	//2. 计算arr的列数
	int colCount = sizeof(arr[0]) / sizeof(arr[0][0]);
	//3. 设置最大值
	int totalScore = 0;
	for (int i = 0; i < rowCount; i++) {
		int total=0;
		for (int j = 0; j < colCount; j++) {
			total = total + arr[i][j];
		}
		cout << "第" << i << "个人总分为:" << total << endl;
		if (total > totalScore) {
			totalScore = total;
		}
	}
	cout << "总分最高的是" << totalScore << endl;

	system("pause");
	return 0;
}
```

# 6.函数

+ 函数是一组一起执行一个任务的语句。每个 C++ 程序都至少有一个函数，即主函数 **main()** ，所有简单的程序都可以定义其他额外的函数。

  您可以把代码划分到不同的函数中。如何划分代码到不同的函数中是由您来决定的，但在逻辑上，划分通常是根据每个函数执行一个特定的任务来进行的。

  函数**声明**告诉编译器函数的名称、返回类型和参数。函数**定义**提供了函数的实际主体。

  C++ 标准库提供了大量的程序可以调用的内置函数。例如，函数 **strcat()** 用来连接两个字符串，函数 **memcpy()** 用来复制内存到另一个位置。

  函数还有很多叫法，比如方法、子例程或程序，等等。

## 6.1 概述

## 6.2函数的定义

+ 函数的定义一般有5个步骤:

  1. 返回值类型
  2. 函数名
  3. 参数列表
  4. 函数体语句
  5. return 表达式

+ 语法:

  ```c++
  return_type function_name( parameter list )
  {
     body of the function
  }
  ```

+ 在 C++ 中，函数由一个函数头和一个函数主体组成。下面列出一个函数的所有组成部分：

  - **返回类型：**一个函数可以返回一个值。**return_type** 是函数返回的值的数据类型。有些函数执行所需的操作而不返回值，在这种情况下，return_type 是关键字 **void**。
  - **函数名称：**这是函数的实际名称。函数名和参数列表一起构成了函数签名。
  - **参数：**参数就像是占位符。当函数被调用时，您向参数传递一个值，这个值被称为实际参数。参数列表包括函数参数的类型、顺序、数量。参数是可选的，也就是说，函数可能不包含参数。
  - **函数主体：**函数主体包含一组定义函数执行任务的语句。

+ 示例代码: 返回参数中最大值

  ```c++
  // 1.定义一个求最大值的函数,输入两个数
  int maxMy(int num1, int num2) {
  	if (num1 > num2) {
  		return num1;
  	}
  	else {
  		return num2;
  	}
  }
  
  
  
  int main() {
  	cout << "5和10谁大" << maxMy(5, 10) << endl;
  
  
  	system("pause");
  	return 0;
  }
  ```

## 6.2 函数的声明

+ 函数**声明**会告诉**编译器函数名称及如何调用函数**。函数的实际主体可以单独定义。

  函数声明包括以下几个部分：

  ```c++
  return_type function_name( parameter list );
  ```

+ 针对上面定义的函数 max()，以下是函数声明：

  ```c++
  int max(int num1, int num2);
  ```

+ 在函数声明中，参数的名称并不重要，只有参数的类型是必需的，因此下面也是有效的声明：

  ```c++
  int max(int, int);
  ```

  ```c++
  void addFun(int, int) {
  
  };
  ```

+ 当您在一个源文件中定义函数且在另一个文件中调用函数时，函数声明是必需的。在这种情况下，您应该在**调用函数的文件顶部声明函数**。

  ```c++
  // 提前声明函数可以,  声明可以有多次,定义 有多次
  void addFun(int param1, int param2);
  
  
  int main() {
  	
  	addFun(2000,10); //2000 10
  	system("pause");
  	return 0;
  }
  
  
  //1. 默认参数
  //void addFun(int param1=20, int param2) { // 默认实参不在形参列表的结尾
  void addFun(int param1, int param2 = 20) {
  	cout << "param1:" << param1 << "\t" << "有默认值param2:" << param2 << endl;
  };
  ```


+ 注意: <mark>函数可以声明无数次, 但只可以被定义一次</mark>

## 6.3 调用函数

+ 创建 C++ 函数时，会定义函数做什么，然后通过调用函数来完成已定义的任务。
+ 当程序调用函数时，**程序控制权会转移给被调用的函数。被调用的函数执行已定义的任务，当函数的返回语句被执行时，或到达函数的结束括号时，会把程序控制权交还给主程序。**

## 6.4 函数参数

+ 如果函数要使用参数，则必须声明接受参数值的变量。这些变量称为函数的**形式参数**。

+ 形式参数就像函数内的其他局部变量，在进入函数时被创建，退出函数时被销毁。

+ 当调用函数时，有三种向函数传递参数的方式：

  | 调用类型                                                     | 描述                                                         |
  | :----------------------------------------------------------- | :----------------------------------------------------------- |
  | [传值调用](https://www.runoob.com/cplusplus/cpp-function-call-by-value.html) | 该方法把参数的实际值赋值给函数的形式参数。在这种情况下，修改函数内的形式参数对实际参数没有影响。 |
  | [指针调用](https://www.runoob.com/cplusplus/cpp-function-call-by-pointer.html) | 该方法把参数的地址赋值给形式参数。在函数内，该地址用于访问调用中要用到的实际参数。这意味着，修改形式参数会影响实际参数。 |
  | [引用调用](https://www.runoob.com/cplusplus/cpp-function-call-by-reference.html) | 该方法把参数的引用赋值给形式参数。在函数内，该引用用于访问调用中要用到的实际参数。这意味着，修改形式参数会影响实际参数。 |

+ 默认情况下，C++ 使用**传值调用**来传递参数。一般来说，这意味着**函数内的代码不能改变用于调用函数的参数**。之前提到的实例，调用 max() 函数时，使用了相同的方法。
+ js 函数参数 也是传值调用, 不会改变 栈中变量的值(地址), 但是对象实际的值在 堆 中, 是可以被改变的

 ## 6.5 参数的默认值  和 js一样

当您定义一个函数，您可以为参数列表中后边的每一个参数指定默认值。当调用函数时，如果实际参数的值留空，则使用这个默认值。

这是通过在函数定义中使用赋值运算符来为参数赋值的。调用函数时，如果未传递参数的值，则会使用默认值，如果指定了值，则会忽略默认值，使用传递的值。

+ 示例代码:

  ```c++
  //1. 默认参数
  //void addFun(int param1=20, int param2) { // 默认实参不在形参列表的结尾
  void addFun(int param1 , int param2=20) {
  	cout << "param1:" << param1 << "\t" << "有默认值param2:" << param2 << endl;
  };
  
  int main() {
  	
  	addFun(2000); //2000 20
  	system("pause");
  	return 0;
  }
  ```

+ 注意:<mark>有默认值的参数必须在形参列表的最后</mark>

## 6.6 Lambda 函数与表达式        (Lambda函数 又叫 箭头表达式)

+ C++11 提供了对匿名函数的支持,称为 Lambda 函数(也叫 Lambda 表达式)。

+ Lambda 表达式把函数看作对象。Lambda 表达式可以像对象一样使用，比如可以将它们赋给变量和作为参数传递，还可以像函数一样对其求值。

+ Lambda 表达式本质上与函数声明非常类似。Lambda 表达式具体形式如下:

  ```c++
  [capture](parameters)->return-type{body}
  ```

+ 例如：

  ```c++
  [](int x, int y){ return x < y ; }
  ```

+ 如果没有返回值可以表示为：

  ```c++
  [capture](parameters){body}
  ```

+ 例如：

  ```c++
  []{ ++global_x; } 
  ```

+ 在一个更为复杂的例子中，返回类型可以被明确的指定如下：

  ```c++
  [](int x, int y) -> int { int z = x + y; return z + x; }
  ```

+ 本例中，一个临时的参数 z 被创建用来存储中间结果。如同一般的函数，z 的值不会保留到下一次该不具名函数再次被调用时。

  **如果 lambda 函数没有传回值（例如 void），其返回类型可被完全忽略**。

+ 在Lambda表达式内可以访问当前作用域的变量，这是Lambda表达式的闭包（Closure）行为。<mark> **与JavaScript闭包不同，C++变量传递有传值和传引用的区别**。</mark>可以通过前面的[]来指定：

  ```
  []      // 沒有定义任何变量。使用未定义变量会引发错误。
  [x, &y] // x以传值方式传入（默认），y以引用方式传入。
  [&]     // 任何被使用到的外部变量都隐式地以引用方式加以引用。
  [=]     // 任何被使用到的外部变量都隐式地以传值方式加以引用。
  [&, x]  // x显式地以传值方式加以引用。其余变量以引用方式加以引用。
  [=, &z] // z显式地以引用方式加以引用。其余变量以传值方式加以引用。
  ```

+ 另外有一点需要注意。对于[=]或[&]的形式，lambda 表达式可以直接使用 this 指针。但是，对于[]的形式，如果要使用 this 指针，必须显式传入：

  ```c++
  [this]() { this->someFunc(); }();
  ```

## 6.7 值传递

+ 所谓值传递, 就是函数调用时实参将 (地址对应的)值传给形参
+ 值传递时,如果形参发生改变,不会影响实参

## 6.8 函数的分文件编写

+ 作用: 让代码结构更加清晰

+ 函数分文件书写的四个步骤:

  + 1. 创建后缀名为 .h 的文件
    2. 创建后缀名为 .cpp 的文件
    3. 在头文件中写函数的声明
    4. 在源文件中写函数的定义

+ 代码示例:

  + 头文件 swap.h 用于声明函数 swap

    ```c++
    // swap.h
    
    #pragma once
    #include<iostream>
    using namespace std;
    
    void swap(int num1, int num2);
    ```

  + 定义函数的文件 swap.cpp

    ```c++
    // swap.cpp
    
    // 引用本地目录的头文件时, 使用双引号
    #include "swap.h"
    
    
    
    void swap(int num1, int param2) {
    	int temp = param2;
    	param2 = num1;
    	num1 = temp;
    	cout << "第一个参数的值被调换后为" << num1 << "\n" << "第二个参数的值被调换为:" << param2 << endl;
    }
    ```

  + 调用这个自定的函数时, 在需要使用的文件中 引入swap.h头文件即可,**引入<mark>声明</mark>了自定义函数的 头文件**时,即可调用该函数

    ```c++
    // main.cpp
    #include<iostream> // 引入系统的头文件
    #include "swap.h" // 引入<mark>声明<mark>了自定义函数的 头文件时,即可调用该函数
    
    
    using namespace std;
    
    int main() {
    
    	swap(1, 2);// 2 ,1
    
    	system("pause");
    	return 0;
    }
    ```

    

# 7 指针

## 7.1 指针的基本概念

+ 指针的作用: 可以通过**指针间接访问内存**
  + 内存编号是 从0 开始记录的,一般用16进制数字表示
  + 可以利用指针变量保存地址

## 7.2 指针的定义 和使用

+ 指针变量定义语法:`数据类型 *变量名`;
+ 指针 就是一个 地址 ,存放地址的变量

+ 示例:

  ```c++
  int main() {
  
  	// 1.指针的定义 指针就是一个 指向内存地址的变量
  	int a = 1000;
  
  	// 1.1 指针的定义
  	int* p;
  
  	// 1.2 指针 取址 赋值
  	p = &a;
  	cout << &a << endl; // &a代表 a的地址
  	cout << p << endl; // 变量 p 存的就是a的值
  
  	// 2. 指针的使用 指针的解引用
  	//通过 * 操作指针变量 指向内存,  取出对应指针变量P的值(地址)对应的值
  	cout << "* p" << *p << endl;//1000
  	cout << "a" << a << endl;// 1000
  
  
  	system("pause");
  	return 0;
  }
  ```

## 7.3 指针所占的内存空间

```c++
int main() {
	cout << "sizeof(int *)=" << sizeof(int *) << endl;//8
	cout << "sizeof(short *)=" << sizeof(short *) << endl;//8
	cout << "sizeof(float *)=" << sizeof(float *) << endl;// 8
	cout << "sizeof(double *)=" << sizeof(double*) << endl;// 8

	// 64位操作系统下, 占用8个字节
    // 32位操作系统, 占用8个字节


	system("pause");
	return 0;
}
```

## 7.4 指向指针的指针,   三级指针,二级指针

+ 指向指针的指针是一种**多级间接寻址**的形式，或者说是一个指针链。

+ 指针的指针就是将指针的地址存放在另一个指针里面。

  通常，一个指针包含一个变量的地址。当我们定义一个指向指针的指针时，第一个指针包含了第二个指针的地址，第二个指针指向包含实际值的位置。

  ![](E:\Learn\006-cpp\img\pointer_to_pointer.jpg)

+ 一个指向指针的指针变量必须如下声明，即在变量名前放置两个星号。例如，下面声明了一个指向 int 类型指针的指针：

  ```c++
  int **var;
  ```

+ 示例:

  ```c++
  int main() {
  	// 1. 指向指针的指针;
  	int a = 10;
  	int* p1 = &a;
  	int** p2 = &p1;
  	int*** p3 = &p2;
  
  	cout << "a的值为" << a << endl; //10
  	cout << "*p1的值为" << *p1 << endl;// 10
  	cout << "*p2的值为" << *p2 << endl;// &p1 即为 指针变量p1的地址
  	cout << "**p2的值为" << **p2 << endl;//10
  	cout << "***p3的值为" << ***p3 << endl;// 10 指针的指针的指针
  
  	system("pause");
  	return 0;
  }
  ```

  

## 7.5 空指针 和野指针

### 7.5.1 空指针: 指针变量指向内存中编号为0的空间

+ 用途: 初始话指针变量

+ 注意:空指针指向的内存是不可以访问的

+ 示例1: 空指针

  ```c++
  int main() {
  	// 1 空指针 用于指针变量初始化
  	int * p = NULL;
  
  	// 2.空指针是不能够进行访问的
  	// 0~255之间的内存编号是系统占用的,因此不可访问
  	//*p = 100;
  
  
  	system("pause");
  	return 0;
  }
  ```

### 7.5.2 野指针:指针指向非法的内存空间

+ 示例2: 野指针:

  ```c++
  int main() {
  	// 野指针
  	// 在程序中, 尽量避免 野指针
  	// (int *)0x1100 将该16进制数字强转为 指针类型的值
  	int* p = (int*)0x1100;// 引发了异常,读取访问权限冲突
  	cout << *p << endl;
  
  	system("pause");
  	return 0;
  }
  ```

+ 将会导致如下错误:

  <img src="E:\Learn\006-cpp\img\wild_pointer.png" style="zoom:50%;" />

## 7.6 const 修饰指针

+ const 修饰指针有三种情况

  1. const 修饰指针,	--常量指针 

     + 语法:`const int * p = &a`, 指向常量的指针

     + 指针指向的值不可以被更改,指针指向可以更改

       ```c++
       int a = 10;
       int c = 20;
       const int * p = &a;// 指针p 指向变量a的地址
       
       *p = 20;// 错误, 解引用 不能修改指针的值(指针的值即为地址)指向的值(这里指向的值为a的值20)
        p= &c; // 正确, 指针的值可以更改
       
       
       ```

       

  2. const修饰常量 ,    -- 指针常量

     + 语法:`int * const p = &a`; 指针的 值是一个常量, 即指针的指向不可被修改

     + 指针指向不能被更改,指针指向的值可以被更改

       ```c++
       int a = 10;
       int c = 20;
       int * const p = &a;
       
       *p = 40;// 正确, 解引用 可以更改指针指向的值, 此时 a = 20
        p = &c;// 错误, 指针变量p 是常量, p的值(即p的指向,变量a的地址,&a)不能够更改
       ```

       

  3. const既修饰指针,又修饰常量

     + 语法:`const int * const p = &a`;  指向常量的指针,且指针的指向是一个常量

     + 指针指向的值不能被修改,指针指向也不能被更改

       ```c++
       int a = 10;
       int c = 20;
       int * const p = &a;
       
       *p = 40;// 正确, 解引用 可以更改指针指向的值, 此时 a = 20
        p = &c;// 错误, 指针变量p 是常量, p的值(即p的指向,变量a的地址,&a)不能够更改
       ```

       

+ 示例代码:

  ```c++
  int main() {
  	int a1 = 10;
  	int c1 = 20;
  
  	// 1. 常量指针   指向常量的指针
  	// 指针变量p的值(即 &a)可以修改, 指针变量p的值指向的值,是一个不能被修改的常量
  	const int * p1 = &a1;
  	//* p1 = 20;// 编译器直接报错, 表达式必须是一个可修改的左值
  	p1 = &c1;// 指针变量的值修改为c1了
  	cout << "现在的a1的值是:" << a1 << "\n" << "现在指针p1的值(地址:)" << p1 << "\n" << "现在指针变量p1的值(地址)指向的值为:" << *p1 << endl;
  
  	// 2.指针常量  指针的值(即指针地址,指针指向)为 一个常量
  	// 指针变量p2的值(即 &a2)不能修改, 指针变量p2的值指向的值,不能被修改
  	int a2 = 10;
  	int c2 = 20;
  	int * const p2 = &a2;
  	* p2 = 20;// 可以修改 指针变量的值指向的值 即 现在 a2是20
  	//p2 = &c;//编译器直接报错, 表达式必须是一个可修改的左值
  	cout << "现在的a2的值是:" << a2 << "\n" << "现在指针p2的值(地址:)" << p2 << "\n" << "现在指针变量p2的值(地址)指向的值为:" << *p2 << endl;
  
  	// 3. const 即修饰指针,又修饰常量
  	// 指针变量p的值(即 &a)不可以修改, 指针变量p的值指向的值,也不能被修改
  	int a3 = 10;
  	int c3 = 20;
  	const int * const p3 = &a3;
  	//* p3 = 20;//编译器直接报错, 表达式必须是一个可修改的左值
  	//p3 = &c3;//编译器直接报错, 表达式必须是一个可修改的左值
  
  	system("pause");
  	return 0;
  }
  ```

## 7.7 指针和数组

+ 利用指针访问数组中的元素

+ 示例: 利用指针 访问数组中的元素

  ```c++
  int main() {
  	// 1. 利用指针来访问一维数组中的每一个元素
  	int arr[4] = { 1,2,3,4 };
  	int length = sizeof(arr) / sizeof(arr[0]);
  	int * p = arr;// 指针指向数组的 首地址
  	for (size_t i = 0; i < length; i++)
  	{
  		cout << "arr[" << i << "]的地址为" << (long long)p << endl;
  		cout << "arr[" << i << "]的值为" <<  *p << endl;
  		p++;// p=p+1 每次加 int类型的 byte
  	}
  
  	system("pause");
  	return 0;
  }
  ```

## 7.8 指针和函数

+ 作用: 利用指针作函数参数,可以修改实参的值

+ c++ 一般的函数参数是值传递,   **不会修改实参, 只会赋值参数的值**

+ 将指针作为函数参数, 则为地址传递,  **会修改实参**

  ```c++
  #include<iostream>
  
  using namespace std;
  
  
  // 1.先声明函数,再定义和使用函数
  void swap(int* p1, int* p2);
  
  
  
  int main() {
  	// 指针用作函数参数
  	int a = 20;
  	int b = 10;
  	swap(&a, &b);// 这时函数不再是传值调用,而是指针调用
  	cout << "a的值:" << a << "\n" << "b的值" << b << endl;// 10 20
  	system("pause");
  	return 0;
  }
  
  // 2.定义函数
  void swap(int* p1, int* p2) {
  	int temp = *p2;// 获取p1指针指向的值
  	*p2 = *p1;
  	*p1 = temp;
  
  }
  ```

+ **能接受指针作为参数的函数，也能接受数组作为参数**，如下所示：

  ```c++
  #include <iostream>
  
  using namespace std;
  
  double getAverage(int * arr, int size);
  
  int main()
  {	
  	int arr[5] = { 1,2,3,4,5 };
  	int length = (sizeof(arr) / sizeof(arr[0]));
  	double avg = getAverage(arr, length);// 数组名 arr 就是数组arr的首地址
  	cout << "平均数为:" << avg << endl;
  	return 0;
  }
  
  // 求参数一数组的平均值
  double getAverage(int* arr, int size) {
  	int total = 0;
  	double avg = 0;
  	for (int i = 0; i < size; i++)
  	{
  		total = total + arr[i];
  	}
  	cout << "总数为:" << total << endl;
  	avg = double(total) / size;
  	return avg;
  }
  ```

  

## 7.9 指针,数组和函数

+ 案例描述: 封装一个函数, 利用冒泡排序, 实现对整型数组的	升序排序

+ 例如数组: int arr[10]={4,3,6,9,1,2,10,8,5,7};

+ 示例代码:

  ```c++
  // 1. 定义一个返回 数组的函数(c++ 不能直接返回数组,但是可以返回地址)
  int* bubbleSort(int* arr,int size);
  
  int main()
  {
  	int arr[] = { 2,6,3,8,1,4,9 };
  	int length = sizeof(arr) / sizeof(arr[0]);
  	bubbleSort(arr,length);
  	for (int i = 0; i < length; i++)
  	{
  		cout << bubbleSort(arr, length)[i] << " ";
  		//cout << arr[i] << " ";
  	}
  	return 0;
  }
  
  
  int* bubbleSort(int* arr,int size) {
  	for (int i = 0; i < size - 1; i++) {
  		for (int j = 0; j < size - i - 1; j++) {
  			if (arr[j] > arr[j + 1]) {
  				int temp = arr[j+1];
  				arr[j+1] = arr[j];
  				arr[j] = temp;
  			}
  		}
  	}
  	return arr;
  }
  ```

+ C++ 返回数组的方法:

  + C++ 中数组不是一个类型, 函数不能直接返回, 可以返回函数内指针的地址,函数体用指针接收

    ```c++
    int* bubbleSort(int* arr,int size) {
    	for (int i = 0; i < size - 1; i++) {
    		for (int j = 0; j < size - i - 1; j++) {
    			if (arr[j] > arr[j + 1]) {
    				int temp = arr[j+1];
    				arr[j+1] = arr[j];
    				arr[j] = temp;
    			}
    		}
    	}
    	return arr;
    }
    ```

# 8. 结构体 (定义时类似于 ts的接口 ,创建时类似于js的字面量对象)

## 8.1 结构体基本概念

+ 结构体属于用户<mark>自定义的类型</mark>,允许用户存储不同的数据类型  (C++ 的typedef)

## 8.2 结构体的定义和使用  (类似于 typescript 中的 接口定义(interface))

+ 定义语法:`struct 结构体名 {结构体成员和列表}`
+ 通过结构体**创建**变量的方式有3种
  1. struct 结构体名 变量名
  2. struct 结构体名 变量名={成员1值,成员2值}
  3. 定义结构体时,顺便创建变量

### 8.2.1 定义结构

+ 为了定义结构，您必须使用 **struct** 语句。struct 语句定义了一个包含多个成员的新的数据类型，struct 语句的格式如下：

  ```c++
  struct type_name {
  member_type1 member_name1;
  member_type2 member_name2;
  member_type3 member_name3;
  .
  .
  } object_names;
  ```

+ **type_name** 是结构体类型的名称，**member_type1 member_name1** 是标准的变量定义，比如 **int i;** 或者 **float f;** 或者其他有效的变量定义。在结构定义的末尾，最后一个分号之前，您可以指定一个或多个结构变量，这是可选的。下面是声明一个结构体类型 **Books**，变量为 **book**：

  ```c++
  struct Books
  {
     char  title[50];
     char  author[50];
     char  subject[100];
     int   book_id;
  } book;
  ```

### 8.2.2 访问结构体成员

+ 为了访问结构的成员，我们使用**成员访问运算符（.）**。成员访问运算符是结构变量名称和我们要访问的结构成员之间的一个句号。



+ 示例:

  ```c++
  #include<iostream>
  
  
  using namespace std;
  
  // 1. 定义结构体
  struct student {
  	string name; //姓名
  	int age;//年龄
  	int score;// 分数
  } stu3; // 结构体变量创建方式3
  
  int main() {
  	// 1. 结构体变量创建方式1
  	student stu1;
  	stu1.name = "张三";
  	stu1.age = 32;
  	stu1.score = 89;
  
  	cout << stu1.name << stu1.age << stu1.score << endl;
  
  	// 2. 结构体变量创建方式2
  	student stu2 = { "李四",24,78 };
  	cout << stu2.name << stu2.age << stu2.score << endl;
  
  
  	// 3.定义结构体的时候,顺便定义变量
  	stu3.name = "王五";
  	stu3.age = 22;
  	stu3.score = 80;
  
  	cout << stu3.name << stu3.age << stu3.score << endl;
  
  	return 0;
  }
  ```

+ 注意: **结构体 创建的时候, struct关键字可以省略, 但是定义的时候不能省略**

## 8.3 创建结构体数组变量

+ 作用: 将自定义的结构体放到数组中, 方便维护 (接口定义)

+ 语法:`struct 结构体名 数组名[元素个数]`={{},{},....{}}

+ 示例:

  ```c++
  // 1. 定义结构体
  struct student {
  	string name; //姓名
  	int age;//年龄
  	int score;// 分数
  }; // 结构体变量创建方式3
  
  int main() {
  	
  	// 2.创建结构体体数组变量
  	student stuArr[3] = { {"张三",32,90},{"李四",12,40},{"王五",23,87} };
  
  	// 3. 给结构体数组中的元素赋值
  	stuArr[2].name = "赵六";
  	stuArr[2].age = 88;
  	stuArr[2].score = 100;
  
  	// 4.便利结构体中的数据
  	int length = sizeof(stuArr) / sizeof(stuArr[0]);
  
  	for (size_t i = 0; i < length; i++)
  	{
  		cout << stuArr[i].name << "\t" << stuArr[i].age << "\t" << stuArr[i].score << "\t" << endl;
  	}
  	return 0;
  }
  ```

## 8.4 结构体指针

+ 作用:  通过指针访问结构体成员

+ 利用操作符 `->`可以通过结构体指针访问结构体属性

+ 示例:

  ```c++
  // 1. 定义结构体
  struct Student {
  	string name; //姓名
  	int age;//年龄
  	int score;// 分数 // 不填写的话,和数组一样,默认
  }; 
  
  int main() {
  	// 1. 创建学生结构体变量,     创建变量时 struct可忽略, 定义时必须要写
  	struct Student Stu1 = {"张三",32,90};
  
  	// 2. 创建指针变量 指向该地址
  	Student* p = &Stu1;
  
  	// 3.指针变量 访问 结构体成员, 通过 -> 符号
  	cout << "  姓名: " << p->name << "  年龄: " << p->age << "  分数: " << p->score << endl;
  
  
  
  	return 0;
  }
  ```

+ 注意: **创建结构体变量时,结构体中没有填写的字段默认输出为0**

## 8.5 结构体嵌套结构体

+ 作用: 结构体中的成员可以是另外一个结构体

+ 例如: 每个老师辅导一个学生, 一个老师的结构体中,记录一个学生的结构体

+ 示例:

  ```c++
  // 1. 定义结构体, 先定义 Tool
  struct Tool {
  	int countPencil;//数量
  };
  
  // 2. 定义Teacher 结构体
  struct Teacher {
  	string name;
  	int age;
  	//struct Student { // 结构体里面定义 一个结构体 是非法的!
  	//	string name; //姓名
  	//	int age;//年龄
  	//	int score;// 分数 // 不填写的话,和数组一样,默认
  	//};
  	Tool tool; // 创建一个结构体变量, 作为一个结构体, 合法的
  };
  
  
  
  int main() {
  	// 3. 创建Teacher结构体变量
  	Teacher teacher;
  	teacher.name = "张三丰";
  	teacher.age = 108;
  	teacher.tool.countPencil = 20;
  
  	// 4. 创建指针变量, 指向该 结构体变量teacher
  	Teacher* p = &teacher;
  
  	// 5. 指针访问成员
  	cout << "teacher下的tool的count: " << p->tool.countPencil << endl;// 20 正常访问
  
  
  
  	return 0;
  }
  ```

## 8.6 结构体做函数参数

+ 作用: 将结构体作为参数, 像函数中传递

+ 传递方式有两种

  + 值传递
  + 地址传递

+ 示例:

  ```c++
  // 将歌曲信息包装为结构体, 然后去打印歌曲信息
  // 1.定义 歌曲信息结构体
  
  struct Song {
  	string name;
  	string author;
  	int second;
  	bool isVIP;
  };
  
  //2.声明函数   值传递
  void printSongInfoByValue(struct Song song);
  
  //3.声明函数  地址传递
  void printSongInfoByAddress(struct Song *song);
  
  int main() {
  
  	// 6. 创建结构体变量
  	Song song = {"七里香","周杰伦",321,true};
  	cout << "结构体占用空间" << sizeof(song) << endl;// 88
  
  	printSongInfoByValue(song); // 值传递
  	cout << "值传递后,原来结构体的名字变为了:" << song.name << endl;//七里香 不变  值传递不会改变原来结构体中成员的value
  
  	printSongInfoByAddress(&song);// 地址传递
  	cout << "地址传递后,原来结构体的名字变为了:" << song.name << endl;// 这是地址传递版本 地址传递, 实参改变了
  	return 0;
  }
  
  
  // 4.定义打印歌曲信息函数  值传递版
  void printSongInfoByValue(struct Song song) {
  	song.name = "这是值传递函数改变了的";
  	cout << "歌曲名: " << song.name << "\n作者: " << song.author << "\n时长" << song.second << "\n是否需要VIP: " << (song.isVIP ? "是" : "否") << endl;
  };
  
  
  // 5.定义打印歌曲信息函数  地址传递版本
  void printSongInfoByAddress(struct Song *song) {
  	song->name = "这是地址传递版本";
  	cout << "歌曲名: " << song->name << "\n作者: " << song->author << "\n时长"<<song->second << "\n是否需要VIP: " << (song->isVIP ? "是" : "否") << endl;
  };
  ```

  

## 8.7 结构体中 const的使用场景

+ 作用: 用const 来防止误操作

  + **地址传递** 相比**值传递**可以节省内存, 但是不安全,数据可能会被修改, 使用常量指针,防止修改

    ```c++
    void printSongInfoByAddress(const Song* song)
    ```

+ 示例:

  ```c++
  // 1.定义 歌曲信息结构体
  struct Song {
  	string name;
  	string author;
  	int second;
  	bool isVIP;
  };
  
  //3.声明函数  地址传递
  void printSongInfoByAddress(Song* song);
  
  int main() {
  
  	// 6. 创建结构体变量
  	Song song = { "七里香","周杰伦",321,true };
  	cout << "结构体占用空间" << sizeof(song) << endl;// 88
  
  	printSongInfoByAddress(&song);// 地址传递
  	cout << "地址传递后,原来结构体的名字变为了:" << song.name << endl;// 这是地址传递版本 地址传递, 实参改变了
  	return 0;
  }
  // 5.定义打印歌曲信息函数  地址传递版本
  void printSongInfoByAddress(const Song* song) {// 地址传递 相比值传递可以节省内存, 但是不安全,数据可能会被修改, 使用常量指针,防止修改
  	song->name = "这是地址传递版本";// 使用常量指针后, 成员value不能被修改
  	cout << "歌曲名: " << song->name << "\n作者: " << song->author << "\n时长" << song->second << "\n是否需要VIP: " << (song->isVIP ? "是" : "否") << endl;
  };
  ```



## 8.8 结构体案例

### 8.8.1结构体案例1

![](E:\Learn\006-cpp\img\结构体案例1.png)

```c++
#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;


//2. 定义 Student结构体
struct Student {
	string sName;
	int score;
};

// 1. 定义 Teacher结构体
struct Teacher {
	string tName;
	struct Student stuArr[5];
};

// 4. 声明 给 结构体成员赋值的函数
void allocateSpace(struct Teacher tArray[], int len);

// 5. 声明打印出所有 memberd的value的函数
void printInfo(struct Teacher tArray[],int len);


int main() {
	srand((unsigned)time(NULL));// 随机数种子
	//3. 创建Teacher 的结构体数组 
	struct Teacher teacherArr[3];
	int length = sizeof(teacherArr) / sizeof(teacherArr[0]);

	//8. 调用 赋值函数
	allocateSpace(teacherArr, length);

	//9.调用 打印函数
	printInfo(teacherArr, length);
	system("pause");
	return 0;
}

// 6. 定义赋值函数
void allocateSpace(Teacher tArray[], int len) {

	string nameSeed = "ABCDE";
	string tName = "Teacher_";
	string sName = "Student_";
	for (int i = 0; i < len; i++)
	{
		tArray[i].tName = tName + nameSeed[i];
		for (int j = 0; j < 5; j++) {
			tArray[i].stuArr[j].sName = sName + nameSeed[j];
			tArray[i].stuArr[j].score = 40 + rand() % 61;
		}
	}
}

// 7. 定义 打印信息的函数
void printInfo(Teacher tArray[], int len) {
	for (int i = 0; i < len; i++)
	{
		cout << "老师的姓名: " << tArray[i].tName << "\n" << "\n\t学生: ";
		for (int j = 0; j < 5; j++) {
			cout << "学生姓名: " << tArray[i].stuArr[j].sName << "学生分数" << tArray[i].stuArr[j].score<<endl;
		}
		cout << endl;
	}
	return;
}
```



### 8.8.2 结构体案例2

+ ![](E:\Learn\006-cpp\img\结构体案例2.png)

```c++
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



