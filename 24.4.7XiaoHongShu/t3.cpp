#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int main() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> dp(m+1, 0);
    for (int i = 1; i <= m; i++) {
        dp[i] = i;
    }
    for (int i = 0; i < n-1; i++) {
        if (s[i] == '>') {
            for (int j = 1; j <= m; j++) {
                dp[j] = dp[m] - dp[j];
                dp[j] = (dp[j] + dp[j-1]) % mod;
            }
        } else if (s[i] == '<') {
            for (int j = m; j >= 1; j--) {
                dp[j] = dp[j-1];
            }
            for (int j = 1; j <= m; j++) {
                dp[j] = (dp[j] + dp[j-1]) % mod;
            }
        }
    }
    cout << dp[m];
}