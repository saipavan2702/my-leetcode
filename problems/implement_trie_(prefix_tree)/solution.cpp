class Node{
    public:
    Node* dict[26];
    bool have=false;
};

class Trie {
public:
    Node* node;
    Trie() {
        node=new Node();
    }
    
    void insert(string s) {
        Node* data=node;

        int n=size(s);
        for(int i=0;i<n;i++){
            if(data->dict[s[i]-'a']==nullptr)
            data->dict[s[i]-'a']=new Node();

            data=data->dict[s[i]-'a'];
        }
        data->have=true;
    }
    
    bool search(string s) {
        Node* data=node;
        int n=size(s);

        for(int i=0;i<n;i++){
            if(data->dict[s[i]-'a']==nullptr)
            return 0;

            data=data->dict[s[i]-'a'];
        }
        return data->have;
    }
    
    bool startsWith(string s) {
         Node* data=node;
        int n=size(s);

        for(int i=0;i<n;i++){
            if(data->dict[s[i]-'a']==nullptr)
            return 0;

            data=data->dict[s[i]-'a'];
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */