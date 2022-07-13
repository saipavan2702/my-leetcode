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
    int maxd(TreeNode*node)
    {
        if(!node)
        return 0;
        queue<TreeNode*>q;
        q.push(node);
        int ans=0;
        while(!q.empty())
        {
            int n;
            n=q.size();
            ans++;
            for(int i=0;i<n;i++)
            {
                TreeNode*curr=q.front();
                q.pop();
                if(curr->left)
                q.push(curr->left);
                if(curr->right)
                q.push(curr->right);
                
            }
        }
        return ans;
    }
    int maxDepth(TreeNode* root) {
        int x;
        x=maxd(root);
        return x;
    }
};