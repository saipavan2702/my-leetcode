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
    using T=TreeNode*;
    int minDepth(TreeNode* root) {
        queue<pair<T,int>>q;
        if(!root)
        return 0;
        
        q.push({root,1});

        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto node=q.front();
                q.pop();

                if(!node.first->left and !node.first->right)
                return node.second;

                if(node.first->left)
                q.push({node.first->left,node.second+1});

                if(node.first->right)
                q.push({node.first->right,node.second+1});
            }
        }
        return 2;
    }
};