#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    long long ans = 0;
    long long temp = 0;
    int n = s.size();
    if (s[0] == '-') {
        int i;
        for (i = 2; i < n; i++) {
            if (s[i] != '0') {
                break;
            }
        }
        for (int j = i; j < n; j++) {
            ans *= 10;
            ans += (s[j] - '0');
            
        }
        for (int j = 1; j < i; j++) {
            temp *= 10;
            temp += (s[j] - '0');
            
        }
        cout << ans - temp << endl;
    } else {
        int i;
        for (i = 1; i < n; i++) {
            if (s[i] != '0') {
                break;
            }
        }
        // [0, i-1] [i, n-1]
        // [0, n-2] [n-1, n-1]
        for (int j = i; j < n; j++) {
            ans *= 10;
            ans += (s[j] - '0');
            
        }
        for (int j = 0; j < i; j++) {
            temp *= 10;
            temp += (s[j] - '0');
            
        }
        ans = ans + temp;
        temp = 0;
        for (int j = 0; j < n-1; j++) {
            temp *= 10;
            temp += (s[j] - '0');
            
        }
        temp += s[n-1] - '0';
        ans = max(ans, temp);
        cout << ans;
    }
}