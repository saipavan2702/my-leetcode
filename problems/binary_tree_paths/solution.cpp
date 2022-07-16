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
    void dfs(TreeNode*node,vector<string>&ans,string res)
   {
    if(node->right==NULL and node->left==NULL)
    {
        ans.push_back(res);
        return;
    }
   
    if(node->left)
    dfs(node->left,ans,res+"->"+to_string(node->left->val));
    if(node->right)
    dfs(node->right,ans,res+"->"+to_string(node->right->val));
   }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
       dfs(root,ans,to_string(root->val));
        return ans;
    }
};