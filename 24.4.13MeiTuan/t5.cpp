#include <iostream>
#include <unordered_set>
#include <list>
using namespace std;

int main() {
    unordered_set<string> set;
    string s;
    getline(cin, s);
    for (char c : s) {
        char* pc = &c;
        list<string> l;
        for (auto str : set) {
            if (str.back() == c) continue;
            str.push_back(c);
            if (!set.count(str)) {
                l.emplace_back(str);
            }
        } 
        for (auto item : l) {
            set.insert(item);
        }
        string cstr = string(1, c);
        if (!set.count(cstr)) {
            set.insert(cstr);
        }

    }

    std::cout << set.size();
    for (auto& i : set) {
        std::cout << i << ' ';
    }
}
// 64 位输出请用 printf("%lld")