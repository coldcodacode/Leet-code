#include <iostream>
using namespace std;
#define N 105
int a[N][N];

int main() {
    int m, n;
    int ans = 0;
    cin >> m >> n;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            // if (i + 1 >= m || j + 1 >= n) {
            //     break;
            // }
            if (a[i][j] == a[i+1][j+1] && a[i][j] == a[i+1][j] && a[i][j] == a[i][j+1]) {
                ans++;
            }
        }
    }
    cout << ans;
    return ans;
}
// 64 位输出请用 printf("%lld")