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
    struct N{
        bool isValid;
        int lo,hi,runS;
    };
    int maxSumBST(TreeNode* root) {
        using T=TreeNode*;
        int gS=0;

        function<N(T)>recur=[&](T node)->N{
            if(!node)
            return {true,INT_MAX,INT_MIN,0};

            N lS=recur(node->left);
            N rS=recur(node->right);

            if(lS.isValid && rS.isValid && lS.hi<node->val && rS.lo>node->val){
                int currS=lS.runS+rS.runS+node->val;
                gS=max(gS,currS);

                return {1, min(lS.lo,node->val),max(rS.hi,node->val),currS};
            }
            else
            return {0,0,0,0};

        };
        recur(root);
        return gS;
    }
};