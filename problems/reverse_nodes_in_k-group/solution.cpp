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
    using L=ListNode*;
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head)
        return nullptr;

        L dup=head;
        for(int i=0;i<k;i++){
            if(!dup)
            return head;
            dup=dup->next;
        }

        L curr=head;
        L prev=nullptr;
        L nxt=nullptr;
        int cn=0;


        while(curr && cn++<k){
            nxt=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nxt;
        }
        
        if(nxt)
        head->next=reverseKGroup(nxt,k);

        return prev;
    }
};