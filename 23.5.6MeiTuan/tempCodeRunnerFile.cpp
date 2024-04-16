#include <iostream>
#include <vector>
using namespace std;

int findMax(vector<int> &v){
    int index = 0;
    for (int i = 1; i < v.size(); i++){
        if(v[i] > v[index])
            index = i;
    }
    return index;
}

int main(){
    int n, k;
    cin >> n >>k;
    int* a = new int[n];
    int* w = new int[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        cin >> w[i];
    }
    int ret = 0;

    vector<int> v;
    int need = 0;
    int index;
    int start = 0;
    while(start < n){
        while (w[start] != 2){
            v.push_back(a[start]);
            start++;
        }
        need = a[start] - k;
        while (need > 0){
            if (v.empty()) return -1;
            index = findMax(v);
            ret++;
            k += v[index];
            need -= v[index];
            v.erase(v.begin() + index);
        }
    }
    return ret;
}