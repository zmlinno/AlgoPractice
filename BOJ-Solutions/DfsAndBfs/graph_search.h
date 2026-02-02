#ifndef GRAPH_SEARCH_H
#define GRAPH_SEARCH_H

#include <vector>
#include <iostream>
#include <queue>
using namespace std;


//无向图的DFS遍历函数声明

void dfs(const std::vector<std::vector<int>>& graph, int start, std::vector<bool>& visited);


// 无向图的BFS遍历函数声明
void bfs(const std::vector<std::vector<int>>& graph, int start, std::vector<bool>& visited);

// 封装：遍历整个图（处理非连通图）的DFS入口
void dfs_traverse(const std::vector<std::vector<int>>& graph);

// 封装：遍历整个图（处理非连通图）的BFS入口
void bfs_traverse(const std::vector<std::vector<int>>& graph);

#endif // GRAPH_SEARCH_H