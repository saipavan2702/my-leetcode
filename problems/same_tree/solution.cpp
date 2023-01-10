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
    bool recur(TreeNode*node,TreeNode*data){
        if(!node && !data)
        return 1;

        if(!node || !data)
        return 0;
        
        if(node->val!=data->val)
        return 0;

        return recur(node->left,data->left) && recur(node->right,data->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return recur(p,q);
    }
};