#include <bits/stdc++.h>
using namespace std;

int main () {
    cout << "list:          " << sizeof(list<int>) << endl   ;
    cout << "vector:        " << sizeof(vector<int>) << endl;
    cout << "deque:         " << sizeof(deque<int>) << endl  ;
    cout << "stack:         " << sizeof(stack<int>) << endl  ;
    cout << "queue:         " << sizeof(queue<int>) << endl  ;
    cout << "priority_queue:" << sizeof(priority_queue<int>) << endl;
    cout << "set:           " << sizeof(set<int>) << endl  ;
    cout << "unordered_set: " << sizeof(unordered_set<int>) << endl  ;
    cout << "map:           " << sizeof(map<int, int>) << endl ;
    cout << "unordered_map: " << sizeof(unordered_map<int, int>) << endl ;
    return 0;
}