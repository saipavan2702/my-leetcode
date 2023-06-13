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
    TreeNode* searchBST(TreeNode* root, int val) {
        using T=TreeNode*;
        T need=nullptr;

        function<void(T)>recur=[&](T node){
            if(!node)
            return;

            if(node->val<val)
            recur(node->right);
            else if(node->val>val)
            recur(node->left);
            else
            {need=node;return;}
        };
        recur(root);
        return need;
    }
};