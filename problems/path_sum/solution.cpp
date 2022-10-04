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
    int k;
    void recur(TreeNode*node,int t,int s)
    {
        if(!node)
        return;
        
        s+=node->val;
        if(s==t and !node->left and !node->right)
        k=1;
        
        recur(node->left,t,s);
        recur(node->right,t,s);
        s-=node->val;
        
    }
    bool hasPathSum(TreeNode* root, int t) {
        k=0;
        recur(root,t,0);
        return k;
    }
};