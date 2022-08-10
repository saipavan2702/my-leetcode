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
    TreeNode*create(vector<int>&nums,int lo,int hi)
    {
        if(lo>hi)
        return nullptr;
        
        int mid=(lo+hi)/2;
        TreeNode*node=new TreeNode(nums[mid]);
        node->left=create(nums,lo,mid-1);
        node->right=create(nums,mid+1,hi);
        
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n;
        n=nums.size();
        return create(nums,0,n-1);
    }
};