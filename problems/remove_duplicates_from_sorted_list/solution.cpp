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

        L curr=head;
        L prev=new ListNode();
        prev->next=curr;

        while(curr){
            if(curr->next && curr->val==curr->next->val){
                while(curr && curr->next && curr->val==curr->next->val ){
                    curr->next=curr->next->next;
                }
            }
            else
            curr=curr->next;
        }
        return prev->next;
    }
};