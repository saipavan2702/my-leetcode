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
    TreeNode* addOneRow(TreeNode* root, int val, int d) {
        if(d==1)
        {
            TreeNode*head=new TreeNode(val);
            head->left=root;
            return head;
        }
            
        int lvl=1;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int n;
            n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode*curr=q.front();
                q.pop();
                if(lvl!=d-1)
                {
                    if(curr->left)
                    q.push(curr->left);
                    if(curr->right)
                    q.push(curr->right);
                }
                else
                {
                    TreeNode*l=new TreeNode(val);
                    l->left=curr->left;
                    curr->left=l;
                    
                    TreeNode*r=new TreeNode(val);
                    r->right=curr->right;
                    curr->right=r;
                }
            }
            lvl++;
        }
        return root;
        
    }
};