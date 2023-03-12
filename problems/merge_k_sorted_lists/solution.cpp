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
    using vi=vector<int>;

    void create(ListNode**node, int v){
        ListNode* need=new ListNode(v);
        need->next=*node;
        *node=need;
    }
    ListNode* mergeKLists(vector<ListNode*>& lst) {
        ListNode*node=nullptr;
        for(auto x:lst){
            while(x){
                create(&node,x->val);
                x=x->next;
            }
        }
        vi a;
        auto root=node;
        while(root){
            a.push_back(root->val);
            root=root->next;
        }
        sort(begin(a),end(a));
        int n=size(a);

        ListNode*h=nullptr;
        for(int i=n-1;i>=0;i--){
            create(&h,a[i]);
        }
        return h;
    }
};