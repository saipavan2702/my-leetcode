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
    void rsv(TreeNode*node,vector<int>&res)
    {
        if(!node)
        return ;
        
        queue<TreeNode*>q;
        q.push(node);
        while(!q.empty())
        {
            int n;
            n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode*curr=q.front();
                q.pop();
                if(i==0)
                {
                    res.push_back(curr->val);
                }
                if(curr->right)
                q.push(curr->right);
                if(curr->left)
                q.push(curr->left);
            }
        }
        
        
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        rsv(root,res);
        return res;
    }
};