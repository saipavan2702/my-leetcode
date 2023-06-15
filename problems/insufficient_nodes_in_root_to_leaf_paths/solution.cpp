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
    TreeNode* sufficientSubset(TreeNode* root, int l) {
        using T=TreeNode*;
        function<T(T,int)>recur=[&](T node, int cur)->T{
            if(!node)
            return nullptr;

            if(!node->left && !node->right ){
                if(cur+node->val<l)return nullptr;

                return node;
            }

            node->left=recur(node->left,cur+node->val);
            node->right=recur(node->right,cur+node->val);

            if(!node->left && !node->right)
            return nullptr;

            return node;
        };
        return recur(root,0);
    }
};