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
    using T=TreeNode*;
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        unordered_map<T,int>par;
        par[nullptr]=-1;
        
        function<void(T,T)>assign=[&](T node, T parent){
            if(!node)
            return;

            par[node]=par[parent]+1;
            assign(node->left,node);
            assign(node->right,node);
        };
        assign(root,nullptr);
        int lvl=-1;
        for(auto x:par) lvl=max(lvl,x.second);
        cout<<lvl<<endl;
        
        function<T(T)>lca=[&](T node)->T{
            if(!node)return nullptr;
            if(par[node]==lvl)return node;

            T left=lca(node->left);
            T right=lca(node->right);

            if(!left && !right)return nullptr;
            return !left? right: !right? left:node;
        };
        return lca(root);
    }
};