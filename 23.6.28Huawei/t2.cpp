
// we have defined the necessary header files here for this problem.
// If additional header files are needed in your program, please import here.

#include <string>
#include <iostream>
#include <stack>
using namespace std;
#define MAX_SIZE 1130

struct node{
    char s[MAX_SIZE];
    struct node* child;
    struct node* brother;
} ;

typedef struct node* pnode;

void cleanBuffer(char * buf){
    for (int i = 0; i < MAX_SIZE; ++i){
        buf[i] = '\0';
    }
}

void initNode(pnode node, char *buf){
    int i = 0;
    while(buf[i] != '\0'){
        node->s[i] = buf[i];
        i++;
    }
    node->s[i] = '\0';
    cleanBuffer(buf);
}

void insertTree(char *buf, pnode cur, pnode parent){
    cur = new struct node();
    initNode(cur, buf);
    if (!parent->child){
        parent->child = cur;
    }else{
        pnode tmp = parent->child;
        while(tmp->brother){
            tmp = tmp->brother;
        }
        tmp->brother = cur;
    }

}

void printTree(pnode root){
    
    stack<pnode> st;
    st.push(root);

    cout << st.top()->s;
    while(root->)

}

int main()
{
    // please define the C++ input here. For example: int a,b; cin>>a>>b;;
    // please finish the function body here.
    // please define the C++ output here. For example:cout<<____<<endl;
    char rule[MAX_SIZE];
    cin >> rule;
    getchar();
    // cout << rule;

    stack<pnode> st;
    char buf[MAX_SIZE];
    buf[0] = '/';
    pnode root = new struct node();
    initNode(root, buf);
    st.push(root);

    char c;
    int counter = 1;
    pnode cur;
    pnode parent = root;
    while ( (c= getchar()) != '\n'){
        if (c == ' '){
            while(c = getchar() == ' ') counter++;
            // counter ++;
        }
        counter /= 4;
        buf[0] = c;
        cin >> buf + 1;
        getchar();

        if (counter + 1 > st.size()){
            st.push(cur);
        }
        else if (counter + 1 < st.size()){
            st.pop();
        }
        insertTree(buf, cur, st.top());

        counter = 0;
        cleanBuffer(buf);
        // return 0;
    }
    
    // cout << buf;
    // insertTree(buf, )
    

    return 0;
}
