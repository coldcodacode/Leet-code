/*
 * @lc app=leetcode.cn id=628 lang=cpp
 *
 * [628] 三个数的最大乘积
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    void quicksort(vector<int>& nums, int l, int r) {
        if (r <= l) return;
        int l0 = l;
        int r0 = r;
        int pivot = nums[l];
        while (l < r) {
            while (l < r && nums[r] > pivot) r--;
            nums[l] = nums[r];
            while (l < r && nums[l] <= pivot) l++;
            nums[r] = nums[l];
        }
        nums[l] = pivot;

        quicksort(nums, l0, l-1);
        quicksort(nums, l+1, r0);
    }
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        quicksort(nums, 0, n-1);
        for (auto it : nums) {
            cout << it << ' ';
        }

        if (nums[0] >= 0 || nums[n-1] <= 0) return nums[n-3]*nums[n-2]*nums[n-1];
        else if (nums[1] >= 0) return nums[n-3]*nums[n-2]*nums[n-1];
        else return max(nums[n-3]*nums[n-2]*nums[n-1], nums[0]*nums[1]*nums[n-1]);
    }
};

// int main () {
//     Solution s;
//     vector<int> v;
//     v.push_back(9);
//     v.push_back(-9);
//     v.push_back(89);
//     v.push_back(-79);
//     s.maximumProduct(v);
// }
// @lc code=end

