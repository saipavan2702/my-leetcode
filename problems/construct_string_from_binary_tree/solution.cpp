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
    using T=TreeNode*;
    string tree2str(TreeNode* root) {
        string s="";
        function<void(T)>recur=[&](T node){
            if(!node) return;

            s+=to_string(node->val);

            if(node->left){
                s+="(";
                recur(node->left);
                s+=")";
            }

            if(node->right) {
                if(!node->left) s+="()";
                
                s+="(";
                recur(node->right);
                s+=")";
            }
        };

        recur(root);
        return s;
    }
};