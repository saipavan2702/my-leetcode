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
class Solution {
public:
    using LL=ListNode*;
    ListNode* swapPairs(ListNode* head) {
        if(!head)
        return nullptr;

        if(!head->next)
        return head;
        
        LL node=head;
        swap(node->val,node->next->val);
        swapPairs(node->next->next);
        return node;
    }
};