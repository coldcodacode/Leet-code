#include <bits/stdc++.h>
using namespace std;

void cal(int& a, int& b, int m, int n) {
    if (m == n) {
        a -= 1;
        b -= 1;
        return;
    }
    if (m == 1 || n == 1) {
        if (m > n) {
            b -= (m+1);
        } else if (m < n) {
            a -= (n+1);
        }
        return;
    }
    if (m > n) {
        a -= 1;
    } else {
        b -= 1;
    }
    return;
}

int isDead(const int& a, const int& b) {
    if (a <= 0 && b <= 0) {
        return 0;
    }
    if (a <= 0) return 1;
    if (b <= 0) return 2;
    return 3;
}

int main () {
    int a, b;
    cin >> a >> b;

    int epoch;
    cin >> epoch;
    int m, n;
    for(int i = 0; i < epoch; i++) {
        cin >> m >> n;
        cal(a, b, m, n);
        int res = isDead(a, b);
        switch (res)
        {
        case 0:
            cout << "DEAD DEAD" << endl;
            return;
        case 1:
            cout << "B WIN" << endl;
            return;
        case 2:
            cout << "A WIN" << endl;
            return;
        default:
            break;
        }
    }
    cout << "WIN WIN" << endl;
}