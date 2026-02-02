#include "graph_search.h" // 引用自己的头文件

// DFS核心实现（递归）
void dfs(const std::vector<std::vector<int>>& graph, int start, std::vector<bool>& visited) {
    // 1. 访问当前节点 + 标记已访问
    std::cout << start << " ";
    visited[start] = true;

    // 2. 递归遍历所有未访问的邻居
    for (int neighbor : graph[start]) {
        if (!visited[neighbor]) {
            dfs(graph, neighbor, visited);
        }
    }
}

// BFS核心实现（队列）
void bfs(const std::vector<std::vector<int>>& graph, int start, std::vector<bool>& visited) {
    std::queue<int> q;
    // 1. 起始节点入队 + 标记已访问（入队即标记，防重复）
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        // 2. 取出队首节点并访问
        int curr = q.front();
        q.pop();
        std::cout << curr << " ";

        // 3. 所有未访问邻居入队
        for (int neighbor : graph[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

// 封装DFS入口：处理非连通图，无需外部传visited
void dfs_traverse(const std::vector<std::vector<int>>& graph) {
    int n = graph.size();
    std::vector<bool> visited(n, false); // 初始化访问标记
    std::cout << "DFS遍历结果：";
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) { // 未访问的节点重新启动DFS
            dfs(graph, i, visited);
        }
    }
    std::cout << std::endl;
}

// 封装BFS入口：处理非连通图，无需外部传visited
void bfs_traverse(const std::vector<std::vector<int>>& graph) {
    int n = graph.size();
    std::vector<bool> visited(n, false); // 初始化访问标记
    std::cout << "BFS遍历结果：";
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) { // 未访问的节点重新启动BFS
            bfs(graph, i, visited);
        }
    }
    std::cout << std::endl;
}