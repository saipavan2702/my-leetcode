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
    ListNode*reverse(ListNode*book)
{
   ListNode*data=book;
   ListNode*prev=NULL;
   ListNode*pro=NULL;
   while(data)
   {
    pro=data->next;
    data->next=prev;
    prev=data;
    data=pro;
   }
   return prev; 
}
    bool isPalindrome(ListNode* node) {
        if(!node)
    return 1;

    ListNode*slow=node;
    ListNode*fast=node;
    while(fast and fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    ListNode*half=reverse(slow);

    ListNode*curr=node;
    while(curr and half)
    {
        if(curr->val!=half->val)
        return 0;

        curr=curr->next;
        half=half->next;
    }
    return 1;
    }
};