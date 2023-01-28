class SummaryRanges {
public:
    set<int>py;
    SummaryRanges() {
        py.clear();
    }
    
    void addNum(int val) {
       py.insert(val);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>>ans;
        int l=-1,r=-1;
        for(auto x:py){
            if(r<0)
            l=r=x;
            else if(x-r==1){
                r=x;
            }
            else{
                ans.push_back({l,r});
                l=r=x;
            }
        }
        ans.push_back({l,r});
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */