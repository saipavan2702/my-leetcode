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
    int agg(TreeNode*point,int&res)
    {
        if(!point)
        return 0;
        
        res++;
        int ls=agg(point->left,res);
        int rs=agg(point->right,res);
        return (ls+rs+point->val);
    }
    void preorder(TreeNode*node,int&cnt)
    {
        if(!node)
        return;
        
        int res=0;
        int avg=(agg(node,res))/res;
        if(avg==node->val)
        cnt++;
        preorder(node->left,cnt);
        preorder(node->right,cnt);
        
    }
    int averageOfSubtree(TreeNode* root) {
        int cnt=0;
        preorder(root,cnt);
        return cnt;
    }
};