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
    ListNode* swapNodes(ListNode* head, int k) {
        int n=0;
        using LL=ListNode*;
        LL temp=head;
        while(temp){
            temp=temp->next;
            n++;
        }

        LL hlo=head;
        int i=1;
        while(i<k){
            hlo=hlo->next;
            i++;
        }

        i=1;
        LL hi=head;
        while(i<=n-k){
            hi=hi->next;
            i++;
        }
        swap(hi->val,hlo->val);
        return head;
    }
};