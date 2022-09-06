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
    TreeNode* dfs(TreeNode*node)
    {
        if(!node)
        return nullptr;
        
        node->left=dfs(node->left);
        node->right=dfs(node->right);
        
        if(!node->left and !node->right and node->val==0)
        return nullptr;
        
        return node;
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(!root)
        return NULL;
        
        root=dfs(root);
        return root;
    }
};