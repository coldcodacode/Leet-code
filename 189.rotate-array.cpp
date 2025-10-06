/*
 * @lc app=leetcode.cn id=189 lang=cpp
 * @lcpr version=30204
 *
 * [189] 轮转数组
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
class Solution
{
private:
    int size;
    int k;
    int findPos(int pos) {
        return (pos + k) % size; 
    }
    void init(int size, int k) {
        size = size;
        k = k;
    } 
    // 0, k - remainder, 2(k - remainder) % k, 
    vector<int> calClosure(int k, int remainder) {
        vector<int> res;
        int start = 0;
        int cur = start;
        do {
            cur = (cur + k - remainder) % k; 
        } while(cur != start);
        res.push_back(start);
        return res;
    }
public:
    void rotate(vector<int> &nums, int k)
    {
        init(nums.size(), k);
        int remainder = size % k;
        vector<int> closure = calClosure(k, remainder);
        for (int i = 0; i < closure.size(); i++) {
            int curIdx = closure[i];
            int curVal = nums[curIdx];
            int nextIdx;
            int nextVal;
            int originIdx = curIdx;
            do {
                nextIdx = findPos(curIdx);
                nextVal = nums[nextIdx];
                nums[nextIdx] = curVal; 
                curIdx = nextIdx;
                curVal = nextVal;
            } while(originIdx != curIdx);
        }
    }
};
// @lc code=end

/*
// @lcpr case=start
// [1,2,3,4,5,6,7]\n3\n
// @lcpr case=end

// @lcpr case=start
// [-1,-100,3,99]\n2\n
// @lcpr case=end

 */
