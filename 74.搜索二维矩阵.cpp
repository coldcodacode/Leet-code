/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    int helper(vector<int> &matrix, int left, int right, int target)
    {
        while (left <= right)
        {
            if (matrix.at(((left + right) / 2)) == target)
            {
                return -2;
            }
            else if (matrix.at(((left + right) / 2)) < target)
            {
                left = (left + right) / 2 + 1;
            }
            else
            {
                right = (left + right) / 2 - 1;
            }
        }
        return left - 1; // left is the position to insert
    }
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix.at(0).size();
        vector<int> temp;
        for (int i = 0; i < m; ++i)
        {
            temp.push_back(matrix.at(i).at(0));
        }
        int res = helper(temp, 0, m - 1, target);
        if (res == -2)
        {
            cout << "res = -1" << endl;
            return true;
        }else if(res == -1){
            return false;
        }
        else {
            cout << "res= " << res << endl;
            int res1 = helper(matrix.at(res), 0, n - 1, target);
            if (res1 == -2)
            {
                cout << "res1= -1" << endl;
                return true;
            }
            else
            {
                cout << "res1= " << res1 << endl;
                return false;
            }
        }
    }
};
// @lc code=end
