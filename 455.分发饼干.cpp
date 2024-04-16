/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        /*Greedy strategy:
        choose as few as cookies as possible each time
        to sarisfy the child with the smallest appetite*/
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        auto itg = g.begin();
        auto its = s.begin();
        while (its != s.end() && itg != g.end()){
            if (*its < *itg){
                its++;
            }else{
                itg++;
                its++;
            }
        }
        return itg - g.begin();
    }
};
// @lc code=end

