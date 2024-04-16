/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
#include <vector>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
// n层n叉树剪枝
class Solution {
private:
    vector<vector<int>> v;
public:
    bool check(int a[], int k, int size){ // 检查k是否能插入, 数组当前大小size
        for(int i = 1; i <= size; ++i){
            if (k == a[i] || k == a[i] + size - i + 1 || k == a[i] - size + i - 1){
                return false;
            }
        }
        return true;
    }
    bool insert(int a[], int n, int m){ // 还有m个待插入
        if (m == 0){
            vector<int> v1(a + 1, a + n + 1);
            v.push_back(v1);
            return true;
        }
        for (int i = 1; i <= n; ++i){
            if (check(a, i, n - m)){
                a[n - m + 1] = i;
                if (!insert(a, n, m-1)){
                    continue;
                }
            }
        }
        return false;
    }
    void trans(vector<vector<string>>& vs, vector<vector<int>>& v, int n){
        vector<string> tmp;
        string tmp2 = ""; // 底层是动态数组
        while(n--){
            tmp2.push_back('.');
        }
        string tmp3 = tmp2;
        int tmp1;
        for (auto item : v){
            for (int i = 0; i < item.size(); ++i){
                tmp1 = item[i];
                tmp2[tmp1 - 1] = 'Q';
                tmp.push_back(tmp2);
                tmp2 = tmp3;
            }
            vs.push_back(tmp);
            tmp.clear();
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        int a[n + 5];
        memset(a, 0, sizeof a);
        insert(a, n, n);
        vector<vector<string>> vs;
        trans(vs, v, n);
        for(auto item : v){
            for (auto subItem : item){
                cout << subItem << " ";
            }
            cout << endl;
        }
        return vs;
    }
};
// @lc code=end

