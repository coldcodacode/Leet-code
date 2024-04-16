/*
 * @lc app=leetcode.cn id=410 lang=cpp
 *
 * [410] 分割数组的最大值
 */

// @lc code=start
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
// 前缀和+二分
class Solution {
public:
    bool check(int mid, vector<int>& nums, int k){
        int cnt = 1;
        int sum = 0;
        for (auto n : nums){
            if (sum + n <= mid){
                sum += n;
            }else{
                sum = n;
                cnt++;
            }
        }
        return cnt <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int l = 0, r = 0;
        for (auto n : nums){
            if (l < n) l = n;
            r += n; 
        }
        int mid;
        while(l < r){
            mid = (l + r) / 2; // 替换为mid = l + (r - l) / 2更好，因为考虑数值溢出
            if (check(mid, nums, k)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return r;
    }
};

// dp
class Solution2{
public:
    int splitArray(vector<int>& nums, int k){
        // 最优子结构（求最值问题）、重叠子问题
        // 定义问题dp[i][j] 前 i 个元素，分成 j 组，min（max各组和）
        // dp[i][j] = min(dp[i][j], max(dp[k][j-1], sum[i] - sum[k])), k from j-1 to i-1
        int n = nums.size();
        int sum[n + 5];
        int dp[n + 5][55];
        memset(sum, 0x0, sizeof(sum));
        memset(dp, 0x3f, sizeof dp);
        for (int i = 1; i <= n; i++){
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= min(k, i); ++j){
                if (j == 1){
                    dp[i][j] = sum[i];
                }else{
                    for(int k = j-1; k <= i-1; k++){
                        dp[i][j] = min(dp[i][j], max(dp[k][j-1], sum[i] - sum[k]));
                    }
                }
            }
        }
        return dp[n][k];
    }
};
// @lc code=end

