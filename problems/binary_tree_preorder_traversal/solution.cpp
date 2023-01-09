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
    void dfs(TreeNode*node,vector<int>&ret){
        if(!node)
        return;
        
        ret.push_back(node->val);
        dfs(node->left,ret);
        dfs(node->right,ret);
    }
    vector<int> preorderTraversal(TreeNode* root) {
       vector<int>ret;
       dfs(root,ret);
       return ret;
    }
};