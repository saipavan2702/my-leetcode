class Solution {
public:
    vector<string>ret;
    void dfs(int idx, int k, string ip, string s){
        int n=s.size();
        
        if(k==4){
            if(idx>=n){
                ip.pop_back();
                ret.push_back(ip);
            }
            return;
        }
        string res;
        for(int i=idx;i<n;i++){
            if(res=="0")
            return;

            res=res+s[i];
            if(stoi(res)>=0 && stoi(res)<=255){
                string it=ip;
                ip=ip+res+".";
                dfs(i+1, k+1, ip, s);
                ip=it;
            }
            else if(stoi(res)>255)
            return;
        }

    }
    vector<string> restoreIpAddresses(string s) {
       dfs(0,0,"",s);
       return ret;
    }
};