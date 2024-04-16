/*
 * @lc app=leetcode.cn id=1114 lang=cpp
 *
 * [1114] 按序打印
 */
/**
 * 多线程编程之加锁
*/
// @lc code=start
#include <iostream>
#include <mutex>
using namespace std;
class Foo {
public:
    Foo() {
        m3.lock();
        m2.lock();
        cout << "firstsecondthird" << endl;
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        m2.unlock();
    }

    void second(function<void()> printSecond) {
        m2.lock();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        m2.unlock();
        m3.unlock();
    }

    void third(function<void()> printThird) {
        m3.lock();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        m3.unlock();
    }
private:
    mutex m3, m2;
};
// @lc code=end

