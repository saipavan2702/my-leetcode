class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        
        int n=size(chars);
        unordered_map<char,int>dict;
        for(int i=0;i<n;i++){
            dict[chars[i]]=vals[i];
        }
        
        int nas=INT_MIN;
        int curr=0;
        for(auto &x:s){
            
            nas=max(nas,curr);
            
            if(dict.count(x)){
                curr+=dict[x];
            }
            else{
                curr+=((x-'a')+1);
            }
            
            if(curr<0)
            curr=0;
        }
        nas=max(nas,curr);
        return nas;
    }
};