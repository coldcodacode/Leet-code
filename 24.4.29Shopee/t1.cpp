#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    /**
     * Note: 类名、方法名、参数名已经指定，请勿修改
     *
     * 
     * 根据价格列表和当前点券数，计算出能买到的最多英雄
     * @param costs int整型 vector 英雄点券价格列表
     * @param coins int整型  拥有的点券
     * @return int整型vector
     */
    // dp[i][j] = max(dp[i-1][j], d[i-1][j-costs[i]] + 1)
    vector<int> solution(vector<int>& costs, int coins) {
        // write code here
        // cout << 't' << endl;
        int n = costs.size();
        // cout << n << endl;
        vector<int> dp(coins+1, 0);
        vector<vector<bool>> helper(n, vector<bool>(coins+1, false));

        for (int i = 1; i <= n; i++) {
            for (int j = coins; j >= costs[i-1]; j--) {
                if (dp[j] < dp[j-costs[i-1]] + 1) {
                    dp[j] = dp[j-costs[i-1]] + 1;
                    helper[i-1][j] = true;
                }
                // dp[j] = max(dp[j], dp[j-costs[i]] + 1);
            }
            // cout << 't' << endl;
        }

        // vector<int> tmp(n+1, 0);
        // cout << dp[coins];
        vector<int> ans(dp[coins]);
        int m = ans.size();
        int j = coins;
        for (int i = n; i >= 1; i--) {
            if (helper[i-1][j]) {
                // tmp[i] = 1;
                ans[--m] = costs[i-1];
                j = j - costs[i-1];
            }
        }
        return ans;

    }
};


int main() {
    Solution s;
    vector<int> a({2,1,3,4,5});
    int coins = 10;
    vector<int> ans = s.solution(a, coins);
    for (auto i : ans) {
        cout << i << ' ';
    }
}