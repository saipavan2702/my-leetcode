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
    map<int,vector<int>>freq;
    vector<vector<int>>ans;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(!root)
        return ans;
        
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty())
        {
            int n;
            n=q.size();
            multiset<pair<int,int>>st;
            for(int i=0;i<n;i++)
            {
                auto curr=q.front();
                q.pop();
                st.insert({curr.first->val,curr.second});
                if(curr.first->left)
                q.push({curr.first->left,curr.second-1});
                if(curr.first->right)
                q.push({curr.first->right,curr.second+1});
            }
            for(auto x:st)
            {
                freq[x.second].push_back(x.first);
            }
        }
        for(auto x:freq)
        {
            ans.push_back(x.second);
        }
        return ans;
        
    }
};