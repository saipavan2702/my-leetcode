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
    void dfs(TreeNode*node,vector<int>&res)
    {
         if(!node)
         return ;
        
        queue<TreeNode*>q;
        q.push(node);
        while(!q.empty())
        {
            int n,gt=INT_MIN;
            n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode*curr=q.front();
                q.pop();
                if(curr->val>gt)
                {
                    gt=curr->val;
                }
                if(curr->left)
                q.push(curr->left);
                if(curr->right)
                q.push(curr->right);
            }
            res.push_back(gt);
        }
    }
    vector<int> largestValues(TreeNode* root) {
        vector<int>res;
        dfs(root,res);
        return res;
    }
};