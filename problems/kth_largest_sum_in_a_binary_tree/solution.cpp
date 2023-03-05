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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(!root)
            return 0;
        
        queue<TreeNode*>q;
        q.push(root);
        priority_queue<long long>pq;
        int cnt=0;
        while(!q.empty()){
            int sz;
            sz=q.size();
            long long ans=0;
            for(int i=0;i<sz;i++){
                auto x=q.front();
                q.pop();
                
                if(x->left)
                    q.push(x->left);
                if(x->right)
                    q.push(x->right);
                
                ans+=x->val;
            }
            pq.push(ans);
            cnt++;
        }
        if(k>cnt)
            return -1;
        
        long long need=0;
        for(int i=1;i<=k;i++){
            need=pq.top();
            pq.pop();
        }
        return need;
    }
};