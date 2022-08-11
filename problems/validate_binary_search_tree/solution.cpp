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
    bool check(TreeNode*node,long long int max,long long int min)
    {
        if(!node)
        return 1;
        if(node->val<=min or node->val>=max)
        return 0;
        
        return check(node->left,node->val,min) and check(node->right,max,node->val);
    }
    bool isValidBST(TreeNode* root) {
        if(!root)
        return 1;
        return check(root,LONG_MAX,LONG_MIN);
    }
};
