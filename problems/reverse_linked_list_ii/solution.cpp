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
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode**dict=&head;
        int k=left;
        while(k!=1 and dict)
        {
            dict=&(*dict)->next;
            k--;
        }
        ListNode*fast=*dict;
        for(int i=left;i<right;i++)
        {
            swap(*dict,fast->next->next);
            swap(*dict,fast->next);
        }
        return head;
        
    }
};