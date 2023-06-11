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
    ListNode* deleteDuplicates(ListNode* head) {
        using L=ListNode*;
        L baka=new ListNode();
        baka->next=head;
        L prev=baka;

        while(head){
            if(head->next && head->val==head->next->val){
                while(head && head->next && head->val==head->next->val){
                    head=head->next;
                }
                prev->next=head->next;
            }
            else
            prev=prev->next;
            
            head=head->next;
        }
        return baka->next;
    }
};