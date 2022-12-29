class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& T) {
        int n;
        n=T.size();
        
        vector<int>req;
        using node=pair<int,int>;

        for(int i=0;i<n;i++)
        T[i].push_back(i);
        
        sort(T.begin(),T.end());
        priority_queue<node, vector<node>, greater<node>>pq;

        int i=0;
        long long ret=T[0][0];
        while(i<n or !pq.empty()) {

           while(i<n && ret>=T[i][0]) {
             pq.push({T[i][1],T[i][2]});
             i++;
           }

           if(pq.empty()){
               ret=T[i][0];
           }
           else{
               node x=pq.top();
               pq.pop();
               req.push_back(x.second);
               ret+=x.first;
           }
        }
        return req;
    }
};