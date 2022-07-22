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
     void create(ListNode**point,int l)
 {
    ListNode*curr=new ListNode(l);
    curr->next=*point;
    *point=curr;
 }
    ListNode* partition(ListNode* head, int k) {
        if(!head)
   return 0;

   ListNode*temp=head;
   vector<int>res;
   while(temp!=NULL)
   {
       if(temp->val<k)
       res.push_back(temp->val);
       temp=temp->next;
   }
   /*temp=head;
   while(temp!=NULL)
   {
       if(temp->val==k)
       res.push_back(temp->val);
       temp=temp->next;
   }*/
   temp=head;
   while(temp!=NULL)
   {
       if(temp->val>=k)
       res.push_back(temp->val);
       temp=temp->next;
   }
   ListNode*book=NULL;
   for(int i=res.size()-1;i>=0;i--)
    create(&book,res[i]);

   return book;
    }
};