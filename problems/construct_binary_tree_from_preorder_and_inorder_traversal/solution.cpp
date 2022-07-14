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
TreeNode*create(vector<int>& pre,vector<int>& in,int ins,int ine,int pres,int pree)
{
    if(ins>ine)
    return nullptr;
    int rval=pre[pres];
    int idx=-1;
    for(int i=ins;i<=ine;i++)
    {
        if(in[i]==rval)
        {idx=i;
        break;}
    }
    int lins=ins;
    int line=idx-1;
    int rins=idx+1;
    int rine=ine;
    int lpres=pres+1;
    int lpree=line-lins+lpres;
    int rpres=lpree+1;
    int rpree=pree;
    TreeNode*root=new TreeNode(rval);
    root->left=create(pre,in,lins,line,lpres,lpree);
    root->right=create(pre,in,rins,rine,rpres,rpree);
    return root;
    
}
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        int n;n=pre.size();
        return create(pre,in,0,n-1,0,n-1);
    }
};