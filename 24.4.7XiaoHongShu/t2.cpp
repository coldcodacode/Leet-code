#include <bits/stdc++.h>
using namespace std;

struct Node{
    int a;
    int b;
    Node() : a(0), b(0) {}
    Node(int a, int b) : a(a), b(b) {}
};
int main() {
    int n, k;
    cin >> n >> k;
    vector<Node> input(n);
    for (int i = 0; i < n; i++) {
        cin >> input[i].a;
    }
    for (int i = 0; i < n; i++) {
        cin >> input[i].b;
    }
    sort(input.begin(), input.end(), [](const Node& a, const Node& b) {
        return a.b > b.b;
    });
    priority_queue<int, vector<int>, greater<int>> pq;
    int sum0 = 0;
    for (int i = 0; i < k; i++) {
        pq.push(input[i].a);
        sum0 += input[i].a;
    }
    int b0 = input[k-1].b;
    int res = sum0 * b0;
    for (int i = k; i < n; i++) {
        if (pq.top() < input[i].a) {
            b0 = input[i].b;
            sum0 = sum0 - pq.top() + input[i].a;
            res = max(res, sum0 * b0);
        }
    }

    cout << res << endl;
}