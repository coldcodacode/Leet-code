#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * Note: 类名、方法名、参数名已经指定，请勿修改
     *
     * 
     * 
     * @param originStr string字符串  
     * @return string字符串
     */
    string ReverseString(string originStr) {
        // write code here
        string temp;
        int last = 0;
        int i = 0;
        for (; i < originStr.size(); i++) {
            char ch = originStr[i];
            if (ch == ' ') {
                last = i - 1;
                for (auto it : temp) {
                    originStr[last--] = it;
                }
                temp.clear();
                continue;
            }
            temp.push_back(ch);
        }
        last = i - 1;
        for (auto it : temp) {
            originStr[last--] = it;
        }
        temp.clear();

        return originStr;
    }
};


int main() {
    Solution s;
    cout << s.ReverseString("hello world, my friends");
}
