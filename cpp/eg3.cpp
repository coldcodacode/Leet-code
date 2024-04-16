#include <iostream>
#include <string>
#include <map>
#include <string.h>
#include <iterator>
#include <vector>
using namespace std;

int main()
{
    // 直接赋值
    vector<string> vec1;
    vec1.push_back("helloWorld");
    vector<string> vec2;
    vec1 = vec2;
    cout << "vec1 address: " << &vec1 << endl; //0x61fcb0
    cout << "vec2 address: " << &vec2 << endl; //0x61fc90

    // 通过copy（）赋值
    
    map<string, int>
            m_map;
    m_map.insert(make_pair<string, int>("Element1", 5));
    m_map.insert(make_pair<string, int>("Element2", 15));
    map<string, int>::iterator it = m_map.begin();
    for (it; it != m_map.end(); it++)
    {
        cout << "m_map first is " << it->first << ", "
             << "m_map second is " << it->second << endl;
    }
    cout << "Previous m_map Size is ==========================" << m_map.size() << endl; // 2

    cout << "Start Copying Map ==============================" << endl;
    map<string, int> m_Copymap;
    // 利用copy拷贝
    copy(m_map.begin(), m_map.end(), inserter(m_Copymap, m_Copymap.begin()));
    // 拷贝结束
    cout
        << "Copy Map Done! ======================" << endl;

    m_map.clear();
    cout << "Clear Previous Map Done!=======================" << endl;

    cout << "Now m_map Size is =======================" << m_map.size() << endl; // 0
    cout << "m_Copymap Size is " << m_Copymap.size() << endl; // 2 
    map<string, int>::iterator it1 = m_Copymap.begin();
    for (it1; it1 != m_Copymap.end(); it1++)
    {
        cout << "m_Copymap first is " << it1->first << ", "
             << "m_Copymap second is " << it1->second << endl;
    }
    return 0;
}