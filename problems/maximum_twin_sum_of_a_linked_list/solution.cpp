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
    int pairSum(ListNode* head) {
        stack<int>st;
        using LL=ListNode*;
        LL node=head;

        int n=0;
        while(node){
            node=node->next;
            n++;
        }

        node=head;
        for(int i=0;i<n/2;i++){
            st.push(node->val);
            node=node->next;
        }

        int ans=INT_MIN;
        for(int i=n/2;i<n;i++){
            ans=max(ans,st.top()+node->val);
            node=node->next;
            st.pop();
        }
        return ans;
    }
};