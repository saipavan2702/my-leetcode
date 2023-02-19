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
        if(!root)
        return {};

        vector<vector<int>>Q;
        queue<TreeNode*>q;
        bool h=0;

        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int>I(n);

            for(int i=0;i<n;i++) {
                auto node=q.front();
                q.pop();

                if(!h)
                I[i]=node->val;
                else
                I[n-i-1]=node->val;

                if(node->left)
                q.push(node->left);
                if(node->right)
                q.push(node->right);
            }
            Q.push_back(I);
            h=!h;
        }
        return Q;
        
    }
};