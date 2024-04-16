#include <iostream>
#include <vector>
using namespace std;




int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<int> dp(k+1, 0);
    for (int i = 0; i < n; i++) { 
        cin >> a[i];
        if (a[i] < 0) a[i] = 0-a[i];
    }
    // dp[i][k] = max( dp[i-1][k] , dp[i-1][k-a[i]]+1 )
    for (int i = 0; i < n; i++) {
        for (int j = k; j >= 0; j--) {
            if (j-a[i] >= 0) {
                dp[j] = max( dp[j], dp[j-a[i]] + 1);
            }
        }
    } 
    cout << dp[k];
    // for (int i = 0; i < n; i++) cout << a[i] << ' ';

    
    return 0;
}
// 64 位输出请用 printf("%lld")