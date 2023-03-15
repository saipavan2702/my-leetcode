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
    using N=TreeNode*;
    bool recur(N node, int i, int hav){
        if(!node)
        return 1;

        if(i>=hav)
        return 0;

        return recur(node->left,2*i+1,hav) && recur(node->right,2*i+2,hav);
    }
    int count(N node){
        if(!node)
        return 0;

        return 1+count(node->left)+count(node->right);
    }
    bool isCompleteTree(TreeNode* root) {
       if(!root)
       return 0;

       int hav=count(root);
       return recur(root,0,hav);
    }
};