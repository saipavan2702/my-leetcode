class FrequencyTracker {
public:
    map<int,int>freq,dict;
    FrequencyTracker() {
       freq.clear();
    }
    
    void add(int N) {
        if(dict[freq[N]]>0)
        dict[freq[N]]--;
        
        freq[N]++;
        dict[freq[N]]++;
    }
    
    void deleteOne(int N) {
        if(freq[N]>0 && dict[freq[N]]>0)
        dict[freq[N]]--,freq[N]--;
        
        dict[freq[N]]++;
    }
    
    bool hasFrequency(int f) {
        return dict[f]>0;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */