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
    void fill(TreeNode*node,TreeNode*prev,unordered_map<TreeNode*,TreeNode*>&freq)
    {
        if(!node)
        return;
        
        freq[node]=prev;
        fill(node->left,node,freq);
        fill(node->right,node,freq);
    }
    int amountOfTime(TreeNode* root, int start) {
        TreeNode*t;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode*curr=q.front();
            q.pop();
            if(curr->left)
            q.push(curr->left);
            if(curr->right)
            q.push(curr->right);
            
            if(curr->val==start)
            t=curr;
        }
        unordered_map<TreeNode*,TreeNode*>freq;
        fill(root,nullptr,freq);
        q.push(t);
        int cnt=0;
        unordered_map<TreeNode*,bool>vis;
        vis[t]=1;
        while(!q.empty())
        {
            int n;
            n=q.size();
            for(int i=0;i<n;i++)
            {
              TreeNode*curr=q.front();
              q.pop();
              if(curr->left and !vis[curr->left])
              {
               q.push(curr->left);
               vis[curr->left]=1;
              }
              if(curr->right and !vis[curr->right])
              {
               q.push(curr->right);
               vis[curr->right]=1;
              }
              if(freq[curr] and !vis[freq[curr]])
              {
               q.push(freq[curr]);
               vis[freq[curr]]=1;
              }
            }
            cnt++;
        }
        return cnt-1;
        
    }
};