/*
 * @lc app=leetcode.cn id=1019 lang=cpp
 *
 * [1019] 链表中的下一个更大节点
 */
#include <vector>
#include <stack>
using namespace std;
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };
struct node{
    int index;
    int val;
};
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode *p = head;
        int count = 0;
        while(p){
            count++;
            p = p->next;
        }
        struct node n;
        stack<struct node> s;
        int index = 0;
        bool not_push = true;
        vector<int> ret(count);
        struct node temp;
        if (!head){
            return ret;
        }
        n.index = index++;
        n.val = head->val;
        s.push(n);
        head = head->next;
        while(head!=NULL){
            not_push = true;
            n.index = index++;
            n.val = head->val;
            while(!s.empty()){
                temp = s.top();
                if (temp.val >= head->val){
                    s.push(n);
                    not_push = false;
                    break;
                }else{
                    s.pop();
                    ret[temp.index] = head->val;
                }
            }
            if (not_push){
                s.push(n);
            }
            head = head->next;
        }
        while (!s.empty()){
            temp = s.top();
            ret[temp.index] = 0;
            s.pop();
        }
        return ret;
    }
};
// @lc code=end

