/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    using N=TreeNode*;
    bool recur(N left, N right){
        if(!left && !right)
        return 1;

        if(!left or !right or left->val!=right->val)
        return 0;

        return recur(left->left,right->right) && recur(left->right,right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)
        return 1;

        return recur(root->left,root->right);
    }
};