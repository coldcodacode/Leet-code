/*
 * @lc app=leetcode.cn id=907 lang=cpp
 *
 * [907] 子数组的最小值之和
 */

// @lc code=start
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    long long ans = 0;
    long long mod = 1e9 + 7;

    // nearly violent dp solution with time complication O(n^2)
    // int sumSubarrayMins(vector<int>& arr) {
    //     int n = arr.size();
    //     vector<int> dp(n+1, 0);
    //     for (int i = 0; i < n; i++) {
    //         int min = arr[i];
    //         dp[i] = dp[i] % 9 + 7;
    //         dp[i+1] = dp[i];
    //         for (int j = i; j >= 0; j--) {
    //             if (min > arr[j]) {
    //                 min = arr[j];
    //             }
    //             dp[i+1] += min;
    //         }
    //     }

    //     return dp[n];
    // }

    // using mono stack and dp 
    // dp[i] = b为所有以i结尾的子数组，min（b）的总和
    // 最终答案为 dp[0] + ... + dp[n-1]
    // dp[i] = dp[i-k] * arr[i]*k
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        stack<int> monoStack;
        vector<int> left(n);
        vector<int> dp(n+1, 0);
        for (int i = n-1; i >= 0; i--) {
            while (!monoStack.empty() && arr[i] < arr[monoStack.top()]) {
                left[monoStack.top()] = i;
                monoStack.pop();
            }
            monoStack.push(i);
        }
        while (!monoStack.empty()) {
            left[monoStack.top()] = -1;
            monoStack.pop(); 
        }

        for (int i = 0; i < n; i++) {
            int k = (i - left[i]);
            dp[i+1] = dp[i+1-k] + arr[i]*k;
        }

        for (auto i : dp) {
            ans = (ans + i) % mod;
        }

        return ans;
    }

    // using mono stack
//     void clearStack(stack<int>& s) {
//         while (!s.empty()) 
//         {
//             s.pop();
//         }
//     }

//     int sumSubarrayMins(vector<int>& arr) {
//         int n = arr.size();
//         stack<int> monoStack;
//         vector<int> left(n), right(n);
//         for (int i = 0; i < n; i++) {
//             while (!monoStack.empty() && arr[i] < arr[monoStack.top()]) {
//                 right[monoStack.top()] = i;
//                 monoStack.pop();
//             }
//             monoStack.push(i);
//         }
//         while (!monoStack.empty()) {
//             right[monoStack.top()] = n;
//             monoStack.pop(); 
//         }
//         clearStack(monoStack);
//         for (int i = n-1; i >= 0; i--) {
//             while (!monoStack.empty() && arr[i] < arr[monoStack.top()]) {
//                 left[monoStack.top()] = i;
//                 monoStack.pop();
//             }
//             monoStack.push(i);
//         }
//         while (!monoStack.empty()) {
//             left[monoStack.top()] = -1;
//             monoStack.pop(); 
//         }

//         for (int i = 0; i < n; i++) {
//             ans = (ans + (long long)arr[i] * (i - left[i]) * (right[i] - i)) % mod;
//             // ans %= mod;
//         }
//         return ans;
//     }
};



