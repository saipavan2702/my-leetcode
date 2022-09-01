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
    void dfs(TreeNode*node,int&cnt,int hi)
    {
        if(!node)
        return;
        
        if(node->val>=hi)
        {
         cnt++;
         hi=node->val;
        }
        
        dfs(node->left,cnt,hi);
        dfs(node->right,cnt,hi);
    }
    int goodNodes(TreeNode* root) {
        int cnt=0;
        dfs(root,cnt,INT_MIN);
        return cnt;
    }
};