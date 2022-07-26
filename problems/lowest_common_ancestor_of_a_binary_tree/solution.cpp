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
    vector<TreeNode*>l,r;
    bool check(TreeNode*root,TreeNode* x,vector<TreeNode*>&res)
    {
        if(!root)
        return 0;
        
        res.push_back(root);
        if(root->val==x->val)
        return 1;
        
        
        if(check(root->left,x,res) or check(root->right,x,res))
        return 1;
        
        res.pop_back();
        return 0;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         if(!root)
        return nullptr;
        
        
        check(root,p,l);
        check(root,q,r);
        
        int n=min(l.size(),r.size());
        TreeNode* cnt;
        for(int i=0;i<n;i++)
        {
            if(l[i] == r[i])
            cnt = l[i];
            
            else
            break;
        }
        return cnt;
        
    }
};