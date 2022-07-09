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
    TreeNode*postorder(TreeNode*&root)
    {
        if(!root)
        return nullptr;
        
        root->left=postorder(root->left);
        root->right=postorder(root->right);
        if(root->left and root->right)
        {
            int l=root->left->val;
            int r=root->right->val;
            if(root->val==2)
            {
                root= new TreeNode(l or r);
            }
            else if(root->val==3)
            {
                root=new TreeNode(l and r);
            }  
        }
        return root;
    }
    bool evaluateTree(TreeNode* root) {
        if(!root)
        return 0;
        
        postorder(root);
        return root->val;
    }
};