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
    using N=TreeNode*;
    int ans;
    void recur(N node, int s){
        if(!node)
        return;

        s*=10;
        s+=node->val;
        
        if(!node->left && !node->right)
        ans+=s;

        recur(node->left,s);
        recur(node->right,s);
        s-=node->val;
        s/=10;
    }
    int sumNumbers(TreeNode* root) {
        int s=0;
        ans=0;
        recur(root,s);
        return ans;
    }
};