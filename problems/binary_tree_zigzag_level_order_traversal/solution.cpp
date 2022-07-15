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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>>ans;
    if(!root)
    return ans;

    bool flag;
    flag=1;
   queue<TreeNode*>q;
   q.push(root);
   while(!q.empty())
   {
        int n;n=q.size();
        vector<int>res(n);
       for(int i=0;i<n;i++)
       {
         TreeNode*curr=q.front();
         q.pop();

         if(flag)
         res[i]=curr->val;
         else
         res[n-1-i]=curr->val;

         if(curr->left)
         q.push(curr->left);
         if(curr->right)
         q.push(curr->right);
       }
      ans.push_back(res);
       flag=!flag;
   }
    return ans;
    }
};