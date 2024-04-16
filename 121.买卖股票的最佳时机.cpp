/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start

#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int in = 0;
        int out = 0;

        int i = 1;
        while (i != prices.size()) {
            if (prices[in] > prices[i]) {
                in = i;
                out = i;
            }
            if (prices[out] < prices[i]) {
                out = i;

                maxProfit = maxProfit > prices[out] - prices[in] ? maxProfit : prices[out] - prices[in];
            }
            i++;
        }
        
        return maxProfit;
    }
};
// @lc code=end

