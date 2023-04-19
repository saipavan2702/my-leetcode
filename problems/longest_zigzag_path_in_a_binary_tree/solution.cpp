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
    int longestZigZag(TreeNode* root) {
        int l=0;
        int r=0;
        int need=0;

        function<void(TreeNode*,int,int)>recur=[&](TreeNode*node,int l,int r)->void{
            if(!node)
            return;

            need=max({need,l,r});
            recur(node->left,0,l+1);
            recur(node->right,r+1,0);
        };
        recur(root, l,r);
        return need;
    }
};