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
    bool isBalanced(TreeNode* root) {
        using T=TreeNode*;
        bool up=1;
        function<int(T,int)>recur=[&](T node,int h){
            if(!node)
            return 0;

            int l=recur(node->left,h+1);
            int r=recur(node->right,h+1);
            if(abs(l-r)>=2)
            up=0;

            return max(l,r)+1;
        };
        recur(root,0);
        return up;
    }
};