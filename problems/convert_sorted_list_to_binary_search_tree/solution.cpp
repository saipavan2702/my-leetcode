/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    using vi=vector<int>;
    TreeNode* recur(int lo, int hi,vi&a){
        if(lo>hi)
        return nullptr;

        int u=(lo+hi)/2;
        auto node= new TreeNode(a[u]);
        node->left=recur(lo,u-1,a);
        node->right=recur(u+1,hi,a);

        return node;

    }
    TreeNode* sortedListToBST(ListNode* head) {
        vi a;
        while(head){
            a.push_back(head->val);
            head=head->next;
        }
        int n=size(a);
        return recur(0,n-1,a);
    }
};