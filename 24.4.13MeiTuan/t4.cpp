#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct prime{
    int num_2;
    int num_3;
    int num_5;
    int num_7;
};

const int mod = 1e9 + 7;
int main () {
    vector<int> ans;
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    vector<int> b(m);

    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];
    }

    vector<struct prime> p(m, {0, 0, 0, 0});

    for (int i = 0; i < m; i++) {
        int temp = a[i];
        while (temp % 2 == 0) {
            p[i].num_2++;
            temp /= 2;
        }
        temp = a[i];
        while (temp % 3 == 0) {
            p[i].num_3++;
            temp /= 3;
        }
        temp = a[i];
        while (temp % 5 == 0) {
            p[i].num_5++;
            temp /= 5;
        }
        temp = a[i];
        while (temp % 7 == 0) {
            p[i].num_7++;
            temp /= 7;
        }
    } 
    vector<int> preSum(m, 0);
    preSum[0] = b[0] - 1;
    for (int i = 1; i < m; i++) {
        preSum[i] = preSum[i-1] + b[i];
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        int num_2 = 1, num_3 = 1, num_5 = 1, num_7 = 1;
        int j = 0;
        while (preSum[j] < l-1) {
            j++;
        }
        int mul = (preSum[j] - (l-1) + 1);
        num_2 += p[j].num_2 * mul;
        num_3 += p[j].num_3 * mul;
        num_5 += p[j].num_5 * mul;
        num_7 += p[j].num_7 * mul;
        while (preSum[j] < r-1) {
            j++;
            mul = preSum[j] - (preSum[j-1]);
            num_2 += p[j].num_2 * mul;
            num_3 += p[j].num_3 * mul;
            num_5 += p[j].num_5 * mul;
            num_7 += p[j].num_7 * mul;
        }
        // (preSum[j] - (l-1) + 1) * p[j]
        mul = preSum[j] - (r-1);
        num_2 -= p[j].num_2 * mul;
        num_3 -= p[j].num_3 * mul;
        num_5 -= p[j].num_5 * mul;
        num_7 -= p[j].num_7 * mul;
        // ((r-1) - (k-1 < 0 ? -1 : preSum[k-1])) * p[k]
        ans.push_back((num_2*num_3*num_5*num_7) % mod);
    }
    for (auto i : ans) {
        cout << i << endl;
    }
    return 0;
}