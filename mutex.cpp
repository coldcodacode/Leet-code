#include <iostream>
#include <thread>
#include <mutex>
#include <list>
using namespace std;

class A {
 public:
  /* 把收到的消息（玩家命令）存到队列中 */
  void inMsgRecvQueue() {
    for (int i = 0; i < 100; ++i) {
      std::unique_lock<std::mutex> m_guard1(m_mutex1);
      msgRecvQueue.push_back(i); /* 假设数字 i 就是收到的玩家命令 */
      cout << "inMsgRecvQueue exec, push an elem " << i << endl;
    }
  }
  /* 消息队列不为空时，返回并弹出第一个元素 */
  bool outMsgLULProc(int& command) {
    std::unique_lock<std::mutex> m_guard1(m_mutex1);
    if (!msgRecvQueue.empty()) {
      command = msgRecvQueue.front(); /* 返回第一个元素 */
      msgRecvQueue.pop_front();       /* 移除第一个元素 */
      return true;
    }
    return false;
  }
  /* 把数据从消息队列中取出 */
  void outMsgRecvQueue() {
    int command = 0;
    for (int i = 0; i < 100; ++i) {
      bool result = outMsgLULProc(command);
      if (result)
        cout << "outMsgLULProc exec, and pop_front: " << command << endl;
      else
        cout << "outMsgRecvQueue exec, but queue is empty!" << i << endl;
      cout << "outMsgRecvQueue exec end!" << i << endl;
    }
  }

 private:
  // 下面的list就是共享资源
  list<int> msgRecvQueue; /* 容器（实际上是双向链表）：存放玩家发生命令的队列 */
  mutex m_mutex1;         /* 创建互斥量1 */
};

int main() {
  A obj;
  thread myInMsgObj(&A::inMsgRecvQueue, &obj);
  thread myOutMsgObj(&A::outMsgRecvQueue, &obj);
  myInMsgObj.join();
  myOutMsgObj.join();

  cout << "Hello World!" << endl;
  return 0;
}