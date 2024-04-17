#include <bits/stdc++.h>
using namespace std;
// greater<Node> 小根堆的比较函数, 用到了Node的重载运算符'>'
struct Node {
    int a, b, c;
    Node() : a(0), b(0), c(0) {}
    Node(int a, int b, int c) : a(a), b(b), c(c) {}
    bool operator > (const Node& other) const {
        if (this == &other) return false;
        if (a + b*2 >= other.a + other.b*2) {
            if (a + b*2 == other.a + other.b*2) {
                if (b >= other.b) {
                    if (b ==  other.b) {
                        return c < other.c;
                    }
                    return true;
                }
                return false;
            }
            return true;
        }
        return false;
    }
};
int main () {
    int n, k;
    cin >> n >> k;
    vector<Node> input(n);
    int a, b, c;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        input[i] = Node(a, b, i+1);
    }
    set<int> res;
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    for (int i = 0; i < k; i++) {
        pq.push(input[i]);
        res.insert(input[i].c);
    }
    for (int i = k; i < n; i++) {
        if (input[i] > pq.top()) {
            res.erase(pq.top().c);
            pq.pop();
            res.insert(input[i].c);
            pq.push(input[i]);
        }
    }

    for(auto i : res) {
        cout << i << " ";
    }
}