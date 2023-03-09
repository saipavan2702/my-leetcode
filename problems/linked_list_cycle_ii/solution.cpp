/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        auto slow=head;
        auto fast=head;
        auto node=head;

        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow){
                while(fast!=node){
                    fast=fast->next;
                    node=node->next;
                }
                return node;
            }
        }
        return nullptr;
    }
};