/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool fill(TreeNode*node,TreeNode*x,vector<TreeNode*>&res)
    {
        if(!node)
        return 0;
        res.push_back(node);
        if(node->val==x->val)
        return 1;
        
        if(fill(node->left,x,res) or fill(node->right,x,res))
        return 1;
        
        res.pop_back();
        return 0;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
        return nullptr;
        vector<TreeNode*>l,r;
        fill(root,p,l);
        fill(root,q,r);
        int n=min(l.size(),r.size());
        TreeNode* ans;
        for(int i=0;i<n;i++)
        {
            if(l[i]==r[i])
            ans=l[i];
            else
            break;
        }
        return ans;
    }
};