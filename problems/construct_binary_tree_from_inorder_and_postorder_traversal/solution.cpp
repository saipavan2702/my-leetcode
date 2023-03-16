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
    using N=TreeNode*;
    using vi=vector<int>;

    N recur(vi &in, int x, int y, vi &post, int s, int e){
        if(x>y or s>e)
        return nullptr;

        N node=new TreeNode(post[e]);
        int Idx=x;

        while(node->val!=in[Idx])
        Idx++;

        node->left=recur(in,x,Idx-1,post,s,s+Idx-x-1);
        node->right=recur(in,Idx+1,y,post,s+Idx-x,e-1);
        return node;

    }
    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int n=in.size();
        return recur(in,0,n-1,post,0,n-1);;
    }
};