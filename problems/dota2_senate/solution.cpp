class Solution {
public:
    string predictPartyVictory(string S) {
        int n=S.size();
        queue<int>qd,qr;

        for(int i=0;i<n;i++){
            S[i]=='R'?qr.push(i):qd.push(i);
        }
        
        while(!qr.empty() && !qd.empty()){
            if(qr.front()<qd.front())
            qr.push(qr.front()+n);
            else
            qd.push(qd.front()+n);

            qr.pop();
            qd.pop();
        }

        return qr.empty()?"Dire":"Radiant";
    }
};