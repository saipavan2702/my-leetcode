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
    void dfs(TreeNode*node,int &cnt)
    {
        if(!node)
        return;
        if(!(node->val&1))
        {
            if(node->left and node->left->left)
            cnt+=node->left->left->val;
            if(node->left and node->left->right)
            cnt+=node->left->right->val;
            if(node->right and node->right->left)
            cnt+=node->right->left->val;
            if(node->right and node->right->right)
            cnt+=node->right->right->val;
        }
        dfs(node->left,cnt);
        dfs(node->right,cnt);
        
    }
    int sumEvenGrandparent(TreeNode* root) {
        int cnt=0;
        dfs(root,cnt);
        return cnt;
    }
};