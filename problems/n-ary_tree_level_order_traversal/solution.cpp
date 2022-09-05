/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
     vector<vector<int>>ans;
    vector<vector<int>> levelOrder(Node* root) {
        if(!root)
        return ans;
       
        queue<Node*>q;
        q.push(root);
        while(!q.empty())
        {
            int n;
            n=q.size();
            vector<int>res;
            for(int i=0;i<n;i++)
            {
                Node*curr=q.front();
                q.pop();
                res.push_back(curr->val);
                for(auto x:curr->children)
                    q.push(x);
            }
            ans.push_back(res);
        }
        return ans;
        
    }
};