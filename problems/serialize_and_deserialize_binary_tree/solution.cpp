/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    using T=TreeNode*;

    void serialise(T node, ostringstream& oss){
        if(!node){
            oss<<"# ";
            return;
        }

        oss<<node->val<<" ";
        serialise(node->left,oss);
        serialise(node->right,oss);
    }

    T deserialise(istringstream& iss){
        string s;
        iss>>s;

        if(s=="#")
        return nullptr;

        T node = new TreeNode(stoi(s));
        node->left=deserialise(iss);
        node->right=deserialise(iss);
        return node;
    }

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream oss; //writes uses << op same as cout<<
        serialise(root,oss);
        return oss.str(); //set content
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data); // reads >> data same cin>>
        return deserialise(iss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));