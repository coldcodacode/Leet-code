/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */
#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
// recursion: re[n] = max(re[n-1] + re[n-2])
// time limit exceed: calculate repeatly 

//  dp: dp[n] = dp[n-1] + dp[n-2] from bottom to top
class Solution {
public:
    // recursion
    // int recursion(int n) {
    //     if (n == 2 || n == 1) return n;

    //     return recursion(n - 1) + recursion(n - 2);
    // }
    // int climbStairs(int n) {
    //     return recursion(n);
    // }

    // dp
    int dp[50] = {0};
    
    // int[] dp = new int[](45, 0);
    int iter(int n) {
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i){
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
    int climbStairs(int n ){
        // int* test = new int(10,0);
        return iter(n) ;
    }

    // 输出所有方案
    // 递归法，本质还是一个回溯，再本质就是一个二叉树的后序遍历
    vector<vector<int>> res;
    vector<int> path;

    void dfs(int n) {
        if (n == 0) {
            res.push_back(path);
            // path.clear();
            return;
        }
        if (n == 1) {
            path.push_back(1);
            res.push_back(path);
            path.pop_back();
            return;
        }

        path.push_back(1);
        dfs(n-1);
        path.pop_back();

        path.push_back(2);
        dfs(n-2);
        path.pop_back();

        return;
    }
    
    void print() {
        for (int i = 0; i < res.size(); i++) {
            for (auto it : res[i]) {
                cout << it << " ";
            }
            cout << endl;
        }
    }
};
// @lc code=end

int main (){
    Solution s;
    s.dfs(4);
    s.print();
}
