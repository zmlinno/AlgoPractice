#include<iostream>
#include<vector>
using namespace std;

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
int main()
{
    return 0;
}