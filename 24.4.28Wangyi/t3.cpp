#include <bits/stdc++.h>
using namespace std;

int main () {
    int p, q, x;
    cin >> p >> q >> x;
    int stat1 = x / 12;

    int stat2 = 0;
    int remain = x % 12;
    while (remain >= 5){
        if (p > q && remain >= 7){
            remain -= 7;
            q = q+1;
        } else if (p < q && remain >= 5) {
            remain -= 5;
            p = p + 1;
        } else break;
    }
    stat2 = min(p, q);
    cout << stat1 + stat2 << endl;
    return 0;
}