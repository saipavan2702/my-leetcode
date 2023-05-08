class Solution {
public:
    using vi=vector<int>;
    vector<int> colorTheArray(int n, vector<vector<int>>& Q) {
        vi pre(n,0);
        vi ans;

        int c=0;
        for(auto x:Q){
            int i=x[0];
            int prev=(i>0)?pre[i-1]:0;
            int nxt=(i<n-1)?pre[i+1]:0;

            if(pre[i] && prev==pre[i])c--;
            if(pre[i] && nxt==pre[i])c--;

            pre[i]=x[1];

            if(prev==pre[i])c++;
            if(nxt==pre[i])c++;

            ans.push_back(c);
        }

        return ans;
    }
};