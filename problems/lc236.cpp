/*
    236. Lowest Common Ancestor of a Binary Tree
*/

#include<iostream>
#include<vector>
#include "mytree.h"

using namespace std;

TreeNode* lowest_common(TreeNode *nd, int p, int q)
{
    if (!nd || nd -> val == p || nd -> val == q) return nd;
    TreeNode *l = lowest_common(nd -> left, p, q), *r = lowest_common(nd -> right, p, q);
    if (l && r) return nd;
    return l ? l : r;
}

int main()
{
    int n, p, q;
    cin >> n;
    vector<int> treevec(n);
    for (int i = 0; i < n; ++ i) cin >> treevec[i];
    TreeNode *root = build_tree(treevec, 1);
        
    // cin >> p >> q;

    // lowest_common(root, p, q);

    return 0;
} 