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
    void lot(TreeNode*node, vector<vector<int>>&res)
    {
        if(!node)
        return;
        queue<TreeNode*>q;
        q.push(node);
        while(!q.empty())
        {
            int n;n=q.size();
            vector<int>s;
            for(int i=0;i<n;i++)
            {
                TreeNode*curr=q.front();
                
                s.push_back(q.front()->val);
                q.pop();
                if(curr->left)
                q.push(curr->left);
                if(curr->right)
                q.push(curr->right);
            }
            res.push_back(s);
        }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        lot(root,res);
        return res;
    }
};