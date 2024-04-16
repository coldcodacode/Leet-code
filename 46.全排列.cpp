/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int num = nums.size();
        if (num == 1){
            vector<vector<int>> v;
            vector<int> v1;
            v1.push_back(nums.at(0));
            v.push_back(v1);
            return v;
        }
        vector<vector<int>> res;
        for (auto it = nums.begin(); it != nums.end(); it++){
            vector<int> copy = nums;
            copy.erase(remove(copy.begin(), copy.end(), *it));
            vector<vector<int>> temp = permute(copy);
            vector<int> resItem {*it};
            for (auto it1 = temp.begin(); it1 != temp.end(); it1++){
                resItem.insert(resItem.end(), (*it1).begin(), (*it1).end());
                res.push_back(resItem);
                resItem.erase(resItem.begin() + 1, resItem.end());
            }
        }
        return res;
    }
};
// @lc code=end

// @lc code=start
// from CSView
class Solution {
public:
    vector<vector<int>> ans;
    /*  dfs: 当前已排好序的部分为tmp，根据nums和visit，确定还没排的元素
        完成剩余的排序，并把每一个生成的全排列加入ans
    */
    void dfs(vector<int>& nums, vector<int>& visit, vector<int>& tmp) {
        int n = nums.size();
        if(tmp.size() == n) {
            ans.emplace_back(tmp);
            return;
        }
        for(int i = 0; i < n; i++) {
            if(visit[i]) {
                continue;
            }
            tmp.emplace_back(nums[i]);
            visit[i] = 1;
            dfs(nums, visit, tmp);
            tmp.pop_back();
            visit[i] = 0;
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> visit(n);
        vector<int> tmp;
        dfs(nums, visit, tmp);
        return ans;
    }
};
// @lc code=end

