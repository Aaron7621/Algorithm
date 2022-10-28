#include<vector>

struct TreeNode
{
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};


TreeNode *build_tree(std::vector<int>&, int);
void inorder(TreeNode *nd);
