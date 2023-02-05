class Solution {
public:
    bool check(int freq[],int count[]){
        for(int i=0;i<26;i++){
            if(freq[i]!=count[i])
            return 0;
        }
        return 1;
    }
    vector<int> findAnagrams(string s, string p) {
        int q=p.size();
        int n=s.size();

        int freq[26]={0};

        for(auto &x:p)
        freq[x-'a']++;

        vector<int>u;
        int count[26]={0};
        for(int i=0;i<n;i++){
            count[s[i]-'a']++;
            if(i>=q)
            count[s[i-q]-'a']--;

            if(check(count,freq))
            u.push_back(i-q+1);
        }
        return u;
    }
};