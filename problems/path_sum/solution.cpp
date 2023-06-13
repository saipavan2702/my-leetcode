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
    bool hasPathSum(TreeNode* root, int S) {
        using T=TreeNode*;
        if(!root)
        return 0;

        function<bool(T,int)>recur=[&](T node, int curr){
            if(!node)
            return false;

            if(!node->left && !node->right){
                if(curr+node->val==S)
                return true;
                else
                return false;
            }
            return recur(node->left,curr+node->val) || recur(node->right,curr+node->val);
        };
        return recur(root,0);
    }
};