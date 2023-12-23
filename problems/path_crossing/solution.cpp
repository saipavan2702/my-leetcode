class Solution {
public:
    bool isPathCrossing(string path) {
        using pI=pair<int,int>;
        pI ref={0,0};
        set<pI>st;
        st.insert(ref);
        
        for(auto &x:path){
            pI curr=ref;
            if(x=='N'){
                curr.second+=1;
            }else if(x=='S'){
                curr.second-=1;
            }else if(x=='E'){
                curr.first+=1;
            }else{
                curr.first-=1;
            }
            if(st.find(curr)!=st.end()) return true;
            st.insert(curr);
            ref=curr;
        }

        return false;
    }
};