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
    ListNode* removeElements(ListNode* head, int val) {
        using L=ListNode*;
        if(!head)
        return nullptr;

        L baka=new ListNode();
        baka->next=head;
        L curr=baka;

        while(curr->next){
            if(curr->next->val==val){
                curr->next=curr->next->next;
            }
            else
            curr=curr->next;
        }
        return baka->next;
    }
};