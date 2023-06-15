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
    int maxLevelSum(TreeNode* root) {
        queue<T>q;
        int hi=-1e9,cn=0,lvl=0;

        q.push(root);
        while(!q.empty()){
            int sz=q.size();
            int local=0;
            cn++;
            while(sz--){
                auto node=q.front();
                local+=node->val;
                q.pop();

                if(node->left)
                q.push(node->left);
                
                if(node->right)
                q.push(node->right);

            }
            if(hi<local)
            hi=local,lvl=cn;
        }
        return lvl;
    }
};