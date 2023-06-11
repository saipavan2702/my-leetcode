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
    ListNode* removeZeroSumSublists(ListNode* head) {
        using L=ListNode*;

        map<int,L>freq;
        L baka=new ListNode(0,head);
        int pref=0;

        freq[pref]=baka;
        while(head){
            pref+=head->val;
            if(freq.count(pref)){
                L prev=freq[pref];
                L init=prev;

                int dup=pref;
                while(prev!=head){
                    prev=prev->next;
                    dup+=prev->val;

                    if(prev!=head)
                    freq.erase(dup);
                }
                init->next=head->next;
            }else freq[pref]=head;

            head=head->next;
        }
        return baka->next;
    }
};