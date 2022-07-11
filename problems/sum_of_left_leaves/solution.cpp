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
    void lsu(TreeNode*node,int flag,int& ans)
    {
        if(!node)
        return;
        if(node->left==nullptr and node->right==nullptr)
        {
            if(flag==0)
            ans+=node->val;
            
            return;
        }
        lsu(node->left,0,ans);
        lsu(node->right,1,ans);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int ans=0;
        lsu(root,-1,ans);
        return ans;
    }
};