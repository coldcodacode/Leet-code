/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;
class Solution {
public:
    int counter = 0;
    void merge(vector<vector<char>>& g, int i ,int j){
        if (g[i][j] == '1'){
            g[i][j] = '2';
            merge(g, i - 1, j);
            merge(g, i + 1, j);
            merge(g, i, j + 1);
            merge(g, i, j - 1);
        }
        // queue<pair<int, int>> q;
        // q.push(make_pair(i, j));
        // while(!q.empty()){
        //     pair<int, int> p = q.front();
        //     q.pop();
        //     g[p.first][p.second] = '2';
        //     if (g[p.first - 1][p.second] == '1'){
        //         q.push(make_pair(p.first - 1, p.second));
        //     }
        //     if (g[p.first + 1][p.second] == '1'){
        //         q.push(make_pair(p.first + 1, p.second));
        //     }
        //     if (g[p.first][p.second - 1] == '1'){
        //         q.push(make_pair(p.first, p.second - 1));
        //     }
        //     if (g[p.first][p.second + 1] == '1'){
        //         q.push(make_pair(p.first, p.second + 1));
        //     }
        // }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<char>> grid1(m + 2);
        // struct node grid1[m + 2][n + 2] = {{{'0', false}}};
        // struct node** grid1 = (struct node **)malloc(sizeof (struct node*) * (m + 2));
        // struct node** grid1 = new struct node*[m + 2];
        for (int i = 0; i < m + 2; i++){
            grid1[i].resize(n+2);
            fill(grid1[i].begin(), grid1[i].end(), '0');
        }
        for(int i = 1; i <= m; i++){
            for (int j = 1; j <= n; j++){
                grid1[i][j] = grid[i - 1][j - 1];
            }
        }
        for(int i = 1; i <= m; i++){
            for (int j = 1; j <= n; j++){
                if (grid1[i][j] == '1'){
                    counter++;
                    merge(grid1, i, j);
                }
            }
        }
        // for(int i = 0; i < m+2; ++i){
        //     delete[] grid1[i];
        // }
        // delete[] grid1;
        return counter;
    }
};
// @lc code=end

// /*
//  * @lc app=leetcode.cn id=200 lang=cpp
//  *
//  * [200] 岛屿数量
//  */

// // @lc code=start
// #include <vector>
// #include <queue>
// #include <utility>
// using namespace std;
// struct node{
//     char val = '0';
//     bool flag = false;
//     //node(char c, bool b) : val(c), flag(b) {} 
// };
// class Solution {
// public:
//     int counter = 0;
//     void merge(struct node** g, int i ,int j){
//         queue<pair<int, int>> q;
//         q.push(make_pair(i, j));
//         while(!q.empty()){
//             pair<int, int> p = q.front();
//             q.pop();
//             g[p.first][p.second].flag = true;
//             if (g[p.first - 1][p.second].val == '1'){
//                 q.push(make_pair(p.first - 1, p.second));
//             }
//             if (g[p.first + 1][p.second].val == '1'){
//                 q.push(make_pair(p.first + 1, p.second));
//             }
//             if (g[p.first][p.second - 1].val == '1'){
//                 q.push(make_pair(p.first, p.second - 1));
//             }
//             if (g[p.first][p.second + 1].val == '1'){
//                 q.push(make_pair(p.first - 1, p.second + 1));
//             }
//         }
//     }
//     int numIslands(vector<vector<char>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();
//         // struct node grid1[m + 2][n + 2] = {{{'0', false}}};
//         // struct node** grid1 = (struct node **)malloc(sizeof (struct node*) * (m + 2));
//         struct node** grid1 = new struct node*[m + 2];
//         for (int i = 0; i < m + 2; i++){
//             grid1[i] = new struct node[n + 2];
//         }
//         for(int i = 1; i <= m; i++){
//             for (int j = 1; j <= n; j++){
//                 grid1[i][j].val = grid[i - 1][j - 1];
//             }
//         }
//         for(int i = 1; i <= m; i++){
//             for (int j = 1; j <= n; j++){
//                 if (grid1[i][j].val == '1'){
//                     if (!grid1[i][j].flag){
//                         counter++;
//                     }
//                     merge(grid1, i, j);
//                 }
//             }
//         }
//         for(int i = 0; i < m+2; ++i){
//             delete[] grid1[i];
//         }
//         delete[] grid1;
//         return counter;
//     }
// };
// // @lc code=end

