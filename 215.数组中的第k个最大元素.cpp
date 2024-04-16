/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    // solve using heap

    /*
    void mySwap(vector<int>& nums, size_t a, size_t b){
        int temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
    void modifyHeap(vector<int>& nums, size_t root, size_t size){
        size_t left = root * 2 + 1;
        size_t right = root * 2 + 2;
        if (size - 1 < left){
            return;
        }
        if (size - 1 >= right){
            if (nums[root] > nums[left] && nums[root] > nums[right]){
                return;
            }else if (nums[left] > nums[right]){
                mySwap(nums, left, root);
                modifyHeap(nums, left, size);
            }else {
                mySwap(nums, right, root);
                modifyHeap(nums, right, size);
            }
        }else {
            if (nums[root] <= nums[left]){
                mySwap(nums, root, left);
            }
            return;
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        size_t size_nums = nums.size();
         
        // from the bottom to top adjust the heap
        for (size_t i = (size_nums - 2) / 2; i >= 0; --i){
            modifyHeap(nums, i, size_nums);
        }

        // delete the top k times
        while(k-- != 1){
            nums[0] = -10001;
            modifyHeap(nums, 0, size_nums);
        }
        
        return nums[0];
    }
    */

    // solve using quicksorting

    int quicksort(vector<int>& nums, int k, int left, int right) {
        int right0 = right;
        int left0 = left;

        int piquet = nums[left];
        while(left < right) {
            while (right > left && nums[right] > piquet) right--;
            nums[left] = nums[right];
            while(right > left && nums[left] <= piquet) left++;
            nums[right] = nums[left];
        }
        nums[left] = piquet;

        if (right0 + 1 - k == left) {
            return left;
        }else if (right0 + 1 - k < left) {
            return quicksort(nums, k - right0 + left - 1, left0, left - 1);
        }else {
            return quicksort(nums, k, left + 1, right0);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        int index = quicksort(nums, k, 0, nums.size() - 1);
        return nums[index];
    }

};
// @lc code=end

