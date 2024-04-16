/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:

    string minWindow(string s, string t) {
        unordered_map<char, int> hashMap_s, hashMap_t;
        for (char c : t) {
            hashMap_t[c]++;
        }
        size_t left = 0, right = 0;
        int valid = 0;
        int start = 0, len = INT32_MAX;
        while (right < s.size()) {
            char c = s[right];
            right++;
            if (hashMap_t.count(c)) {
                hashMap_t[c]--;
                if (hashMap_t[c] == 0) {
                    valid++;
                }
            }

            while (valid == hashMap_t.size()) {
                if (len > right-left) {
                    start = left;
                    len = right - left;
                }
                char d = s[left];
                left++;
                if (hashMap_t.count(d)) {
                    hashMap_t[d]++;
                    if (hashMap_t[d] > 0) {
                        valid--;
                    }
                }
            }
        }
        if (len  == INT32_MAX) return "";
        return s.substr(start, len);
    }
};
// @lc code=end

