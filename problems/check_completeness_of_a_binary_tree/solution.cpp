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
    bool check(TreeNode*point,int i,int k)
{
   if(point==NULL)
   {
       return true;
   }
   if(i>=k)
   {
       return false;
   }
   return(check(point->left,2*i+1,k) and check(point->right,2*i+2,k));
}
int count(TreeNode*node)
{
   if(node==NULL)
   {
       return 0;
   }
  return(1+count(node->left)+count(node->right));
   
}
    bool isCompleteTree(TreeNode* root) {
         if(root==NULL)
    {
        return 1;
    }
 int k=count(root);
 
 int i=0;
 return check(root,i,k);
    }
};