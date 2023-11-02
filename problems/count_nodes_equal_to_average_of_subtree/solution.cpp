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
    int averageOfSubtree(TreeNode* root) {
        using T=TreeNode*;
        using pI=pair<int,int>;

        int cnt=0;
        function<pI(T)>recur=[&](T node)->pI{
            if(!node) return {0,0};
            pI l=recur(node->left);
            pI r=recur(node->right);

            int S=l.first+r.first+node->val;
            int C=l.second+r.second+1;

            if(S/C==node->val) cnt++;
            return {S,C};
        };
        recur(root);
        return cnt;
    }
};