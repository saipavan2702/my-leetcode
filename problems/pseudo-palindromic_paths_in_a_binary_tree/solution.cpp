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
    int cnt=0;
    void recur(TreeNode*node,int res[])
    {
        if(!node)
        return;
    
        res[node->val]++;
        if(!node->left and !node->right)
        {
            int z=0;
            for(int i=0;i<10;i++)
            {
                if(res[i]&1)
                z++;
            }
            if(z<=1)
            cnt++;
        }
        recur(node->left,res);
        recur(node->right,res);
        res[node->val]--;
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int res[10]={0};
        recur(root,res);
        return cnt;
    }
};