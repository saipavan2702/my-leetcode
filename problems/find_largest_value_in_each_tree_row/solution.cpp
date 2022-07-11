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
        
        deque<TreeNode*>q;
        q.push_back(node);
        while(!q.empty())
        {
            int n,gt=INT_MIN;
            n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode*curr=q.front();
                q.pop_front();
                if(curr->val>gt)
                {
                    gt=curr->val;
                }
                if(curr->left)
                q.push_back(curr->left);
                if(curr->right)
                q.push_back(curr->right);
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