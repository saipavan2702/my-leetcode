/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    /*
      case_0: node not monitored
      case_1: node is monitored but no camera
      case_2: node has camera
    */
    using T=TreeNode*;
    using vi=vector<int>;

    int minCameraCover(TreeNode* root) {
        function<vi(T)>recur=[&](T node){
            if(!node)
            return vi{0,0,9999};

            vi lC=recur(node->left);
            vi rC=recur(node->right);

            int choiceL=min(lC[1],lC[2]);
            int choiceR=min(rC[1],rC[2]);

            int case_0=lC[1]+rC[1];
            int case_1=min(lC[2]+choiceR,rC[2]+choiceL);
            int case_2=1+min(choiceL,lC[0])+min(choiceR,rC[0]);

            return vi{case_0, case_1, case_2};
        };
        vi go=recur(root);
        return min(go[1],go[2]);
    }
};