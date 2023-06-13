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
    vector<int> distanceK(TreeNode* root, TreeNode* t, int k) {
        using T=TreeNode*;
        unordered_map<T,T>hash;
        unordered_map<T,bool>vis;
        vector<int>go;

        function<void(T,T)>assign=[&](T parent, T node){
            if(!node)
            return;

            hash[node]=parent;
            assign(node,node->left);
            assign(node,node->right);
        };

        function<void(T,int)>recur=[&](T node, int k){
            if(vis[node] || !node)
            return;

            vis[node]=1;
            if(k==0){
                go.push_back(node->val);return;
            }
            recur(node->left,k-1);
            recur(node->right,k-1);
            if(hash[node])
            recur(hash[node],k-1);

        };
        assign(nullptr,root);
        recur(t,k);
        return go;
    }
};