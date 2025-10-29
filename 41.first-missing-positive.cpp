/*
 * @lc app=leetcode.cn id=41 lang=cpp
 * @lcpr version=30204
 *
 * [41] 缺失的第一个正数
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    /*
        通过hashTable O(n)时间和空间复杂度
    */ 
    // int firstMissingPositive(vector<int>& nums) {
    //     int len = nums.size();
    //     vector<bool> hashTable(len, false);
    //     for (auto i : nums) {
    //         if (i <= 0 || i > len) continue;
    //         hashTable[i-1] = true;
    //     }

    //     for (int i = 0; i < len; i++) {
    //         if (hashTable[i] == false) return i+1;
    //     }
    //     return len+1;
    // }

    int firstMissingPositive(vector<int>& nums) {
        int len = nums.size();
        int tmp = 0;
        int existTag = 0;

        int res = INT_MIN;
        for (auto i : nums) {
            if (i > len) continue;
            res = max(res, i);
        }
        res += 1;

        for (int i = 0; i < len; i++) {
            if (nums[i] <= 0) {
                nums[i] = INT_MAX;
            }
        }
        
        for (int i = 0; i < len; i++) {
            if (nums[i] == existTag) {
                continue;
            }
            int nextIdx = nums[i] == -2147483648 ? -1 : nums[i]-1;
            if (nextIdx < 0 || nextIdx >= len) {
                continue;
            } else {
                do {
                    tmp = nums[nextIdx];
                    nums[nextIdx] = existTag;
                    nextIdx = tmp == -2147483648? -1 : tmp-1;
                } while (nextIdx >= 0 && nextIdx < len && nums[nextIdx] != existTag);
            }
        }
        
        for (int i = 0; i < len; i++) {
            if (nums[i] != existTag) {
                res = i + 1;
                break;
            }
        }

        return res;
    }
};

// int main() {
//     Solution s;
//     vector<int> test_v{2147483647,2147483646,2147483645,3,2,1,-1,0,-2147483648};
//     cout << s.firstMissingPositive(test_v) << endl;
// }
// @lc code=end



/*
// @lcpr case=start
// [1,2,0]\n
// @lcpr case=end

// @lcpr case=start
// [3,4,-1,1]\n
// @lcpr case=end

// @lcpr case=start
// [7,8,9,11,12]\n
// @lcpr case=end

 */

