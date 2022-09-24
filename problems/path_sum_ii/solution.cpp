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
    vector<vector<int>>ans;
    void recur(TreeNode*node,vector<int>&res,int t)
    {
        if(!node)
        return;
        
         res.push_back(node->val);
        if(!node->left and !node->right and t==node->val)
        ans.push_back(res);
        
       recur(node->left,res,t-node->val);
       recur(node->right,res,t-node->val);
       res.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int t) {
        vector<int>res;
        recur(root,res,t);
        return ans;
    }
};