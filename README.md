# HelloC++

## 代码类说明

- **AcctABC**				:	练习抽象基类以及虚方法的使用
- **BaseDMA**				:	使用动态内存分配和友元的继承范例
- **MIworker**				:	多重继承实例
- **ClassTemplatePractice**	:	类模板范例
- **ClassFriendPractice**	:	友元类范例
- **NestingClassPractice**	:	嵌套类范例
- **ExceptionPractice**		:	程序异常处理范例
- **RTTIPractice**			:	RTTI范例
- **StringPractice**		:	string类的使用范例
- **CoutPractice**			:	使用cout进行输出的使用范例
- **CinPractice**			:	使用cin进行输入的使用范例
- **FilePractice**			:	文件的使用范例

## 关键字、操作符

- **define**
- **typedef**
- **typename**
- **explicit**
- **operator**
- **inline**
- **dynamic_cast**	:	用来判断是否可以安全地将对象的地址赋给特定类型的指针
- **typeid**		:	该操作符使得能够确定两个对象是否为同种类型
- **const_cast**
- **static_cast**
- **reinterpret_cast**
- **extern**		:	变量声明

## 操作符

- 取地址符（操作符&）

- 解引用符（操作符*）

## C++11新特性

- 字面值**nullptr**

- **constexpr**变量

- 别名声明使用**using**

## 知识点

- **声明和定义**

- **引用**

- **指针**

	- void* 指针

- **静态联编和动态联编**

- **内联函数**

- **析构函数**

- ~**友元函数**~

- **复制构造函数**

- **成员初始化列表**

- **类**

	使用**class**或**struct**关键字定义一个类
	
	> 使用**class**和**struct**定义类唯一的区别就是默认的访问控制

- **友元**

	类可以允许其它类或者函数访问它的非公有成员，方法是令其它类或者函数成为它的**友元**

- **派生类**

	- 创建派生类对象时，程序首先调用基类构造函数，然后再调用派生类构造函数
	- 基类构造函数负责初始化继承的数据成员
	- 派生类构造函数主要用于初始化新增的数据成员
	- 派生类构造函数总是调用一个基类构造函数
	- 可以使用初始化成员列表句法指明要使用的基类构造函数，否则将使用默认的基类构造函数
	- 派生类对象过期时，程序将首先调用派生类析构函数，然后再调用基类析构函数
	
	---
	
	> 在派生类方法中，标准的技术是使用作用域解析操作符来调用基类方法

- **虚方法**

	使用关键字**virtual**定义虚方法

	> 如果要在派生类中重新定义基类的方法，通常应将基类方法声明为虚拟的；这样，程序将根据对象类型而不是引用或指针的类型来选择方法版本；为基类声明一个虚拟析构函数也是一种惯例；关键字**virtual**只用于类声明的方法原型中

- **向上强制转换和向下强制转换**

- **抽象基类（abstract base class, 简称 ABC）**

	在原型中使用 **=0** 指出类是一个抽象基类
	
	> 当类声明中包含纯虚函数时，则不能创建该类的对象，即包含纯虚函数的类只用作基类；而要成为真正的 ABC，必须至少包含一个纯虚函数，而在虚函数后缀加上 **=0** 就可以使其成为纯虚函数

- **函数模板**

- **类模板**

- **私有继承**

	使用私有继承，基类的公有成员和保护成员都将成为派生类的私有成员
	
	使用公有继承，基类的公有方法将成为派生类的公有方法，简言之，派生类将继承基类的接口；而使用私有继承，基类的公有方法将成为派生类的私有方法，简言之，派生类不能继承基类的接口，但可以在派生类的成员函数中使用它们

- **保护继承**

- **多重继承（multiple inheritance, MI）**

- **虚基类**

- ~**友元类**~

- **嵌套类**

- **异常**

- **RTTI（运行阶段类型识别, Runtime Type Identification）**

	> RTTI只适用于包含虚函数的类

- **类型转换操作符**

	- dynamic_cast
	- const_cast
	- static_cast
	- reinterpret_cast

	---

	> 以 **const_cast** 为例，这四个操作符的句法都是 **const_cast<type-name>(expression>)** 的形式

- **auto_ptr类**

- **STL**

	**STL**提供了一组表示容器、迭代器、函数对象和算法的模板。**C++ STL**中最基本以及最常用的类或容器无非就是以下几个：
	
	- string
	- vector
	- set
	- list
	- map