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
            if(!node)
            return {0,0};

            auto ln= recur(node->left);
            auto rn=recur(node->right);

            long subS=node->val+ln.first+rn.first;
            long subC=ln.second+rn.second+1;

            long avg=subS/subC;
            if(avg==node->val)
            cnt++;

            return {node->val+ln.first+rn.first, ln.second+rn.second+1};

        };
        recur(root);
        return cnt;
    }
};