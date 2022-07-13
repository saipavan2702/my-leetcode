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
    void scnt(TreeNode*node,int&res,unordered_map<int,int>&freq,int k,long long int sus)
  {
    if(!node)
    return;
    
    sus+=node->val;
    //cout<<sus;
    res+=freq[sus-k];
    freq[sus]++;
    scnt(node->left,res,freq,k,sus);
    scnt(node->right,res,freq,k,sus);
    freq[sus]--;
 }
    int pathSum(TreeNode* root, int targetSum) {
        int res=0;
    unordered_map<int,int>freq;
    freq[0]=1;
    scnt(root,res,freq,targetSum,0);
    return res;
    }
};