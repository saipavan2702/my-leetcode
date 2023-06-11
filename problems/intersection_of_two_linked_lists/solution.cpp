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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        using L=ListNode*;
        //doing with lengths is usual
        if(!headA || !headB)
        return nullptr;

        L aho=headA;
        L baka=headB;

        while(aho!=baka){
            aho=(aho==nullptr)?headB:aho->next;
            baka=(baka==nullptr)?headA:baka->next;
        }

        return aho;

    }
};