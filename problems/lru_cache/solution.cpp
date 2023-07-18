class LRUCache {
public:
    class node{
        public:
        int key;
        int val;

        node*next;
        node*prev;
        node(int key, int val){
            this->key=key;
            this->val=val;
        }
    };

    unordered_map<int,node*>lru;
    int cap;

    node *head=new node(-1,-1);
    node *tail=new node(-1,-1);
    LRUCache(int cap) {
        this->cap=cap;
        head->next=tail;
        tail->prev=head;
    }

    void add(node*curr){
        curr->next=head->next;
        head->next->prev=curr;
        head->next=curr;
        curr->prev=head;
        lru[curr->key]=curr;
    }

    void sub(node*curr){
        lru.erase(curr->key);
        curr->next->prev=curr->prev;
        curr->prev->next=curr->next;

    }
    
    int get(int key) {
        if(lru.find(key)==lru.end())return -1;

        node*curr=lru[key];
        sub(curr);
        add(curr);
        return curr->val;
    }
    
    void put(int key, int value) {
        if(lru.find(key)!=lru.end()) sub(lru[key]);
        if(lru.size()==cap) sub(tail->prev);
        add(new node(key,value));
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */