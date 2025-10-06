#include <bits/stdc++.h>
using namespace std;
// 两个大数(无法用int64表示)乘积
string mutiply(const string& num1, const string& num2) {
    int len1 = num1.size();
    int len2 = num2.size();
    vector<int> result(len1 + len2, 0);

    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int digit1 = num1[i] - '0';
            int digit2 = num2[j] - '0';
            int product = digit1 * digit2;

            int pos_low = i + j + 1;
            int pos_high = i + j;

            int sum = result[pos_low] + product;

            result[pos_low] = sum % 10;
            result[pos_high] += sum / 10;
        }
    }

    for (int i = len1 + len2 - 1; i > 0; i--) {
        if (result[i] / 10 > 0) {
            result[i-1] += result[i] / 10;
            result[i] = result[i] % 10;
        }
    }

    string res;
    int start = 0;
    while (result[start] == 0) {
        start++;
    }
    for (int i = start; i < result.size(); i++) {
        cout << result[i] << endl;
        res.push_back(result[i] + '0');
    }
    return res;
}


int main() {
    string num1 = "11";
    string num2 = "22";
    cout << mutiply(num1, num2) << endl; 
}