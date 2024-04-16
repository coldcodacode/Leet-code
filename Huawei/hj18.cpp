#include <iostream>
#include <string>
#include <vector>
using namespace std;

int result[7];

int convert(string& s) {
    int len = s.size();
    int ret = 0;
    for (int i = 0; i < len; i++) {
        ret *= 10;
        ret += s[i] - '0';
    }
    return ret;
}

vector<string> split(string& s) {
    vector<string> ret;
    for (int i = 0; i < s.size(); ) {
        int pos;
        if (s.find('.', i) < s.size()) pos = s.find('.', i);
        else pos = s.size();
        ret.push_back(s.substr(i, pos - i));
        i = pos + 1;
    }
    return ret;
}

bool checkIP(vector<string>& ip) {
    if (ip.size() != 4) return false;
    for (int i = 0; i <= 3; i++) {
        if (ip[i] == "") return false;
        int num = convert(ip[i]);
        if (num > 255) return false; 
    }
    return true;
}

unsigned long combine(vector<string>& strs) {
    unsigned long ret = 0x0;
    for (int i = 0; i <= 3; i++) {
        ret <<= 8;
        ret += convert(strs[i]);
    }
    return ret;
}

bool checkCO(vector<string>& co) {
    if (co.size() != 4) return false;
    for (int i = 0; i <= 3; i++) {
        if (co[i] == "") return false;
    }
    unsigned long code = combine(co);
    bool flag = true;
    if (code == 0 || code == 0xffffffff) return false;
    for (int i = 0; i < 32; i++) {
        if (flag) {
            if (code % 2 == 1) flag = false;
            code /= 2;
        }else {
            if (code % 2 != 1) return false;
            code /= 2;
        }
    }
    return true;
}

vector<int> divide(unsigned long& num) {
    vector<int> ret;
    ret.push_back(num >> 24);
    ret.push_back((num >> 16) % 256);
    ret.push_back((num >> 8) % 256);
    ret.push_back(num % 256);
    return ret;
}

void check(string &ip, string &co) {
    vector<string> ips = split(ip);
    vector<string> cos = split(co);

    if (!checkIP(ips) || !checkCO(cos)) {
        result[5]++;
        return;
    }

    unsigned long ipAddress = combine(ips);
    unsigned long coverCode = combine(cos);

    unsigned long netCode = ipAddress & coverCode;

    vector<int> v = divide(netCode);
    if (v[0] >= 1 && v[0] <= 126) {
        if (v[0] == 10) result[6]++;
        else result[0]++;
    }else if (v[0] >= 128 && v[0] <= 191) {
        if (v[0] == 172 && v[1] >= 16 && v[1] <= 31) result[6]++;
        else result[1]++;
    }else if (v[0] >= 192 && v[0] <= 223) {
        if (v[0] == 192 && v[1] == 168) result[6]++;
        else result[2]++;
    }else if (v[0] >= 224 && v[0] <= 239) {
        result[3]++;
    }else if (v[0] >= 240 && v[0] <= 255) {
        result[4]++;
    }
}

int main() {
    string in;
    string ip, co;
    while (cin >> in) { // 注意 while 处理多个 case
        if (in == "a") break;
        ip = in.substr(0, in.find('~'));
        co = in.substr(in.find('~') + 1, in.size() - in.find('~'));

        // cout << ip + ' ' + co << endl;
        check(ip, co);
    }
    for (int i = 0; i < 7; i++) {
        cout << ' ' << result[i] ;
    }
}
// 64 位输出请用 printf("%lld")