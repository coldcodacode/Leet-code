#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int n = 3;
    string s;
    vector<string> v(4);
    for (int i = 0; i < n; ++i){
        cin >> s;
        v.push_back(s);
    }
    v.push_back("1234");
    for (int i = 0; i < 4; ++i){
        cout << v[i] << endl;
    }
}