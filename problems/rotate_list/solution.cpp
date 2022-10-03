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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or k==0)
        return head;
        
        int l=0;
        ListNode*slow=head;
        while(slow)
        {
            slow=slow->next;
            l++;
        }
        k=k%l;
        if(k==l or k==0)
        return head;
        
        ListNode*fast=head;
        ListNode*res=head;
        int n=l-k-1;
        for(int i=0;i<n;i++)
        res=res->next;
        
        while(fast->next)
        fast=fast->next;
        
        ListNode*node;
        node=res->next;
        res->next=nullptr;
        fast->next=head;
        
        return node;
    }
};