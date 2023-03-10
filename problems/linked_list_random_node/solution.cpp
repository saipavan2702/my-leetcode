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
    vector<int>A;
    Solution(ListNode* head) {
        while(head){
            A.push_back(head->val);
            head=head->next;
        }
       srand(time(0));
    }
    
    int getRandom() {
        
        int n=size(A);
        int x=rand()%n;

        return A[x];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */