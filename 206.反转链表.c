/*
 * @lc app=leetcode.cn id=206 lang=c
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


#include <stdio.h>
#include <stdlib.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

struct ListNode *reverseList(struct ListNode *head);
struct ListNode *AppendNode(struct ListNode *head);
void DisplayNode(struct ListNode *head);
void DeleteMemory(struct ListNode *head);
// int main()
// {
//     char c;
//     struct ListNode *head = NULL;
//     scanf("%c",&c);
//     while (c != ']')
//     {
//         head = AppendNode(head);
//         scanf("%c",&c);
//     }
//     head = reverseList(head);
//     DisplayNode(head);
//     DeleteMemory(head);
//     system("pause");
// }
struct ListNode *reverseList(struct ListNode *head){
    struct ListNode *pr = head,*temp = NULL;
    if (head == NULL)
    {
        return head;
    }
    else
    {
        if (pr->next == NULL)
        {
            return head;
        }
        else
        {
            while (pr->next != NULL)
            {
                temp = pr;
                pr = pr->next;
            }
            temp->next = NULL;
            pr->next = reverseList(head);
            head = pr;
            return head;
        }
    }
}
struct ListNode *AppendNode(struct ListNode *head){
    int data;
    struct ListNode *p = NULL,*pr = head;
    p = (struct ListNode *)malloc(sizeof(struct ListNode));
    if (p == NULL)
    {
        printf("No enough memeory to allocate!\n");
        exit(0);
    }
    if (scanf("%d",&data) == 1)
    {
        p->val = data;
        p->next = NULL;
        if (head == NULL)
        {
            head = p;
        }
        else
        {
            while (pr->next != NULL)
            {
                pr = pr->next;
            }
            pr->next = p;
        }
        return head;
    }
    else
    {
        free(p);
        return head;
    }
}
void DisplayNode(struct ListNode *head)
{
    struct ListNode *pr = head;
    printf("[");
    if (head != NULL)
    {
        while (pr->next != NULL)
        {
            printf("%d,",pr->val);
            pr = pr->next;
        }
        printf("%d",pr->val);
        printf("]");
    }
    else
    {
        printf("]");
    }
}
void DeleteMemory(struct ListNode *head)
{
    struct ListNode *pr = head,*p = NULL;
    while (pr != NULL)
    {
        p = pr;
        pr = pr->next;
        free(p);
    }
}
// @lc code=end

