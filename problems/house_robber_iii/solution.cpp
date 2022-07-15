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
    pair<int,int> postorder(TreeNode*node)
    {
        if(!node)
        return {0,0};
       
        auto l=postorder(node->left);
        auto r=postorder(node->right);
        int a=l.second+r.second;
        int b=max(a,node->val+l.first+r.first);
        return {a,b};
    }
    int rob(TreeNode* root) {
        auto ans=postorder(root);
        return ans.second;
        
    }
};