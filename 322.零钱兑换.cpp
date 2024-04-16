/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    // dp[i][j] = min (dp[i-1][j], dp[i][j-coins[i]] + 1)
    // dp[0][j] = -1;
    // return dp[n][amount]
    int coinChange(vector<int>& coins, int amount) {
        int* dp = new int[amount+1]; 
        int n = coins.size();
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            dp[i] = -1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                int index = j - coins[i-1];
                if (index < 0) continue;
                int value = dp[index];
                if (value == -1) continue;
                if (dp[j] == -1) dp[j] = value + 1;
                dp[j] = min (dp[j], value + 1);
            }
        }

        return dp[amount];
    }
};

// int main () {
//     Solution* s = new Solution();
//     vector<int> coins = {1, 2, 5};
//     int amount = 11;
//     cout << s->coinChange(coins, amount);
// }
// @lc code=end

