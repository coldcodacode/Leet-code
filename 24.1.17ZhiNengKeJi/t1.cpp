#include <stdio.h>

class Foo {
public:
    // 防止隐式的类型转换，指其他类型调用构造函数，隐式转化为该类型
    explicit Foo(int _x) : x(_x) { 
        printf("%d\n", x);
    }
    ~Foo() {
        printf("%d\n", x);
    }

private:
    int x;
};

void nothing() {
    static Foo Foo(-999);
}

int main () {
    Foo* f1 = new Foo(-1);
    Foo f2 = Foo(0);

    for (int i = 1; i <= 2; i++) {
        Foo f3(i);
        Foo(i*10); // 匿名对象在声明结束后就会销毁
        nothing();
    }

    return 0;
}