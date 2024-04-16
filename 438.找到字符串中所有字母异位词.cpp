/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
#include <vector>
#include <string>
#include <array>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        array<int, 26> arr;
        // cout << sizeof arr;
        memset(&arr, 0, sizeof arr);
        for (char c : p) {
            arr[c - 'a']++;
        }

        int p_size = p.size();
        vector <int> ans;
        int n = s.size();
        int l = 0, r = 0;
        for (; r < n; r++) {
            arr[s[r] - 'a']--;
            
            while (arr[s[r] - 'a'] < 0) {
                arr[s[l] - 'a']++;
                l++;
            }

            if (arr[s[r] - 'a'] == 0) {
                if (r - l + 1 == p_size) {
                    ans.push_back(l);
                    arr[s[l] - 'a']++;
                    l++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

