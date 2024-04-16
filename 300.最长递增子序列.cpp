/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
/*dp[i][j] 前i个元素，子序列最右侧元素为j，此时的最长递增序列长度为dp[i][j]
dp[i][j] = max(dp[i-1][j-1] + 1, dp[i][j]) if j == nums[i]
         = max(dp[i-1][j], dp[i][j]) if j < nums[i]
         = max(dp[i-1][j], dp[i-1][nums[i]-1] + 1, dp[i][j]) if j > nums[i]

dp[0][j] = 1 求dp[n-1][max(nums)]*/
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <list>
using namespace std;

// 递归 复杂度2的n次方
class Solution1 {
public:
    int min;
    vector<int> nextBigger = vector<int>(10);
    vector<int> nextSmaller = vector<int>(10);
    void findNextBigger(vector<int>& nextBigger, vector<int>& nums, int size) {
        nextBigger.resize(size);
        stack<int> s;
        for (int i = size-1; i >= 0; i--) {
            while (!s.empty() && nums[i] > nums[s.top()]) {
                nextBigger[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        while (!s.empty()) {
            nextBigger[s.top()] = -1;
            s.pop();
        }
    }
    void findNextSmaller(vector<int>& nextSmaller, vector<int>& nums, int size) {
        nextSmaller.resize(size);
        stack<int> s;
        for (int i = size-1; i >= 0; i--) {
            while (!s.empty() && nums[i] < nums[s.top()]) {
                nextSmaller[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        while (!s.empty()) {
            nextSmaller[s.top()] = -1;
            s.pop();
        }
    }

    int recu(int max, int i, vector<int>& nums) {
        if (i  == -1) {
            return 0;
        }
        if (i == 0) {
            if (max < nums[i]) 
                return 0;
            else 
                return 1;
        }

        if (max == nums[i]) {
            return 1 + recu(max-1, nextSmaller[i], nums);
        } else if (max < nums[i]) {
            return recu(max, i-1, nums);
        } else if (max > nums[i]) {
            return std::max(recu(max, nextBigger[i], nums), 1 + recu(nums[i]-1, nextSmaller[i], nums));
        }

        return -1;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int max = *(max_element(nums.begin(), nums.end()));
        min = *(min_element(nums.begin(), nums.end()));
        cout << n << " " << max << " " << min << endl;

        findNextBigger(nextBigger, nums, n);
        findNextSmaller(nextSmaller, nums, n);
        // int* dp = new int[n];
        // dp[0] = 1;

        return recu(max, n-1, nums);
    }
};
// @lc code=end

// 动态规划，时间复杂度n方
/**首先，最直接的想法是dp[i]，为前i个数的最长递增子序列长度
 * 但是，这样使得dp[i+1]无法从dp[j]（j<=i）求出来。
 * 考虑到记录下dp[i]的最长子序列的最后一个元素，以尝试写出递推方程，无果。
 * 所以考虑赋予dp[i]新的意义。无法写出递推方程问题在于，
 * 对于dp[i+1]，不确定nums[i+1]是否在最长子序列中。
 * 如果加上一个条件，nums[i]必须选择，那么dp[i+1]就是可以写出递推方程的。
 * 此时，dp[i+1] = 1 + max(dp[j]) , nums[j] < nums[i+1], j<=i
 * 问题的解是max(dp[i]), i<=n-1*/
class Solution2 {
public:
    vector<int> dp;
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n);
        dp[0] = 1;
        for (int i = 1; i < n; ++i) {
            int max = 0;
            for (int j = i-1; j >= 0; --j) {
                if (nums[j] < nums[i]) {
                    max = std::max(max, dp[j]);
                }
            }
            dp[i] = 1 + max;
        }

        return *(max_element(dp.begin(), dp.end()));
    }
};

/**
 * @brief 贪心，nlogn
 * 期望子数列增长越慢越好
 * 
 */
class Solution {
public:
    vector<int> d;

    // 找到第一个比它小的位置
    int find(vector<int>& d, int i) {
        for (auto it = d.rbegin(); it != d.rend(); it++) {
            if (*it < i) {
                return d.rend() - it - 1;
            }
        }
        return -1;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        d.push_back(nums[0]);
        for (int i = 1; i < n; ++i) {
            if (nums[i] > d.back()) {
                d.push_back(nums[i]);
            } else {
                int ret = find(d, nums[i]);
                d[ret+1] = nums[i];
            }
        }
        return d.size();
    }
};
// @lc code=end


// int main () {
//     vector<int> nums = {-813,82,-728,-82,-432,887,-551,324,-315,306,-164,-499,-873,-613,932,177,61,52,1000,-710,372,-306,-584,-332,-500,407,399,-648,290,-866,222,562,993,-338,-590,303,-16,-134,226,-648,909,582,177,899,-343,55,629,248,333,1,-921,143,629,981,-435,681,844,349,613,457,797,695,485,15,710,-450,-775,961,-445,-905,466,942,995,-289,-397,434,-14,34,-903,314,862,-441,507,-966,525,624,-706,39,152,536,874,-364,747,-35,446,-608,-554,-411,987,-354,-700,-34,395,-977,544,-330,596,335,-612,28,586,228,-664,-841,-999,-100,-620,718,489,346,450,772,941,952,-560,58,999,-879,396,-101,897,-1000,-566,-296,-555,938,941,475,-260,-52,193,379,866,226,-611,-177,507,910,-594,-856,156,71,-946,-660,-716,-295,-927,148,620,201,706,570,-659,174,637,-293,736,-735,377,-687,-962,768,430,576,160,577,-329,175,51,699,-113,950,-364,383,5,748,-250,-644,-576,-227,603,832,-483,-237,235,893,-336,452,-526,372,-418,356,325,-180,134,-698};
//     Solution s;
//     cout << s.lengthOfLIS(nums) << endl;
// }