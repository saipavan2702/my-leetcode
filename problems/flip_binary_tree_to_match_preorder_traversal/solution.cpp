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
    int i=0;
    bool dfs(TreeNode*node, vector<int>&pre,vector<int>&res)
    {
        if(!node)
        return 1;
        if(node->val!=pre[i++])
        return 0;
        if(node->left and node->left->val!=pre[i])
        {
            if(node->right and node->right->val==pre[i])
            {
                res.push_back(node->val);
                swap(node->right,node->left);
            }
            else
            return 0;
        }
        return dfs(node->left,pre,res) and dfs(node->right,pre,res);
    }
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>&pre) {
        vector<int>res;
        return dfs(root,pre,res)?res:vector<int>()={-1};
    }
};