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
    ListNode* deleteMiddle(ListNode* head) {
        int l=0;
        ListNode*temp=head;
        while(temp)
        {
            l++;
            temp=temp->next;
        }
        if(l==1)
        return nullptr;
        
        int k=l/2;
        ListNode*slow=head;
        ListNode*prev=nullptr;
        
        for(int i=0;i<k;i++)
        prev=slow,slow=slow->next;
        
        prev->next=slow->next;
        return head;
        
    }
};