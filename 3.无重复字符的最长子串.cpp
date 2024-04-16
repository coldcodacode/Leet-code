/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start

#include <string>
#include <set>
#include <iostream>
using namespace std;
class Solution
{
public:
    static int lengthOfLongestSubstring(string s)
    {
        int max = 0;
        int left = 0, right = 0;
        set<char> set;
        while (right != s.length())
        {
            while (right != s.length() && set.find(s.at(right)) == set.end())
            {
                set.insert(s.at(right));
                right++;
            }
            max = max > (right - left) ? max : (right - left);
            cout << max <<endl;
            if (right != s.length()){
                while (s.at(left) != s.at(right)) {
                    set.erase(set.find(s.at(left)));
                    left++;
                }
                left++;
                right++;
            }
        }
        return max;
    }
};
// @lc code=end
