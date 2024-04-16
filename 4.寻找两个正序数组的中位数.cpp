/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int getMedian(vector<int>& nums, int l, int target) {
        if (target > nums.size() - l) return nums.size() - 1;
        else return l + target - 1;
    }
    int partion(vector<int>& nums1, vector<int>& nums2, int l1, int l2, int target) {
        if (l1 >= nums1.size()) return nums2[l2 + target - 1];
        if (l2 >= nums2.size()) return nums1[l1 + target - 1];

        if (target == 1) return min(nums1[l1] ,nums2[l2]);

        int mid1 = getMedian(nums1, l1, target/2);
        int mid2 = getMedian(nums2, l2, target/2);
        // cout << mid1 << " " << mid2 << endl;
        if (nums1[mid1] > nums2[mid2])  {
            return partion(nums1, nums2, l1, mid2 + 1, target - (mid2 + 1 - l2));
        } else {
            return partion(nums1, nums2, mid1 + 1, l2, target - (mid1 + 1 - l1));
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();

        int target1 = ((size1 + size2) + 1) / 2;
        int target2 = ((size1 + size2) + 2) / 2;

        // cout << partion(nums1, nums2, 0, 0, target1);
        // cout << partion(nums1, nums2, 0, 0, target2);
        
        return ((double)partion(nums1, nums2, 0, 0, target1) + 
                partion(nums1, nums2, 0, 0, target2)) / 2;

    }
};
// @lc code=end

