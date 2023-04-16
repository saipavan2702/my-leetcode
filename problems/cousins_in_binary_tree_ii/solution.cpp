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
    TreeNode* replaceValueInTree(TreeNode* root) {
        root->val=0;
        
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            
            vector<TreeNode*>can;
            int curr=0;
            for(int i=0;i<n;i++){
                auto node=q.front();
                q.pop();
                
                can.push_back(node);
                if(node->left){
                    q.push(node->left);
                    curr+=node->left->val;
                }
                if(node->right){
                    q.push(node->right);
                    curr+=node->right->val;
                }
            }
            
            for(auto&x:can){
                int have=curr;
                
                if(x->left)
                    have-=x->left->val;
                if(x->right)
                    have-=x->right->val;
                
                if(x->left)
                    x->left->val=have;
                if(x->right)
                    x->right->val=have;
            }
        }
        return root;
        
    }
};