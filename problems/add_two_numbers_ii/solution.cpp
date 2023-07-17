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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        using L=ListNode*;
        function<L(L)>reverse=[&](L node)->L{
            if(!node)return NULL;

            L prev=NULL;
            L data=node;
            
            while(data){
                L nex=data->next;
                data->next=prev;
                prev=data;
                data=nex;
            }
            return prev;
        };
        L u=reverse(l1);
        L v=reverse(l2);

        int carry=0;
        int k=0;
        L baka=new ListNode(-1);
        L node=baka;
        while(u or v){
            int x=0,y=0;
            if(u)x=u->val;
            if(v)y=v->val;

            int cur=(x+y+carry)%10;
            carry=(x+y+carry)/10;
            node->next=new ListNode(cur);
            node=node->next;

            if(u)u=u->next;
            if(v)v=v->next;
        }
        if(carry){
            node->next=new ListNode(carry);
        }

        return reverse(baka->next);
    }
};