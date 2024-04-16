/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        map<char, int> lastAppearance;

        for (size_t i = 0; i < s.size(); i++)
        {
            lastAppearance[s[i]] = i;
        }

        int start = 0;
        int bound = lastAppearance[s[start]];
        int cursor = start;

        while (start != s.size()) {
            while (bound != cursor) {
                if (lastAppearance[s[cursor]] > bound) {
                    bound = lastAppearance[s[cursor]];
                }
                cursor++;
            }
            res.push_back(bound - start + 1);
            start = bound + 1;
            bound = lastAppearance[s[start]];
            cursor =  start;
        }

        return res;
    }
};
// @lc code=end

