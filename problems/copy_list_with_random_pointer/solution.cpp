/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*,Node*>List;
        Node*curr=head;
        while(curr){
            List[curr]=new Node(curr->val);
            curr=curr->next;
        }
        curr=head;
        while(curr){
            List[curr]->next=List[curr->next];
            List[curr]->random=List[curr->random];
            curr=curr->next;
        }
        return List[head];
    }
};