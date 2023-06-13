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
    int maxPathSum(TreeNode* root) {
        using T=TreeNode*;
        int hs=-1e9;
        function<int(T)>recur=[&](T node){
            if(!node)
            return 0;

            int ls=max(recur(node->left),0);
            int rs=max(recur(node->right),0);
            hs=max(hs,ls+rs+node->val);

            return max(ls,rs)+node->val;  
        };
        recur(root);
        return hs;
    }
};