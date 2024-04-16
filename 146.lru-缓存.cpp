/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
#include <map>
#include <iostream>
using namespace std;
struct linkNode
{
    int key;
    int value;
    struct linkNode *last;
    struct linkNode *next;
    linkNode() : last(nullptr), next(nullptr) {}
    linkNode(int key, int value) : key(key), value(value), last(nullptr), next(nullptr) {}
    linkNode(int key, int value, linkNode *last, linkNode* next) : key(key), value(value), last(last), next(next) {}
};
typedef struct linkNode *pLinkNode;
struct deQueue
{
    int size;
    pLinkNode front;
    pLinkNode rear;
    deQueue(int size)
    {
        this->size = size;
        this->front = new linkNode();
        this->rear = new linkNode();
        this->front->next = this->rear;
        this->rear->last = this->front;
    }
};
typedef struct deQueue *pDeQueue;
class LRUCache
{
public:
    pDeQueue dq;
    map<int, pLinkNode> hashTable;

public:
    LRUCache(int capacity)
    {
        dq = new deQueue(capacity);
        hashTable = map<int, pLinkNode>();
    }
    ~LRUCache()
    {
        pLinkNode temp = dq->front;
        while (temp)
        {
            pLinkNode temp1 = temp;
            temp = temp->next;
            delete(temp1);
        }
        delete(dq);
    }

    int get(int key)
    {
        map<int, pLinkNode>::iterator it = hashTable.find(key);
        if (it != hashTable.end())
        {
            movetorear(it->second);
            return it->second->value;
        }
        else {return -1;}
    }

    void put(int key, int value)
    {
        map<int, pLinkNode>::iterator it = hashTable.find(key);
        if (it != hashTable.end())
        {
            it->second->value = value;
            movetorear(it->second);
        }
        else
        {
            pLinkNode temp = new linkNode(key, value);
            
            addNode(temp);
            hashTable[key] = move(temp);

            if (hashTable.size() > dq->size)
            {
                pLinkNode temp1 = dq->front->next;
                hashTable.erase(temp1->key);
                
                dq->front->next = temp1->next;
                temp1->next->last = dq->front;
                
                delete(temp1);
            }
        }
    }

    void movetorear(pLinkNode node) {
        removeNode(node);
        addNode(node);
    }

    void removeNode(pLinkNode node) {
        node->last->next = node->next;
        node->next->last = node->last;
    }

    void addNode(pLinkNode node) {
        node->next = dq->rear;
        node->last = dq->rear->last;

        dq->rear->last->next = node;
        dq->rear->last = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

// int main(){
//     LRUCache* obj = new LRUCache(2);
//     obj->put(1,1);
//     cout << obj->dq->front->key << " " << obj->dq->rear->key << endl;

//     obj->put(2,2);
//     cout << obj->dq->front->key << " " << obj->dq->rear->key << endl;

//     int param_1 = obj->get(1);
//     cout << obj->dq->front->key << " " << obj->dq->rear->key << endl;
// }