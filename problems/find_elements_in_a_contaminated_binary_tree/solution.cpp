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
class FindElements {
public:
    unordered_set<int>st;

    FindElements(TreeNode* root) {
        using T=TreeNode*;
        function<T(T,int)>recur=[&](T node, int curr)->T{
            if(!node)
            return nullptr;

            node->val=curr;
            st.insert(node->val);
            node->left=recur(node->left,2*node->val+1);
            node->right=recur(node->right,2*node->val+2);
            
            return node;
        };
        recur(root,0);
    }
    
    bool find(int target) {
        return st.find(target)!=st.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */