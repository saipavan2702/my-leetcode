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
     void dfs(TreeNode*node,string&ans,string res)
   {
    if(!node)
    return;
    if(node->right==NULL and node->left==NULL)
    {
        ans=min(char(node->val+'a')+res,ans);
    }
    dfs(node->left,ans,char(node->val+'a')+res);
    dfs(node->right,ans,char(node->val+'a')+res);
   }
    string smallestFromLeaf(TreeNode* root) {
        string ans="~";
    dfs(root,ans,"");
        return ans;
    }
};