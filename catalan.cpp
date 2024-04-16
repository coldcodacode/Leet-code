#include <vector>
#include <iostream>
#include <stack>

using namespace std;

struct node {
    // int level;
    int value;
    int hasLeft;
    int hasRight;
    // struct node* left;
    // struct node* right;

    node(int val, int hl, int hr) {
        // level = lev;
        value = val;
        hasLeft = hl;
        hasRight = hr;
        // left = l;
        // right  = r;        
    } 
};
typedef struct node* Node;
class Solution {
public:
    static vector<string> Catalan(int k) {
        vector<string> res;
        vector<int> mid;
        stack<Node> s;
        
        Node ptr = new node(0x1, 1, 1);
        // Node ptr_copy = ptr;

        // 回溯问题：
        // 问题建模为一棵树，左支表示‘（’，右支表示‘）’
        // 遍历这棵树，它的所有叶子节点即为所求

        // hasLeft：从根节点到此节点产生了多少左支
        // hasRight：此节点当前最多可以产生几个右支
        // ptr->hasLeft < k：ptr指向的结点有左支
        // stack中保存所有可能有右支的结点（回溯的位置）
        // s.top()->hasRight == 0：判断是否有右支的条件
        // 遍历完成标志：ptr找不到下一个需要判断的结点
        while (true) {
            while (ptr->hasLeft < k) {
                s.push(ptr);
                ptr = new node(ptr->value << 1 | 0x1, ptr->hasLeft + 1, ptr->hasRight + 1);
                // ptr_copy = ptr;
            }
            while (ptr->hasRight --) {
                ptr->value = ptr->value << 1;
            }
            mid.push_back(ptr->value);

            if (s.empty()) break;
            while (s.top()->hasRight == 0) {
                s.pop();
                if (s.empty()) break;
            }
            if (s.empty()) break;

            ptr = new node(s.top()->value << 1, s.top()->hasLeft, s.top()->hasRight - 1);
            // ptr_copy = ptr;
            s.pop();
        }
        
        // int i = 0;
        for (int bits : mid) {
            int count = k*2;
            string st;
            while (count--) {
                if (bits % 2) {
                    st.push_back(')');
                } else {
                    st.push_back('(');
                }
                bits = bits/2;
            }
            res.push_back(st);
        }
        return res;
    }
};
int main() {
    vector<string> strs = Solution::Catalan(4);
    
    for (string str: strs) {
        cout << str << '\n';
    }
    return 0;
}
