#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * Note: 类名、方法名、参数名已经指定，请勿修改
     *
     * 
     * 
     * @param nums int整型 vector 
     * @return string字符串
     */
    void getEachDigit(int a, vector<int>& ma) {
        ma.push_back(a%10);
        while (a / 10) {
            a = a/10;
            ma.push_back(a%10);
        }
    }
    string LargestNum(vector<int>& nums) {
        // write code here
        sort(nums.begin(), nums.end(), [this](int a, int b) {
            if (a == b) return false;
            vector<int> ma;
            vector<int> mb;
    
            getEachDigit(a, ma);
            getEachDigit(b, mb);

            int m = ma.size();
            int n = mb.size();

            // 从最高位开始循环比较两个数位的大小，作为a和b大小的判断标准
            auto i = m-1, j = n-1;
            int count = m + n;
            while (count--) {
                if (ma[i] == mb[j]) {
                    i--;
                    j--;
                    if (i < 0) {
                        i = n-1;
                    }
                    if (j < 0) {
                        j = m-1;
                    }
                    continue;
                }
                return ma[i] > mb[j];
            }
            return false;
        });

        string ans;
        for (auto i : nums) {
            ans.append(to_string(i));
        }
        return ans;

    }
};

int main() {
    Solution s;
    vector<int> a({11, 1});
    string ans = s.LargestNum(a);
    cout << ans;
}