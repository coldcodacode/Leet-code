/*
 * @lc app=leetcode.cn id=2351 lang=cpp
 *
 * [2351] 第一个出现两次的字母
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<char> us;
        for (auto ch : s) {
            if (us.find(ch) != us.end())
                return ch;
            us.insert(ch);
        }
        return ' ';
    }
};
// @lc code=end

