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
    void recur(TreeNode*node, vector<int>&res) {
        if(!node)
        return;

        recur(node->left,res);
        res.push_back(node->val);
        recur(node->right,res);
    }
    int minDiffInBST(TreeNode* root) {
        if(!root)
        return 0;

        vector<int>res;
        recur(root,res);

        int n=res.size();
        int diff=1e9;

        for(int i=0;i<n-1;i++)
        diff=min(diff,res[i+1]-res[i]);
        
        return diff;
    }
};