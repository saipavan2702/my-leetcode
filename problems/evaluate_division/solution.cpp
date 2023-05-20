class Solution {
public:
    using pD=pair<string,double>;
    
    pD find(string r, unordered_map<string,pD>&P){

        if(P.find(r)==P.end())
        P[r]={r,1};

        if(P[r].first==r)
        return P[r];

        auto par=find(P[r].first,P);
        P[r].first=par.first;
        P[r].second*=par.second;


        return {par.first,P[r].second};
    }

    void uni(string u, string v, double val, unordered_map<string,pD>&P){
        auto a=find(u,P);
        auto b=find(v,P);

        if(a.first==b.first)
        return;

        P[b.first].first=a.first;
        P[b.first].second=a.second*val/b.second;
        
    }

    vector<double> calcEquation(vector<vector<string>>& E, vector<double>& val, vector<vector<string>>& Q) {

        vector<double>have;
        unordered_map<string,pD>P;

        int n=E.size();
         for(int i=0;i<n;i++){
            uni(E[i][0],E[i][1],val[i],P);
        }
       
        for(auto x:Q){
            double eval=-1.0;

            if(P.find(x[0])!=P.end() && P.find(x[1])!=P.end()){
                auto u=find(x[0],P);
                auto v=find(x[1],P);

                if(u.first==v.first){
                    eval=v.second*1.0/u.second;
                }
            }
            have.push_back(eval);
        }
        return have;

    }
};