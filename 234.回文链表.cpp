/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */

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
#include <iostream>
using namespace std;
class Solution {
public:
    // 头插法
    // bool isPalindrome(ListNode* head) {
    
    //     ListNode* head1 = new ListNode();
    //     ListNode* node = head;
    //     while (node) {
    //         ListNode* new_node = new ListNode(node->val);
    //         new_node->next = head1->next;
    //         head1->next = new_node;
    //         node = node->next;
    //     }

    //     while (head && head1->next) {
    //         if (head->val != head1->next->val) {
    //             return false;
    //         }
    //         head = head->next;
    //         head1->next = head1->next->next;
    //     }

    //     return true;
    // }

    // 快慢指针
    bool isPalindrome(ListNode* head) {
        
    }
};
// @lc code=end

