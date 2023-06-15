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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string,int>hash;
        vector<T>have;

        function<string(T)>recur=[&](T node)->string{
            if(!node)
            return "#";

            auto L=recur(node->left);
            auto R=recur(node->right);

            auto s="*"+L+to_string(node->val)+R+"*";
            if(++hash[s]==2)
                have.push_back(node);
            
            return s;
        };
        recur(root);
        return have;
    }
};