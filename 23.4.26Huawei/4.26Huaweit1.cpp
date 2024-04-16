
// we have defined the necessary header files here for this problem.
// If additional header files are needed in your program, please import here.
#include <vector>
#include <iostream>
using namespace std;
#define N 1000
struct node
{
    int val;
    struct node *next;
};
struct digram
{
    struct node *nodes[N];
};
int indegree[1000] = {0};
// build a graph (out degree)
// calculate indegree
int main()
{
    // please define the C++ input here. For example: int a,b; cin>>a>>b;;
    // please finish the function body here.
    // please define the C++ output here. For example:cout<<____<<endl;
    struct digram graph;
    for (int i = 0; i < N; i++)
    {
        graph.nodes[i] = nullptr;
    }
    int nodes;
    cin >> nodes;
    for (int i = 0; i < nodes; i++)
    { // 第i个点 模块号i + 1
        int edges;
        cin >> edges;
        indegree[i] = edges;
        for (int j = 0; j < edges; j++)
        {
            int temp;
            cin >> temp;
            struct node *newnode = new node();
            newnode->val = i;
            newnode->next = graph.nodes[temp - 1];
            graph.nodes[temp - 1] = newnode;
        }
    }
    int res = 0;
    vector<int> helper;
    bool flag = true;
    while (true)
    {
        for (int i = 0; i < nodes; i++)
        {
            if (indegree[i] != -1)
            {
                flag = false;
            }
            if (indegree[i] == 0)
            {
                indegree[i]--;
                helper.push_back(i);
            }
        }
        if (flag)
        {
            break;
        }
        else
        {
            if (helper.empty())
            {
                return -1;
            }
            else
            {
                res++;
            }
        }
        for (long long unsigned int i = 0; i < helper.size(); i++)
        {
            struct node *temp = graph.nodes[helper.at(i)];
            while (temp != nullptr)
            {
                indegree[temp->val]--;
                temp = temp->next;
            }
        }
        helper.clear();
        flag = true;
    }
    cout << res << endl;
    for (int i = 0; i < nodes; i++)
    {
        struct node *temp = graph.nodes[i];
        struct node *temp1 = nullptr;
        while (temp != nullptr)
        {  
            temp1 = temp;
            temp = temp->next;
            delete(temp1);
        }
    }
    return res;
}
