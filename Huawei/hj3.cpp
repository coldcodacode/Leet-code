#include <iostream>
#include <set>
using namespace std;

// time limitation: O(n^2) 

int main() {
    // int a, b;
    // while (cin >> a >> b) { // 注意 while 处理多个 case
    //     cout << a + b << endl;
    // }

    int n;
    cin >> n;
    int i = 0;
    int ar;
    set<int> s;
    while (i < n) {
        cin >> ar;
        s.insert(ar);
        i++;
    }

    for (auto it : s) {
        cout << it << '\n'; 
    }
}
// 64 位输出请用 printf("%lld")