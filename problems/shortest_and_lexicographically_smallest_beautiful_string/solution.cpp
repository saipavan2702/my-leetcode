class Solution {
public:
    static bool use(const string a, const string b){
       return a.size()<b.size();
    }
    string shortestBeautifulSubstring(string s, int k) {

        int n=s.size();
        int i,j=0;
        
        unordered_map<char,int>freq;
        vector<string>ref;
        for(i=0;i<n;i++){
            freq[s[i]]++;
            
            while(j<n and freq['1']>k){
                freq[s[j]]--;
                j++;
            }
            while(j<n and freq['1']==k){
                if(s[j]=='1') break;
                freq[s[j]]--;
                j++;
            }
            if(freq['1']==k) ref.push_back(s.substr(j,i-j+1));
        }
        
        sort(ref.begin(),ref.end(),use);
        if(ref.empty()) return "";
        
        string ans=ref[0];
        for(int i=1;i<ref.size();i++){
            if(ref[i].size()==ans.size()){
               ans=min(ans,ref[i]);
            }
        }
        
        return ans;
    }
};