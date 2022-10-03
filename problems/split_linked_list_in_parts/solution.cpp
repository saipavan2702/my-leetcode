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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*>ans(k);
        int l=0;
        ListNode*slow=head,*prev=nullptr;;
        while(slow)
        {
            slow=slow->next;
            l++;
        }
        int x=l/k;
        int y=l%k;
        
        for(int i=0;i<k;i++)
        {
            ans[i]=head;
            for(int j=0;j<x+(i<y);j++)
            {
                prev=head;
                head=head->next;
            }
            if(prev)
            prev->next=nullptr;
        }
        return ans;
    }
};