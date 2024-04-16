/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    // dp[i] = (k = length of word from dictionary matching the rear of s)
    //      dp[i-k1] | dp[i-k2] | ... | dp[i-km] 

    bool match(string s, string t) {
        int sSize = s.size();
        int tSize = t.size();

        if (sSize < tSize) return false;
        for (auto it_t = t.crbegin(), it_s = s.crbegin();
             it_t != t.crend(); it_t++, it_s++) {
            if (*it_s != *it_t) return false;
        }
        return true;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        bool dp[301] = {false};
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (auto it : wordDict) {
                if (match(s.substr(0, i), it)) {
                    dp[i] = dp[i - it.size()] || dp[i];
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end

