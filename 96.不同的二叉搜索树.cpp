/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
#define MAX 20
class Solution {

public:
    // // recursion
    // int numTrees(int n) {
    //     if (n == 1) return 1;
    //     if (n == 2) return 2;
    //     int num = 0;
    //     for (int i = 2; i <= n - 1; i++){
    //         num += (numTrees(i - 1) * numTrees(n - i));
    //     }
    //     num += 2 * numTrees(n-1);
    //     return num;
    // }
    
    // dp
    int dp[MAX] = {1};
    void init(){
        dp[1] = 1;
        for (int i = 2; i < MAX; i++){
            for(int j = 1; j <= i; ++j){
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }
    }
    int numTrees(int n){
        init();
        return dp[n];
    }
};
// @lc code=end

