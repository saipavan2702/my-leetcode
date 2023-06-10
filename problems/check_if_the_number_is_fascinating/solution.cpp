class Solution {
public:
    bool isFascinating(int n) {
        string s=to_string(n);
        for(auto x:s)
            if(x=='0' || x=='5')
                return 0;
        int sn=2*n;
        int tn=3*n;
        
        string snn=to_string(sn);
        string tnn=to_string(tn);
        cout<<s<<" "<<snn<<" "<<tnn<<endl;
        
        for(auto x:snn)
            if(x=='0')
                return 0;
        
        for(auto x:tnn)
            if(x=='0')
                return 0;
        
        string fs=s+snn+tnn;
        for(auto x:fs){
            if(x=='0')
                return 0;
        }
        
        set<char>st;
        for(auto x:fs)
            st.insert(x);
        
        return st.size()==fs.size();
        
    }
};