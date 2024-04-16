#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int val;
    struct Node* lchild;
    struct Node* rchild;
    Node(int val) {
        this->val = val;
    }
};
typedef struct Node* pNode;
vector<int> ret(100);
vector<vector<int>> res;

bool func(pNode root, int target) {
    if (!root) {
        return false;
    }
    if (target < 0 ) {
        return false;
    }
    ret.push_back(root->val);
    target = target - root->val;

    if (!root->lchild && !root->rchild && target == 0) return true;

    if ( func(root->lchild, target) ) {
        return true;
    } else if ( func(root->rchild, target) ) {
        return true;
    } else {
        ret.pop_back();
    }
    return false;
}

void func1(pNode root, int target) {
    if (!root) {
        return ;
    }
    if (target < 0 ) {
        return ;
    }
    ret.push_back(root->val);
    target = target - root->val;

    if (!root->lchild && !root->rchild && target == 0) {
        res.emplace_back(ret);
        return;
    }

    func1(root->lchild, target);
    func1(root->rchild, target);
    
    ret.pop_back();
}

void create(vector<pNode>& v) {
    queue<pNode> q;
    int i = 0;
    q.push(v[i++]);

    while (!q.empty()) {
        pNode tmpPtr = q.front();
        q.pop();
        // tmpPtr = new Node(tmp);
        if (v[i]) q.push(v[i]);
        tmpPtr->lchild = v[i++];
        if (v[i]) q.push(v[i]);
        tmpPtr->rchild = v[i++];
    }
} 

void init(vector<pNode>& v, int a[], int a_size) {
    for (int i = 0; i < a_size; i++) {
        if (a[i] != NULL) v.push_back(new Node(a[i]));
        else v.push_back(nullptr);
    }
}

int main () {
    vector<pNode> v;
    int a[] = {5,4,8,11,NULL,13,4,7,2,NULL,NULL,5,1};
    init(v, a, 13);
    pNode root = v[0];
    create(v);
    
    func1(root, 22);
    for (auto it = res.begin(); it != res.end(); it++) {
        for (auto it1 = (*it).begin(); it1 != (*it).end(); it1++)
            cout << *it1 << " ";
        cout << endl;
    }
}