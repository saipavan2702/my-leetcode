class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>>dict;
    unordered_map<string,pair<double,int>>avg;

    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        dict[id]={stationName,t};
    }
    
    void checkOut(int id, string station, int t) {
        auto prev=dict[id];
        dict.erase(id);

        string dest=prev.first+"-"+station;
        avg[dest].first+=t-prev.second;
        avg[dest].second++;

    }
    
    double getAverageTime(string start, string end) {
        string route=start+"-"+end;
        auto have=avg[route];
        return have.first/have.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */