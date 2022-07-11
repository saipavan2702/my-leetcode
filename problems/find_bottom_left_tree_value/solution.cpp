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
    void bsl(TreeNode*node,vector<int>&res)
    {
        queue<TreeNode*>q;
        q.push(node);
        while(!q.empty())
        {
            int n;n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode*curr=q.front();
                q.pop();
                if(i==0)
                {
                    res.push_back(curr->val);
                }
                if(curr->left)
                q.push(curr->left);
                if(curr->right)
                q.push(curr->right);
            }
        }
    }
    int findBottomLeftValue(TreeNode* root) {
        vector<int>res;
        bsl(root,res);
        return res.back();
    }
};