#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct B{ char b; int a; short c;};
int *ptr;

void foo() {
    int b = 10;
    ptr = &b;
}

int main () {

    foo(); 
    int value = *ptr;
    cout << value << '\n'; // 10

    B b = {'a', 1, 1};
    B b2 = {'c', 3, 3};
    const B& b3 = b2;
    cout << b.b << '\n'; // a
    b = b3;
    cout << &b << " " << &b2 << " "<< &b3 << '\n'; // 
    cout << b.b << '\n'; // c
    cout << b2.b << '\n'; // c
    cout << b3.b << '\n'; // c

    string s = "abs";
    string ps = s;
    cout << &s << " " << &ps << '\n';

    cout << -1 % 5 << '\n'; // -1

    cout << '9' - '0' << '\n'; // 9

    vector<int> v_int;
    vector<string> v_str(10);
    v_int.push_back(1);
    v_int.push_back(2);
    cout << sizeof(v_int) << " " << sizeof v_str<< '\n'; // 24 24
    
}