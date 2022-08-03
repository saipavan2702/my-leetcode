class MyCalendar {
public:
    vector<pair<int,int>>ans;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto x:ans)
        {
            if(max(x.first,start)<min(x.second,end))
            return 0;
        }
        ans.push_back({start,end});
        return 1;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */