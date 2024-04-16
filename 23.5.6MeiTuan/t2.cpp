// tanxin
#include <iostream>
#include <string>
#include <vector>
#include <utility>
using namespace std;

pair<char, int> parse(string s){
    pair<char, int> P;
    int retNum = stoi(s.substr(1));
    P.first = s.at(0);
    P.second = retNum;
    return P;
}
int simulate(pair<char, int> p, int cur){
    switch (p.first)
    {
    case '+':
        cur += p.second;
        return cur;
    case '-':
        cur -= p.second;
        return cur;
    case '*':
        if(cur >= p.second) {
            cur += p.second;
            return cur;
        }
        else return -10000;
    case '/':
        cur /= p.second;
        return cur;
    default:
        return -10000;
        break;
    }
}
int main(){
    pair<char, int> PAIR;
    int n, k;
    cin >> n >> k;
    vector<string> left;
    vector<string> right;
    
    for(int i = 0; i < n; ++i){
        string s;
        cin >> s;
        left.push_back(s);
    }
    for(int i = 0; i < n; ++i){
        string s;
        cin >> s;
        right.push_back(s);
    }

    string l, r;
    pair<char, int> pl, pr;
    for (int i = 0; i < n; i++){
        l = left.at(i);
        r = right.at(i);
        pl = parse(l);
        pr = parse(r);
        // cout << simulate(pl, k) << " " << k << endl;
        if (simulate(pl, k) > simulate(pr, k)){
            k = simulate(pl, k); 
        }else{
            k = simulate(pr, k);
        }
        if (k == -10000) {
            cout << -1 << endl;
            return -1;
        }
    }
    cout << k << endl;
    return k;
}