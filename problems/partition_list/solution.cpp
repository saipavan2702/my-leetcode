/**
 * Definition for singly-linked list.
 * struct L {
 *     int val;
 *     L *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, L *next) : val(x), next(next) {}
 * };
 */
class Solution {
    public:
     ListNode* partition(ListNode* head, int x) {
        using L=ListNode*;

        L left = new ListNode(0);
        L right = new ListNode(0);
        
        L leftTail = left;
        L rightTail = right;
        
        while(head){
            if(head->val < x){
                leftTail->next = head;
                leftTail = leftTail->next;
            }
            else{
                rightTail->next = head;
                rightTail = rightTail->next;
            }
            head = head->next;
        }
        
        leftTail->next = right->next;
        rightTail->next = nullptr;
        
        return left->next;
    }
};