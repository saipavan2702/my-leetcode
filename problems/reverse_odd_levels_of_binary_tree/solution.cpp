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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<int>a;
        int cnt=0;
        while(!q.empty())
        {
            int n;
            n=q.size();
            vector<int>b;
            for(int i=0;i<n;i++)
            {
                TreeNode*curr=q.front();
                q.pop();
                
                if(cnt&1)
                curr->val=a[n-i-1];
                
                if(curr->left)
                {
                 q.push(curr->left);
                 b.push_back(curr->left->val);
                }
                if(curr->right)
                {
                 q.push(curr->right);
                 b.push_back(curr->right->val);
                }
            }
            a=b;
            cnt++;
        }
        return root;
    }
};