#include "mytree.h"
#include<iostream>
using namespace std;

// Build a tree from an array. Use -1 to mark a NULL node
TreeNode *build_tree(vector<int> &vec, int idx)
{
    int n = vec.size();
    if (idx > n || vec[idx] == -1) return nullptr;
    TreeNode *nd = new TreeNode(vec[idx - 1]);
    nd -> left = build_tree(vec, idx * 2);
    nd -> right = build_tree(vec, idx * 2 + 1);
    return nd;
}

void inorder(TreeNode *nd)
{
    if (!nd) return;
    cout << nd -> val << " ";
    inorder(nd -> left), inorder(nd -> right);
    return;
}