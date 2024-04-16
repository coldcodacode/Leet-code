/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        quicksort(nums, 0, nums.size() - 1);
        // for (size_t i = 0; i < nums.size(); i++)
        // {
        //     cout << nums[i] << ' ';
        // }
        // cout <<endl;
        // vector<int> copy;
        // copy.push_back(nums[0]);
        // for (int i = 1; i < nums.size(); ++i) {
        //     if (nums[i] != copy.back())
        //         copy.push_back(nums[i]);
        // }
        // for (size_t i = 0; i < copy.size(); i++)
        // {
        //     cout << copy[i] << ' ';
        // }
        // cout <<endl;

        vector<int> item;
        int stake = nums.size() - 1;
        int low = 0;
        int high = stake - 1;

        while (stake > 1) {
            while (low < high) {
                if (nums[low] + nums[high] < -nums[stake]) low++;
                else if (nums[low] + nums[high] > -nums[stake]) high--;
                else {
                    item.push_back(nums[stake]);
                    item.push_back(nums[low]);
                    item.push_back(nums[high]);
                    res.push_back(item);
                    item.clear();
                    
                    int lowValue = nums[low];
                    int highValue = nums[high];
                    do {
                        low++;
                    } while (low < high && nums[low] == lowValue);
                    do {
                        high--;
                    } while (low < high && nums[high] == highValue);
                }
            }
            int stakeValue = nums[stake];
            do {
                stake--;
            } while (stake > 1 && nums[stake] == stakeValue);
            
            low = 0;
            high = stake - 1;
        }

        return res;
    }

    void quicksort(vector<int>& nums, int left, int right) {
        int left0 = left;
        int right0 = right;
        if (left >= right) return; 

        int pivot = nums[left];
        // int 
        while (left < right) {
            while (left < right && nums[right] >= pivot) right--;
            nums[left] = nums[right];
            while (left < right && nums[left] <= pivot) left++;
            nums[right] = nums[left];
        }
        nums[left] = pivot;

        // for (size_t i = 0; i < nums.size(); i++)
        // {
        //     cout << nums[i] << ' ';
        // }
        // cout <<endl;

        quicksort(nums, left0, left - 1);
        quicksort(nums, left + 1, right0);
    }
};

// int main() {
//     Solution s;
//     vector<int> input = {-1, 0, 1, 2, -1, -4};
//     vector<vector<int>> res = s.threeSum(input);

//     for (int i = 0; i < res.size(); i++) {
//         for (int j = 0; j < res[i].size(); ++j) {
//             cout << res[i][j] << " ";
//         }
//         cout << endl;
//     }
// }
// @lc code=end

