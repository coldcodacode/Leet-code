/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return vector<int>(0);
        int n = matrix[0].size();
        int flag = 0;
        vector<int> res(m*n);
        int counter = 0;
        int i = 0, j = 0;
        int x = m;
        int y = n;
        int p = 0;
        int q = 1;
        while (counter < m*n) {
            if (flag == 0) {
                for ( ; j < y; j++) {
                    res[counter++] = matrix[i][j];
                }
                j--;
                i++;
                y--;
                ++flag;
                flag = flag % 4;
            }else if (flag == 1) {
                for ( ; i < x; i++) {
                    res[counter++] = matrix[i][j];
                }
                i--;
                j--;
                x--;
                ++flag;
                flag = flag % 4;
            }else if (flag == 2) {
                for ( ; j >= p; j--) {
                    res[counter++] = matrix[i][j];
                }
                j++;
                i--;
                p++;
                ++flag;
                flag = flag % 4;
            }else if (flag == 3) {
                for ( ; i >= q; i--) {
                    res[counter++] = matrix[i][j];
                } 
                i++;
                j++;
                q++;
                ++flag;
                flag = flag % 4;
            }
        }
        return res;
    }
};
// @lc code=end

