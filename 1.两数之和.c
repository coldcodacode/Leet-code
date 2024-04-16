/*
 * @lc app=leetcode.cn id=1 lang=c
 *
 * [1] 两数之和
 */

// @lc code=start
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// brute solution O(n^2)
/*
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int *ans = (int *)malloc(2 * sizeof(int));
    for (int i = 0; i < numsSize - 1; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[j] == target - nums[i])
            {
                ans[0] = i;
                ans[1] = j;
                *returnSize = 2;
                return ans;
            }
        }
    }
    return ans;
}
*/

/*
// sort + two pointers O(n*logn) + O(n) 有個問題是數組標號改變導致返回錯誤
void Quicksort(int i, int j, int *nums);
int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int *ans = (int *)malloc(2 * sizeof(int));
    int *copy = ()
    Quicksort(0, numsSize - 1, nums);
    int l = 0, r = numsSize - 1;
    while (l < r)
    {
        if (nums[l] + nums[r] < target)
            l++;
        if (nums[l] + nums[r] > target)
            r--;
        if (nums[l] + nums[r] == target)
        {
            ans[0] = l;
            ans[1] = r;
            *returnSize = 2;
            return ans;
        }
    }
    return ans;
}
void Quicksort(int i, int j, int *nums)
{ //对标号从i到j快排
    int pivot = nums[i];
    if (i < j) //递归条件
    {
        int l = i;
        int r = j;
        while (l < r)
        {
            for (; nums[l] <= pivot; l++)
                ;
            for (; nums[r] > pivot; r--)
                ;
            if (l < r)
            {
                int temp = nums[l];
                nums[l] = nums[r];
                nums[r] = temp;
                l++;
                r--;
            }
        }
        if (l != i && r != j)
        {
            Quicksort(i, r, nums);
            Quicksort(l, j, nums);
        }
        else if (l == i)
            Quicksort(l + 1, j, nums);
        else if (r == j){
            int temp = nums[j];
            nums[j] = nums[i];
            nums[i] = temp;
            Quicksort(i, r - 1, nums);
        }
    }
}
*/

// hash
struct node
{
    int index;
    int val;
    struct node *next;
};
struct hash
{
    struct node *next;
};
void initial(struct hash *HashTable, int hashsize);
int find(int aim, struct hash *HashTable, int hashsize);
void insert(int num, int numind, int hashsize, struct hash *HashTable);
int *twoSum(int *nums, int numsSize, int target, int *returnSize);

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int *ans = (int *)malloc(2 * sizeof(int));
    int hashsize = 1343;
    struct hash *HashTable = (struct hash *)malloc(sizeof(struct hash) * hashsize);
    initial(HashTable, hashsize);
    for (int i = 0; i < numsSize; i++)
    {
        int fin = find(target - nums[i], HashTable, hashsize);
        if (fin != -1)
        {
            ans[0] = i;
            ans[1] = fin;
            *returnSize = 2;
            return ans;
        }
        else
        {
            fin = find(nums[i], HashTable, hashsize);
            if (fin == -1)
            {
                insert(nums[i], i, hashsize, HashTable);
            }
        }
    }
    return ans;
}
void initial(struct hash *HashTable, int hashsize)
{
    struct hash *temp = HashTable;
    for (int i = 0; i < hashsize; i++)
    {
        (temp + i)->next = NULL;
    }
}
// hash函数为 hash(aim) = aim % target
int find(int aim, struct hash *HashTable, int hashsize)
{
     int h;
    h = aim % hashsize;
    if (h < 0) h = -h;
    struct node *temp = (HashTable + h)->next;
    while (temp != NULL)
    {
        if (temp->val == aim)
        {
            return temp->index;
        }
        else
        {
            temp = temp->next;
        }
    }
    return -1;
}
void insert(int num, int numind, int hashsize, struct hash *HashTable)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->index = numind;
    temp->val = num;
    temp->next = NULL;
     int h;
    h = num % hashsize;
    if (h < 0) h = -h;
    struct node *cur = (HashTable + h)->next;
    (HashTable + h)->next = temp;
    temp->next = cur;
}
int main()
{
    int nums[4] = {0,4,3,0};
    int ret = 0;
    int *answer = twoSum(nums, 4, 0, &ret);
    printf("%d\n",answer[0]);
    printf("%d\n",answer[1]);
}
// @lc code=end

