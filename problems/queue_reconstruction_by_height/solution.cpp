class Solution {
public:
    static bool order(vector<int>&a,vector<int>&b)
    {
        if(a[0]==b[0])
        return a[1]<b[1];
        else
        return a[0]>b[0];    
                    
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),order);
        vector<vector<int>>sus;
        
        for(int i=0;i<people.size();i++)
        {
            sus.insert(sus.begin()+people[i][1],people[i]);
        }
        return sus;
    }
};