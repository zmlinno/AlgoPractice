#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>> graph; // 图的邻接表表示
vector<bool> visited;      // 访问标记数组
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};

void dfs(TreeNode* node)
{
    if(node == nullptr)
        return;

    // Process the current node
    cout << node->val << " ";

    // Traverse the left subtree
    dfs(node->left);

    // Traverse the right subtree
    dfs(node->right);
}

void dfs1(int u)
{
    //1.访问当前节点
    cout<<u<<" ";

    //2.标记为当前节点已访问
    visited[u] = true;  

    //3.遍历当前节点的所有邻接节点
    for(int v:graph[u])
    {
        if(!visited[v])
        {
            dfs1(v);
        }
    }
}
// int main()
// {
//     TreeNode* root = new TreeNode(1);    // 根节点1
//     root->right = new TreeNode(2);      // 1的右孩子2
//     root->right->left = new TreeNode(3); // 2的左孩子3

//     // 4. 执行DFS遍历
//     cout << "DFS前序遍历结果：";
//     dfs(root);

//     int n = 5;
//     graph.resize(n);
//     visited.resize(n, false);
//     graph[0].push_back(1); graph[1].push_back(0); // 0-1 双向边
//     graph[0].push_back(2); graph[2].push_back(0); // 0-2 双向边
//     graph[1].push_back(3); graph[3].push_back(1); // 1-3 双向边
//     graph[2].push_back(4); graph[4].push_back(2); // 2-4 双向边
//     cout << "无向图DFS遍历结果（从0开始）：";
//     dfs1(0);

//     return 0;
// }


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<string> grid(N);
    for (int i = 0; i < N; i++) cin >> grid[i];

    // dist[x][y] = 从起点到 (x,y) 最少经过的格子数（起点为 1）
    vector<vector<int>> dist(N, vector<int>(M, 0));

    queue<pair<int,int>> q;
    dist[0][0] = 1;          // (1,1) -> 下标 (0,0)
    q.push({0, 0});

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            // 1) 边界检查
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

            // 2) 只能走 '1'
            if (grid[nx][ny] == '0') continue;

            // 3) 没访问过才入队（dist==0 表示未访问）
            if (dist[nx][ny] == 0) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    cout << dist[N-1][M-1] << "\n";
    return 0;
}