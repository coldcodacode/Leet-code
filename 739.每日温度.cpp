/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ret(temperatures.size(), 0);
        stack<int> s;
        // int counter = 0;

        s.push(0);
        for (size_t i = 1; i < temperatures.size(); i++)
        {
            while (!s.empty() && temperatures[s.top()] < temperatures[i]) {
                ret[s.top()] = i - s.top();
                s.pop();
            }
            // counter = 0;
            // counter = 1;
            s.push(i);
        }
        
        // while(!s.empty()){
        //     ret[s.top()] = 0;
        //     s.pop();
        // }

        return ret;
    }
};
// @lc code=end

