/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:

    // solve using recursion
    /*
    int largestArea = 0;
    size_t findMin(vector<int>& heights, size_t left, size_t right) {
        size_t ret = left;
        for (size_t i = left + 1; i <= right; i++ ) {
            if (heights[i] < heights[ret]) ret = i;
        }
        return ret;
    }

    void areaWithLongestWidth(vector<int>& heights, size_t left, size_t right) {
        size_t indexMin = findMin(heights, left, right);
        if (largestArea < (right - left + 1) * heights[indexMin]) {
            largestArea = (right - left + 1) * heights[indexMin];
        }
        if (indexMin != left) {
            areaWithLongestWidth(heights, left, indexMin - 1);
        }
        if (indexMin != right) {
            areaWithLongestWidth(heights, indexMin + 1, right);
        }
    }

    int largestRectangleArea(vector<int>& heights) {
        size_t length = heights.size();
        size_t left = 0;
        size_t right  = length - 1;
        
        areaWithLongestWidth(heights, left, right);

        return largestArea;
    }
    */

    // solve using monotonous stack

    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        vector<int> v(heights.size(), -1);

        for (int i = 0; i < heights.size(); ++i) {
            while (!s.empty() && heights[s.top()] > heights[i]) {
                v[s.top()] += i;
                s.pop();
            }
            if (s.empty()) {
                v[i] -= -1;
            }else {
                v[i] -= s.top();
            }
            s.push(i);
        }

        while (!s.empty()) {
            v[s.top()] += heights.size();
            s.pop();
        }

        for (int i = 0; i < heights.size(); ++i) {
            v[i] *= heights[i];
        }

        int res = 0;
        for (int i = 0; i < heights.size(); ++i) {
            res = v[i] > res ? v[i] : res;
        }
        return res;
    }
    
};
// @lc code=end

