#include "graph_search.h" // 引用封装好的头文件

int main() {
    // 1. 构建测试用的无向图（和之前一致：0-1-3、0-2-4）
    int node_num = 5; // 节点0~4
    std::vector<std::vector<int>> graph(node_num);
    // 无向图双向加边
    graph[0].push_back(1); graph[1].push_back(0);
    graph[1].push_back(3); graph[3].push_back(1);
    graph[0].push_back(2); graph[2].push_back(0);
    graph[2].push_back(4); graph[4].push_back(2);

    // 2. 测试DFS遍历
    dfs_traverse(graph);

    // 3. 测试BFS遍历
    bfs_traverse(graph);

    // 可选：测试非连通图（比如0-1、2-3、4单独）
    std::cout << "===== 非连通图测试 =====" << std::endl;
    std::vector<std::vector<int>> disconnected_graph(5);
    disconnected_graph[0].push_back(1); disconnected_graph[1].push_back(0);
    disconnected_graph[2].push_back(3); disconnected_graph[3].push_back(2);
    dfs_traverse(disconnected_graph);
    bfs_traverse(disconnected_graph);

    return 0;
}