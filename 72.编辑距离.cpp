/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1, if word1[i] != word2[j]
    // 如果末尾字符不同，只有三种方式让他们相同，分别是替换、删除（相当于在t末尾插入）、在s末尾插入
    // dp[i][j] = dp[i-1][j-1], if word1[i] == word2[j]
    int minDistance(string word1, string word2)
    {
        int s_size = word1.size();
        int t_size = word2.size();

        vector<vector<int>> dp(s_size + 1, vector<int>(t_size + 1, 0));
        for (int i = 1; i <= s_size; i++)
        {
            dp[i][0] = i;
        }
        for (int i = 1; i <= t_size; i++)
        {
            dp[0][i] = i;
        }

        for (int i = 1; i <= s_size; i++)
        {
            for (int j = 1; j <= t_size; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                }
            }
        }
        return dp[s_size][t_size];
    }
};
// @lc code=end
