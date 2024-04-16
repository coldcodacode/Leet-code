/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
/*
给你一个字符串 s，找到 s 中最长的回文子串。

如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。

 

示例 1：

输入：s = "babad"
输出："bab"
解释："aba" 同样是符合题意的答案。
示例 2：

输入：s = "cbbd"
输出："bb"
 

提示：

1 <= s.length <= 1000
s 仅由数字和英文字母组成*/
// @lc code=start
#include <string>
using namespace std;
#include <vector>
#include <algorithm>

/**
 * @brief 
 * if substr[i, j] 是一个回文串 <=>
 *      sub[i+1][j-1] 是一个回文串 && s[i] == s[j]
 */
class Solution {
public:
    string longestPalindrome(string s) {
        string ans = "";
        int size = s.size();
        int max_i = 0; // left pointer to max substr
        int max_j = 0; // right pointer to max substr
        int max = 0; // length of max substr
        vector<vector<int>> dp(size, vector<int>(size, 1));
        for (int i = size - 1; i > -1; i--) {
            for (int j = size - 1; j > i; j--) {
                dp[i][j] = dp[i+1][j-1] ? 
                    (s[i] == s[j] ? 
                        j-i+1 : 
                        0) : 
                    0;
                if (dp[i][j] > max) {
                    max = dp[i][j];
                    max_i = i;
                    max_j = j;

                }
            }
        }
        ans = s.substr(max_i, max_j - max_i + 1);
        return ans;
    }
};
// @lc code=end

