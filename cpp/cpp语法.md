# CPP语言相关

## 一、::的使用

[参考链接](https://blog.csdn.net/deadmaus/article/details/121539981)

    1. 链接类名和成员名
    2. 表示全局作用域

## 二、top的使用

检查进程占用内存的情况。

## 三、STL容器的赋值是深拷贝

深拷贝（deep copy）和浅拷贝（shallow copy）是在编程中用于复制对象或数据结构的概念，它们有以下区别：

浅拷贝是创建一个新的对象或数据结构，然后将原始对象的元素的引用复制到新对象中。新对象中的元素仍然与原始对象中的元素共享相同的内存地址。如果对其中一个对象进行修改，另一个对象也会受到影响。换句话说，**浅拷贝只复制了对象的引用而不是实际的值**。

深拷贝是创建一个全新的对象或数据结构，并递归地复制原始对象中的所有元素，包括嵌套对象，而不仅仅是引用。**这意味着深拷贝生成的对象与原始对象完全独立**，对一个对象的修改不会影响另一个对象。

浅拷贝的操作通常比深拷贝更快，因为它只涉及复制引用而不是递归地复制整个对象结构。

在某些编程语言中，深拷贝和浅拷贝可能是默认的行为，而在其他语言中，需要明确指定进行哪种类型的拷贝。

总而言之，深拷贝创建了原始对象的完全独立副本，而浅拷贝只复制了对象的引用。因此，如果您希望在修改一个对象时不影响另一个对象，应该使用深拷贝。而如果您只是希望创建一个与原始对象共享一些数据的新对象，或者对性能要求较高，可以使用浅拷贝。

另外，通过copy函数的拷贝也是深拷贝。代码见“深拷贝与浅拷贝.cpp”

[参考链接](https://blog.csdn.net/hanxiaoyong_/article/details/112150777)

## 四、vector容器的push_back()和emplace_back()

功能都是将元素添加到容器末尾，但emplace_back()效率更高，因为它直接在容器末尾构造容器项对象，而不是像push_back()，先创造容器对象，再移动or拷贝到容器末尾。

[参考链接](https://blog.csdn.net/lemonxiaoxiao/article/details/108595548)

## 五、stl容器的push_back操作是创建目标的一个新副本（对于对象），复制值（对于基本类型）

STL（Standard Template Library）容器的push_back操作将传入的元素进行拷贝构造（调用对象的拷贝构造函数）并添加到容器中。

当你调用push_back方法将一个对象添加到容器中时，STL容器会调用该对象的拷贝构造函数（Copy Constructor）创建一个新的对象，并将其添加到容器中。这意味着容器中存储的是新的对象，而不是原始对象的引用。

拷贝构造函数的实现方式可能因对象类型而异。对于基本数据类型（如整数、浮点数等），拷贝构造函数只是简单地将值复制到新的对象中。对于自定义类型，拷贝构造函数可能会执行深拷贝操作，递归地复制对象及其成员。

需要注意的是，STL容器的push_back操作仅涉及拷贝构造函数，而不会进行赋值操作或移动语义。这意味着如果你修改了原始对象，容器中存储的对象不会受到影响，因为它们是独立的副本。

## 六、左值和左值引用，构造函数和析构函数  

1. 在C++中，对象可以在堆上或栈上创建。如果您使用new运算符创建对象，则该对象将在堆上创建。如果您使用类似于以下代码的方式创建对象，则该对象将在栈上创建：

        ```cpp
        MyClass myObject;
        ```

2. 在c++中，对象在使它生效的作用域结束后会调用析构函数。

3. 在c++中，函数返回**左值引用**将不会创建副本，返回一个已存在对象的引用。
   而返回**左值**将返回他的一个副本，该副本通过拷贝构造函数或移动构造函数构造出来。

4. changeName2()错误原因：
   在changeName2()方法内部，你创建了一个名为p的Person对象，该对象是在栈上分配的。然后，你尝试将该对象作为引用返回给调用者。然而，这是一个错误的做法。

   因为p是在栈上分配的局部变量，它的生命周期仅限于changeName2()方法的范围内。一旦方法执行完毕，p对象就会被销毁，它的内存将变为无效。所以在changeName2()方法返回后，引用alias_p2将指向一个已被销毁的对象，这会导致未定义的行为。

   要解决这个问题，你可以考虑使用堆上分配的对象，通过使用new关键字创建一个动态分配的Person对象，并将其作为指针返回。这样，对象的生命周期将在main()函数中进行管理，而不会在方法调用后被销毁。

   下面是修复后的代码示例：

        ```cpp
        Person& Person::changeName2() {
          cout << "call changeName2" << endl;
          Person* p = new Person(); // allocated on the heap
          cout << "ret changeName2" << endl;
          return *p;
        }
        ```

   记得在使用完指针后，释放相应的内存：

        ```cpp
        Person p2;
        std::cout << "origin : \n" << "info: " << &p2.info << endl;
        Person* alias_p2 = &(p2.changeName2());
        std::cout << "alias : \n" << "info: " << &(alias_p2->info) << endl;
        std::cout << (alias_p2 == &p2) << endl;
        delete alias_p2; // 释放通过 new 创建的对象内存
        ```

5. changeName3（）潜在的问题：
   在changeName3()方法中，你创建了一个名为p的Person对象，并尝试将其作为值返回给调用者。然而，由于返回类型是Person而不是Person&，返回的是p的副本，而不是原始对象。这会导致在main()函数中创建一个新的Person对象，而不是引用原始对象。

   在main()函数中，你使用Person alias_p3 = p3.changeName3();语句将changeName3()返回的副本赋值给alias_p3。由于没有定义拷贝构造函数，这会导致默认的浅拷贝，即仅复制指针而不复制实际的数据。这可能会导致悬挂指针，即多个对象共享同一块内存，当其中一个对象销毁时，其他对象仍然保持对该内存的引用，导致未定义的行为。

   为了解决这些问题，你可以按照以下方式进行修改：

   将changeName3()方法的返回类型更改为Person&，以返回原始对象的引用，而不是副本。这将确保在main()函数中引用的是原始对象。

   在Person类中定义拷贝构造函数，以确保进行深拷贝，复制实际的数据而不仅是指针。

   以下是修改后的代码示例：

        ```cpp
        Person& Person::changeName3() {
            cout << "call changeName3" << endl;
            cout << "ret changeName3" << endl;
            return *this;
        }

        Person::Person(const Person& other) {
            info = new char[size];
            strncpy(info, other.info, size);
        }

        int main() {
            Person p3;
            std::cout << "origin : \n" << "info: " << &p3.info << endl;
            Person& alias_p3 = p3.changeName3();
            std::cout << "alias : \n" << "info: " << &alias_p3.info << endl;
            std::cout << (&alias_p3 == &p3) << endl;

            return 0;
        }
        ```

## 七、lambda function  

    ```cpp
    auto arrayHash = [fn = hash<int>{}] (const array<int, 26>& arr) -> size_t {
                return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {
                    return (acc << 1) ^ fn(num);
                });
            };
    ```

arrayHash = []：表示这是一个lambda函数。函数名是arrayHash，[fn = hash< int>{}]表示捕获一个变量fn，并用hash<>给他赋值；  
(const array<int, 26>& arr)：表示声明了参数类型和名字；  
-> size_t：指明返回类型；  
接下来就是函数体。
在函数体内同样使用了一个lambda表达式，[&]表示在这个lambda函数体内使用的所用变量都将用引用的形式，这暗示了不会产生一个变量副本copy。  
In sum， the arrayHash lambda function takes an array of 26 integers, applies a hash function to each element, and accumulates the hash values into a final result.  

## 八、哈希表  

unordered_map的底层实现是哈希表。在哈希表中bucket是一个储存哈希结点链表的一个一个桶。哈希结点是以<key, value>形式挂载链表上的。实际创建一个unoedered_map时，他的bucket大小由多种因素决定，包括装载因子、创建map时指定的参数等，编译器会根据实际情况调整bucket的大小，但每次调整意味着重构哈希表，这将耗费很多时间。所以传入一个科学的bucket大小很有必要，如果可能的话。  
定义hash function时，记住他的返回值是一个size_t，（根据模版template）。

## 九、cpp栈堆机制  

[好文要顶](https://zhuanlan.zhihu.com/p/313608043)
  
1. 从memset函数的使用开始：  
头文件 string.h  
函数原型 void\* memset(void\*, int, size_t)，作用是把指定内存块指定大小的内存，以字节为单位赋值int对应的二进制码。  
2. 到初始化一个数组：  
   发现cpp定义数组需要用常量指定数组大小。动态定义数组需要用new。得知原因是编译阶段需要计算栈区大小（计算函数中所有局部变量的占用空间）。
3. 提问为什么要编译时确定栈空间大小：是语言特性
4. 在上述文章内学习了cpp栈堆机制，原来每个函数都会分配一个栈帧，如果函数内调用替他函数，则栈区分配一个新的栈区。**esb寄存器**保存一个栈地址，使快速找到**函数参数、返回地址**等信息。通过esb寄存器和栈帧中保存的caller函数esb寄存器指向的地址，形成一个函数调用链。  
5. 一个函数的栈帧自上而下分别是参数，返回地址，ebp寄存器的值，局部变量区，寄存器的值（保存现场用）。
6. 函数的返回值：4字节--》eax寄存器，8字节--》eax edx寄存器，大于8字节，callee栈帧会保存一个指针，指向caller的局部变量区一个未使用空间，那里保存返回值。
7. 同时也更理解递归层数太深导致栈区溢出是什么原因了。

## 十、cpp多线程

1. 先说从何引出这个问题：  

+ Java如何开启一个线程？只有Tread类对象才能使用start（）方法  

  + 继承Thread类，重写run（）方法，创建一个类实例即可start（）线程
  + 实现Runable（）接口，chongxierun（）方法，创建一个Thread代理类，代理类启动start（）
+ 两种方式有什么区别？**第二种方式更方便进行资源共享**，具体方式是一份资源（一个实例），多份代理，各代理之间共享一个实例
  + Java中start（）和run（）方法的区别。
    + start是一个线程开启，该线程进入就绪状态，得到操作系统调度，就开始执行。start内部会调用run，run方法体的指令执行完意味着线程执行完毕
    + 如果直接调用run方法，与普通的调用函数无异，并不会开启线程。
+ 贴一个讲得比较清楚的文章，同时讲述了线程生命周期[好文要顶](https://zhuanlan.zhihu.com/p/134235964)

1. 因为我是学cpp的，所以也要掌握cpp的多线程啦

+ mutex：  
  + 是一个互斥量，线程通过对他上锁lock（）和unlock（），实现对共享资源的控制。
  + 如果当前互斥量没有被锁住，则调用线程锁住这个互斥量
  + 如果当前互斥量被其他线程锁住，则调用线程阻塞
  + 如果当前互斥量被调用线程锁住，则死锁（不允许同一线程多次上锁同一互斥量）
+ unique_lock\<mutex> ：
  + 是一个类，（类似vector\<int></int>），与mutex配合使用，使我们不直接操作mutex，unique_lock的构造函数和析构函数会执行上锁解锁操作。
  + unique_lock掌握mutex的所有权，即不能两个unique_lock绑定同一个mutex，但可以做所有权的转让，类似智能指针。

        ```cpp
        unique_lock<mutex> ul(myMutex);
        <--!
        这个操作就绑定了一个mutex给unique_lock，并完成上锁
        -->
        ```

  + 贴一个链接[unique_lock](https://zhuanlan.zhihu.com/p/532487790)
  + condition_variable:  
    + 配合unique_lock使用，用来阻塞线程，并在收到唤醒信号，且满足唤醒条件时被唤醒。
    + letecode 1114

`std::condition_variable` 是一种用来同时阻塞多个线程的**同步原语**（synchronization primitive），**`std::condition_variable` 必须和 `std::unique_lock` 搭配使用**：

    ```cpp

    class Foo {
        condition_variable cv;
        mutex mtx;
        int k = 0; // 条件变量 
    public:
        void first(function<void()> printFirst) {
            printFirst();
            k = 1;
            cv.notify_all();    // 向所有阻塞线程发送唤醒信号
        }

        void second(function<void()> printSecond) {
            unique_lock<mutex> lock(mtx);   // lock mtx
            cv.wait(lock, [this](){ return k == 1; });  // unlock mtx，并阻塞线程，收到唤醒信号且满足条件才能继续执行
            printSecond();
            k = 2;
            cv.notify_one();    // 随机通知一个（unspecified）在等待唤醒队列中的线程
        }

        void third(function<void()> printThird) {
            unique_lock<mutex> lock(mtx);   // lock mtx
            cv.wait(lock, [this](){ return k == 2; });  // unlock mtx，并阻塞线程，收到唤醒信号且满足条件才能继续执行
            printThird();
        }
    };
    ```

## 腾讯客户端8.29面试——语言面

### 十一、字节序

  分为大端序和小端序。大端序是

### 十二、字节对齐

  分两步：  

+ 每个成员变量的对齐原则是，min（#pragma pack()， **成员自身的字节数**）
  + 如果成员仍然是一个结构体类型，则**成员自身字节数** = 它最大成员的字节数
+ 结构体（联合体）整体的对齐原则是，min（#pragma pack(), 最大成员的字节数）
  + 整体对齐是为结构体数组设置的，保证结构体数组内的成员仍然对齐。

  注意联合体最后要做整体的对齐。  
  数组看成连续的基本类型，比如int a[10]，就是十个int类型。

为什么要对齐？

+ 提高cpu的访存效率。因为在CPU眼中，内存是一块一块的，cpu按块取内存，对齐后能减少访存次数。

      ```cpp
      struct B{ char b; int a; short c;};sizeof(B); // 12
      ```

### 十三、sizeof是在求什么

sizeof 求的是对象或类型的大小。如果sizeof一个指针，返回指针大小

    ```cpp
    char *p = new char[10];
    printf("%d\n", sizeof(p)); // 8 指针大小
    printf("%d\n", sizeof(*p)); // 1 char大小
    ```

另外，指针大小和操作系统的位数有关。  

#### 操作系统位数和cpu位数？

操作系统位数决定内存的寻址空间，32位意味着4GB（2^32）内存  
cpu位数决定cpu一次操作处理的最大位数，她决定寄存器位数，和数据总线的宽度。

### 十四、了解的编码方式

### 十五、malloc和new有什么区别

[malloc的实现原理？](https://www.cnblogs.com/ssezhangpeng/p/10808969.html#_label3_0)：  
对于小于128K的空间申请，在**虚拟地址空间**的**堆空间**分配空间，因为malloc没有初始化，所以不会申请实际的物理页。当触发缺页中断时，才会分配物理内存，并建立和虚拟内存的映射关系。而对于大于128K的空间申请，则是在虚拟空间堆栈之间的一段空闲空间（**文件映射区**）上分配。  

free释放内存时，会直接还给操作系统吗？

对于小于128K的空间申请，malloc会维护未分配内存和已分配内存，他们都在malloc管理的内存池中。这个**内存池**的增减时与操作系统交互的结果，具体来说，操作系统有一个堆顶指针，malloc需要申请内存而他本身的内存池不够时，他会向操作系统借空间（堆顶指针向上移动），这样它的内存池就变大了。当free函数调用，molloc维护的内存池不会减少（堆顶指针不动），只是标记相应区域为空闲，molloc何时将内存池归还操作系统，取决于具体实现和操作系统。  
对于大于128K的空间申请，malloc直接把内存归还操作系统。

free如何知道释放多少空间？

[free函数](https://www.bilibili.com/video/BV1h34y137xJ/?spm_id_from=pageDriver&vd_source=c6777edd96c9fb88c04c1f264668b689)  
根据struct malloc_chunk结构体中的size字段确认。

1. malloc返回的指针类型是void*，而new返回的指针类型是相应类型指针，不需要做显示类型转换。
2. malloc需要给出申请空间字节大小，new根据类型直接分配。
3. malloc只申请空间，不会做初始化，new会调用构造函数进行初始化。

### 十六、vector和list有什么区别

vector底层是动态数组，高效的随机存取O（1），但插入和删除时，会导致内存块的拷贝。
list底层是双向链表，低效的随机存取O（n）

### 十七、什么是野指针

是指向无效内存区域的指针。通常由**指针没有初始化**、**指针使用后没有置空**、**指针指向的区域已经被释放**造成。

### 十八、什么是内存泄漏

### 十九、析构函数能用虚函数吗

### 二十、函数调用过程

### 二十一、堆和栈有什么区别

在堆上new一个对象，它的生命周期如何？

### 二十二、一个进程有几个堆几个栈

一个进程的所有线程共享一个堆，每个线程有一个栈。

### 二十三、虚拟地址物理地址

___
___

## 二十四、cpp如何编译一个类  

[c++类在内存中的存储方式](https://zhuanlan.zhihu.com/p/103384358)  
  cpp类中的成员函数和非成员函数，都是存放在代码区。所以类中的普通成员函数，友元函数，内联函数，静态成员函数，都不占用类的内存空间，但是类的虚函数，需要维护一个指向虚函数表的指针，所以需要为这个指针分配空间。  
  cpp类对象的大小主要由两部分组成，一部分为非静态成员变量，另一部分为虚函数指针（如果有虚函数的话）。所以

    ```cpp
      void someFunction() {
        myClass cl;
      }
    ```
  上面的这段代码，在栈中申请了一段空间给自定义类myClass，首先栈中会分配空间给someFunction的栈帧，其中预留了myClass对象的大小。而后会调用myClass的构造函数，以分配对象空间和初始化对象的成员变量。当函数返回时，首先调用myClass的析构函数来回收空间，再将someFunction栈帧释放。
  
## 二十五、cpp右值不能赋给没有const修饰的左值引用

## 二十六、stl容器

  如果你定义一个stl容器如下，他在栈上分配内存，是vector对象本身，而非他存储的内容。这24个字节中包括一个8字节的指向堆中动态数组的指针。所以，vector容器是在栈上消耗较少的空间，存储在容器中的内容分配在堆上。  

    ```cpp
      vector<string> v;
      cout << sizeof v; // 24
    ```

## 二十七、cpp中==运算符

  对于指针，比的是指针指向的地址一不一致
  对于stl容器，比的是存储的元素是否一摸一样
  对于string，比的是字符串内容是否一摸一样

    ```cpp
    int test_a, test_b;
    int* p1 = &test_a;
    int* p2 = p1;
    cout << (p2 == p1) << endl; // 1
    int* p3 = &test_b;
    cout << (p3 == p1) <<endl; // 0

    string str = "aaa";
    string str2 = str;
    cout << (str == "aaa") <<endl; // 1
    cout << (str2 == "aaa") <<endl; // 1
    cout << (str == str2) << endl; // 1

    vector<int> v1(5,0);
    vector<int> v2 = v1; // 需要拷贝复制
    cout << (v2 == v1) << endl; // 1
    vector<int> v3 = move(v1); // 左值转为右值引用，所有权转换
    cout << (v2 == v1) << endl; // 0
    cout << (v3 == v1) << endl; // 0
    vector<int> v4(5, 0);
    cout << (v3 == v4) << endl; // 1
    vector<int> v5(10, 0);
    cout << (v3 == v5) << endl; // 0
    ```

## 二十八、cpp只在堆or只在栈上分配类对象

  [指路](https://blog.csdn.net/tonglin12138/article/details/85925620): <https://blog.csdn.net/tonglin12138/article/details/85925620>  
  简单来说：若想只能在堆上创建，就断绝外界对构造函数和拷贝函数的调用，通过private关键字做到这一点；若只想在栈上创建，就断绝外界对new delete关键字的使用，通过private关键字实现。

## 二十九、allocator（简单了解）

这是为了自定义分配空间，并初始化对象用的。例如

    ```cpp
    allocator<int> allo;
    vector<int> v(allo); // 传递一个allocator， 自定义vector的内存管理方式。
    ```

## 三十、vector的push_back 与 拷贝

当未指定vector的size时，如果push的元素超出了容量，就会扩容，vector的扩容规则是，扩大到原来的两倍。扩容的过程涉及到拷贝复制，具体来说，有一个vector存储class node的对象，在vector容量不够时，他先拷贝构造这个vector内的所有元素（用到node类的拷贝构造函数），把他们放在新的容器（新容器的容量是旧容器的二倍），然后调用node的析构函数，消除原来vector中的node对象。  

    ```cpp
    #include<iostream>
    #include<stdio.h>
    #include<vector>

    using namespace std;
    int num = 0;
    class Node{
    public:
        int a;
        Node(int a){
            this->a = a;
            cout<<this<<" "<<"construction\t"<<a<<endl;
        }
        Node(const Node & node){
            num++;
            this->a = node.a;
            cout<<this<<" "<<"copy\t\t"<<a<<endl;
        }
        ~Node(){
            cout<<this<<" "<<"dismantle\t"<<a<<endl;
        }
    };
    int main(){
    //  freopen("in.txt", "w", stdout);
        vector<Node> vect;
        for (int i = 0; i<5; i++){
            vect.push_back(Node(i));
            cout << "echo" << endl;
        } 
        cout<< "nums of copy called: " << num<<endl;
    }
    ```

## 三十一、cpp中的static关键字

[reference](https://blog.csdn.net/sevenjoin/article/details/81772792)  
对于static修饰全局变量/局部变量/函数，与C语言中的static作用相同。  
这里主要强调一下，static在面向对象中的应用，具体来说：

+ statics修饰成员变量，这个成员属于整个类，不属于某个对象，意味着只能初始化一次。所以cpp中要求，**static成员变量只能在类外初始化**。且**一定要初始化**，因为如果不在类外初始化，cpp不会为其分配内存，（尽管在类中已经声明，但没有定义，也就是不分配内存）。
+ 一个例外是，如果static const修饰的成员变量，可以在类中声明的同时初始化。

        ```cpp
        class MyClass {
        public:
            static const int myStaticConstVar = 10;
        };
        ```

## 三十二、单例模式

[github:CPPthings](https://github.com/Light-City/CPlusPlusThings/tree/master/design_pattern/singleton)

## 三十三、关于线程切换上下文信息保存在哪里

-线程切换时，上下文信息保存在哪里？
-Poe
在操作系统中，当线程切换时，上下文信息通常保存在线程的控制块（Thread Control Block，TCB）中。TCB是用于管理和跟踪线程的数据结构，它包含了线程的状态以及与线程执行相关的各种信息。

TCB中保存的上下文信息包括但不限于以下内容：
寄存器状态：线程切换时，当前线程的寄存器状态会保存到TCB中，包括通用寄存器、程序计数器（PC）、堆栈指针（SP）等。这些寄存器保存了线程执行的上下文信息。
堆栈信息：线程的堆栈指针（SP）指向当前线程的堆栈空间，堆栈中保存了函数调用的上下文信息，包括局部变量、函数参数、返回地址等。当线程切换时，当前线程的堆栈信息也需要保存到TCB中。
资源状态：线程可能在执行过程中获得了一些资源，比如打开的文件、网络连接等。这些资源的状态也需要保存在TCB中，以便在线程切换后能够正确地恢复。
当操作系统进行线程切换时，它会根据调度算法选择下一个要执行的线程，并从该线程的TCB中恢复上下文信息。操作系统会将上下文信息加载到适当的寄存器和堆栈中，使得线程可以继续执行。这个过程通常是由操作系统内核提供的线程调度器完成的。

-TCB是保存在哪里，操作系统的内核区域吗？
-Poe
是的，TCB通常保存在操作系统的内核区域。内核区域是操作系统的核心部分，负责管理和调度系统资源，包括线程和进程。TCB作为线程的控制块，包含了线程的状态和相关的信息，因此需要在内核区域中进行管理。

具体而言，TCB可以在内核的数据结构中分配内存空间。这些数据结构通常由操作系统提供，并且在内核初始化过程中进行分配和初始化。每个线程都有一个对应的TCB，当线程被创建时，操作系统会分配一个TCB并将其相关信息填充到其中。TCB的内存空间通常在内核堆或内核栈中分配，这些内存区域是内核专用的，无法直接被用户程序访问。
由于TCB保存在内核区域，用户程序无法直接访问和修改它们的内容。线程的创建、切换和管理等操作需要通过操作系统提供的系统调用接口来进行。通过这些接口，用户程序可以与操作系统交互并请求线程的创建、切换或其他操作，而操作系统则负责在内核区域中管理和操作TCB。

-同一进程的不同线程有不同的堆栈空间吗，那线程调度后，如何保证上一个线程堆栈中的信息不被修改和覆盖？
-Poe
在同一进程中，不同线程通常会拥有各自独立的堆栈空间。每个线程都有自己的栈帧，用于保存函数调用的局部变量、参数和返回地址等信息。这些栈帧位于各自线程的堆栈空间中，是线程私有的。
当线程调度发生时，操作系统会负责保存和恢复线程的上下文信息，包括堆栈指针（SP）。在切换到下一个线程之前，操作系统会将当前线程的堆栈指针保存到其对应的线程控制块（TCB）中。
这样，在线程切换后，当操作系统再次调度回上一个线程时，它能够从TCB中获取上一个线程的堆栈指针，并将其恢复到寄存器中。这样，上一个线程的堆栈指针指向的位置仍然是它在切换之前的状态，保证了上一个线程堆栈中的信息不被修改和覆盖。

需要注意的是，线程之间的堆栈空间是独立的，但它们通常是在同一进程的虚拟地址空间中。因此，一个线程无法直接读取或修改另一个线程的堆栈数据。这种隔离性确保了线程之间的数据不会相互干扰，同时操作系统的调度机制能够保证上下文切换时的数据完整性。

-也就是说不同线程的栈帧在同一进程虚拟空间的不同位置，他们相互不会干扰？
-Poe
正确，不同线程的栈帧在同一进程的虚拟地址空间中的不同位置，它们是相互独立的，不会相互干扰。每个线程有自己的栈指针（SP），它指向线程的当前栈帧，用于保存局部变量、函数参数和返回地址等。当线程切换时，操作系统会保存和恢复线程的栈指针，以确保每个线程在被调度执行时，可以从正确的栈帧中获取和保存数据。
由于线程的栈帧位于不同的堆栈空间中，线程之间的栈操作不会相互干扰。一个线程的栈操作（如入栈和出栈）不会影响其他线程的栈内容。这种隔离性确保了线程之间的数据独立性和安全性。

需要注意的是，虽然不同线程的栈帧位于不同的虚拟地址空间位置，但它们共享进程的其他资源，比如堆和全局变量。因此，在多线程编程中，需要注意对共享资源的访问，以避免数据竞争和并发访问的问题。这可以通过使用同步机制（如互斥锁、条件变量等）来保护共享数据，确保线程之间的正确协作和数据一致性。

## 三十四、构造函数、拷贝构造函数、移动构造函数

  下面的例子解释了如何编写拷贝构造函数，移动构造函数。另外，vector容器的初始化会调用默认构造函数；下面的例子声明了一个容量为3的vector，所以调用了三次默认构造函数。

    ```cpp
    class MyStruct
    {
    public:
        char *data;
        size_t len;

        MyStruct() : data(nullptr), len(0)
        {
            std::cout << "Default constructor\n";
        }

        MyStruct(const char *str)
            : len(std::strlen(str)), data(new char[len + 1])
        {
            std::strcpy(data, str);
            std::cout << "Standard constructor\n";
        }

        MyStruct(const MyStruct &other)
            : len(other.len), data(new char[other.len + 1])
        {
            std::strcpy(data, other.data);
            std::cout << "Copy constructor\n";
        }

        MyStruct(MyStruct &&other) noexcept
            : len(other.len), data(other.data)
        {
            other.len = 0;
            other.data = nullptr;
            std::cout << "Move constructor\n";
        }

        MyStruct &operator=(const MyStruct &other)
        {
            if (this != &other)
            {
                delete[] data;
                len = other.len;
                data = new char[len + 1];
                std::strcpy(data, other.data);
            }
            std::cout << "Copy assignment operator\n";
            return *this;
        }

        MyStruct &operator=(MyStruct &&other) noexcept
        {
            if (this != &other)
            {
                delete[] data;
                len = other.len;
                data = other.data;
                other.len = 0;
                other.data = nullptr;
            }
            std::cout << "Move assignment operator\n";
            return *this;
        }

        ~MyStruct()
        {
            std::cout << "Destructor\n";
            delete[] data;
        }
    };

    int main()
    {
        std::vector<MyStruct> myVector(3);
        std::cout << std::endl;

        // myVector.emplace_back(); // 使用emplace_back而不是push_back
        // std::cout << std::endl;

        MyStruct ms("Hello");
        myVector[0] = ms;
        // myVector.push_back(ms);
        std::cout << std::endl;

        MyStruct ms1("World");
        myVector[1] = std::move(ms1);
        // myVector.push_back(std::move(ms1));
        std::cout << std::endl;

        // myVector[2] = MyStruct("cpp");
        // std::cout << std::endl;

        std::cout << (ms.data != nullptr) << " " << (ms1.data == nullptr) << "\n";
        for (const auto &it : myVector)
        {
            std::cout << &it << '\n';
            if (it.data != nullptr)
            {
                std::cout << it.data << "\n";
            }
        }
        std::cout << "ms's address is: " << &ms << '\n' 
                << "ms1's address is:" << &ms1 << '\n'
                << "myVector's address is: " << &myVector << '\n'
                << "myVector[0]'s address is: " << &myVector[0] << '\n'
                << "myVector[1]'s address is: " << &myVector[1] << '\n';
        return 0;
    }

    ```

## 美团笔试4.13，t5涉及的一些cpp问题

### 三十五、for循环简洁的遍历方式

    ```cpp
    for (auto i : list) {
        cout << i;
    }
    ```
这里i返回的并不是容器中的元素，而是元素的一个全新副本。如果想要返回容器中的元素，使用auto&。
    ```cpp
    for (auto& i : list) {
        cout << i;
    }
    ```

### 三十六、在string后添加一些字符和一个字符

添加一些字符用append（const char*）；  
添加一个字符用push_back(char)。

### 三十七、如果在for遍历中向容器中插入新元素，新元素会被遍历吗？

取决于容器类型：  

1. 对于vector、string、deque、array等线性容器，可能导致迭代器失效；
2. 对于list、set、map、multiset、multimap等节点容器，不会导致迭代器失效，但新插入的元素是否会被遍历取决于插入的位置和遍历的方向；
3. 对于unordered_set、unordered_map等无序容器，可能导致迭代器失效，因为插入可能触发容器rehash。

___
___

## leetcode 146 lru缓存涉及的cpp问题

### 三十八、容器中不能存引用类型的元素

因为引用不能被复制和移动，容器要求其存储的元素可以复制和移动。

### 三十九、move函数作用后的变量，就不能被使用了

因为move函数把变量的所有权转移。

    ```cpp
    // fatal
    pLinkNode temp = new linkNode(key, value);
    hashTable[key] = std::move(temp); // move将一个左值转换为右值引用。移动赋值运算符和移动构造函数执行移动操作。这允许你在不创建副本的情况下将资源从一个对象移动到另一个对象。
    addNode(temp); // 在std::move之后，temp已经不再拥有linkNode对象，其值已经变为未定义。
    // correct
    pLinkNode temp = new linkNode(key, value);
    addNode(temp);
    hashTable[key] = std::move(temp);
    ```

___
___

## 四十、
