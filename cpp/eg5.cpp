#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main(){
    vector<int> v_int;
    int integer = 232;
    v_int.push_back(integer);
    std::cout << "Now the val in vector:" << v_int[0] <<endl;
    integer = 345;
    std::cout << "After change the val of integer: " << v_int.at(0) << endl;
    std::cout << "the val has been changed: "<< boolalpha << (232 != v_int[0]) << endl;

    vector<string> v_string;
    string s1 = "hello";
    cout << s1 << " --the origin string address: " << &s1 <<endl;
    v_string .push_back(s1);
    std::cout << "Now the string in vector:" << v_string[0]
        << ", address: " << &v_string[0] <<endl;
    s1 = "world";
    cout << s1 << " --the origin string address:" << &s1 <<endl;
    std::cout << "After change the string: " << v_string[0]
        << ", address: " << &v_string[0] << endl;
    cout << "s1的地址没有改变, 只是它指向的地址发生了改变"<<endl;

}