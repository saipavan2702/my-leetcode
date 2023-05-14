class Solution {
public:
    bool doesValidArrayExist(vector<int>& de) {
        int n=de.size();
//         vector<int>OG(n);
//         OG[0]=de[0];
        
//         for(int i=1;i<n;i++){
//             if(i==n-1)
//                 OG[i]=de[i]^OG[0];
//             else
//             OG[i]=de[i-1]^OG[i-1];
//         }
        
        int ans=de[0];
        for(int i=1;i<n;i++){
            ans^=de[i];
        }
        return ans==0;
        
    }
};