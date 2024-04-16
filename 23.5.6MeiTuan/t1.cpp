#include <iostream>

using namespace std;

int main(){
    int n, k;
    cin >> n >>k;
    int* a = new int[n];
    int* c = new int[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        cin >> c[i];
        c[i] = a[i] + c[i];
    }
    int start = a[0];
    int ret = 0;
    for (int i = 0; i < n; i++){
        start = (start >= a[i])? start : a[i]; 
        if (start <= c[i]){
          ret++;
          start = start + k;
        }   
    }
    cout << ret << endl;
    return ret;
}