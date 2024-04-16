#include <iostream>
#include <vector>
using namespace std;

// int v[60];
// int w[60];
// int q[60];


// dp[i+1][j] = max(
    // dp[i][j],
    // if q[i+1] == 0 then dp[i][j-w[i+1]] + v[i+1]*w[i+1]
    // else 
    //    if q[i+1] <= i then dp[i][]  
//                   
int main() {
    int N, n;
    cin >> N >> n;
    // for (int i = 1; i <= n; i++) {
    //     cin >> v[i] >> w[i] >> q[i];
    // }
    int v, p, q;
    vector<vector<int>> table(n+1, vector<int>(6, 0));
    for (int i = 1; i <= n; i++) {
        cin >> v >> p >> q;
        if (q == 0) {
            table[i][0] = v;
            table[i][1] = v*p;
        }else if (table[q][2] == 0) {
            table[q][2] = v;
            table[q][3] = v*p;
        }else {
            table[q][4] = v;
            table[q][5] = v*p;
        }
    }
    // dp[i][j] = dp[i-1][j]
    //            dp[i-1][j-table[i][0]] + table[i][1]
    //            dp[i-1][j-table[i][2]-table[i][0]] + table[i][3] + table[i][1]
    //            dp[i-1][j-table[i][4]-table[i][0]] + table[i][5] + table[i][1]
    //            dp[i-1][j-table[i][2]-table[i][4]-table[i][0]] + table[i][3] + table[i][1] + table[i][5]
    vector<int> dp(N+1);

    for (int i = 1; i <= n; i++) {
        for (int j = N; j >= 1; j--) {
            if (j - table[i][0] >= 0) dp[j] = max(dp[j], dp[j-table[i][0]] + table[i][1]);
            if (j - table[i][0] - table[i][2] >= 0) dp[j] = max(dp[j], dp[j-table[i][0]-table[i][2]] + table[i][1] + table[i][3]);
            if (j - table[i][0] - table[i][4] >= 0) dp[j] = max(dp[j], dp[j-table[i][0]-table[i][4]] + table[i][1] + table[i][5]);
            if (j - table[i][0] - table[i][2] - table[i][4] >= 0) dp[j] = max(dp[j], dp[j-table[i][0]-table[i][2]-table[i][4]] + table[i][1] + table[i][3] + table[i][5]);
        }
    }
    
    cout << dp[N];
}
// 64 位输出请用 printf("%lld")