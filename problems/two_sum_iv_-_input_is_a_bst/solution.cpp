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
    bool recur(TreeNode*node,int k,unordered_map<int,int>&freq)
    {
        if(!node)
        return 0;
        
        int curr=node->val;
        if(freq.count(k-curr))
            return 1;
        
        freq[curr]++;
        
        return recur(node->left,k,freq) || recur(node->right,k,freq);
    }
    bool findTarget(TreeNode* root, int k) {
      unordered_map<int,int>freq;
      return recur(root,k,freq);
    }
};