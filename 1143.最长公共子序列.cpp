/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
#include <string>
using namespace std;


// dp: 
//   dp[i][j] = max( if text1[i] == text2[j] 
//                      dp[i-1][j-1] + 1
//                   else 
//                      max(dp[i-1][j], dp[i][j-1])      
//                 )
class Solution {
public:
    
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();

        int dp[m][n];

        if (text1[0] == text2[0]) {
            dp[0][0] = 1;
        }else {
            dp[0][0] = 0;
        }
        for (int i = 1; i < m; ++i) {
            if (text1[i] == text2[0]) dp[i][0] = 1;
            else dp[i][0] = dp[i-1][0];
        }

        for (int j = 1; j < n; ++j) {
            if (text1[0] == text2[j]) dp[0][j] = 1;
            else dp[0][j] = dp[0][j-1];
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (text1[i] == text2[j]) dp[i][j] = dp[i-1][j-1] + 1;
                else {
                    dp[i][j] = (dp[i-1][j] > dp[i][j-1]) ? dp[i-1][j] : dp[i][j-1];
                }
            }
        }

        return dp[m-1][n-1];
    }
};
// @lc code=end

