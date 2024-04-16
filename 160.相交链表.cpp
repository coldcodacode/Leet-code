/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <unordered_set>
using namespace std;
class Solution {
public:
    // 使用哈希表
    // unordered_set<ListNode*> hashset;
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //     ListNode* node = headA;
    //     while (node) {
    //         hashset.insert(node);
    //         node = node->next;
    //     }
    //     node = headB;
    //     while (node) {
    //         if (hashset.find(node) != hashset.end()) {
    //             return node;
    //         }
    //         node = node->next;
    //     }
    //     return node;
    // }

    // 双指针
    // 他朝若是同淋雪， 此生也算共白头
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* node1 = headA;
        ListNode* node2 = headB;

        while (node1 != node2) {
            node1 = node1 ? node1->next : headB;
            node2 = node2 ? node2->next : headA;
        }

        return node1;
    }
};
// @lc code=end

