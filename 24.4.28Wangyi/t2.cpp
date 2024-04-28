#include <bits/stdc++.h>
using namespace std;

void mySwap(vector<pair<int, int>>& t, int i, int j) {
    if (i == j) return;
    pair<int, int> tmp = make_pair(t[i].first, t[i].second);
    t[i].first = t[j].first;
    t[i].second = t[j].second;
    t[j].first = tmp.first;
    t[j].second = tmp.second;
}

void mySort(vector<pair<int, int>>& t) {
    // 按奖励的大小排序
    for (int i = 0; i < t.size(); i++) {
        int cur = i;
        for (int j = i+1; j < t.size(); j++) {
            if (t[j].first > t[cur].first) {
                cur = j;
            }
        }
        mySwap(t, cur, i);
    }
}

int main () {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> task(n, make_pair(0, 0));
    for (int i = 0; i < n; i++) {
        cin >> task[i].first >> task[i].second;
    }
    sort(task.begin(), task.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first)
            return a.second > b.second;
        else
            return a.first > b.first;
    });
    // mySort(task);
    vector<int> ticket(m+1, 0);
    for (int i = 1; i <= m; i++) {
        cin >> ticket[i];
    }

    long long ans = 0;
    for (int i = m; i >= 1; i--) {
        int num = ticket[i];
        for (int j = 0; j < n && num > 0; j++) {
            if (task[j].second >= i) {
                ans += task[j].first;
                task[j].second = 0;
                num--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}