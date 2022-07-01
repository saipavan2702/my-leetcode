class Solution {
public:
    static bool re(vector<int>&a,vector<int>&b)
    {
        return a[1]>b[1];
    }
    int maximumUnits(vector<vector<int>>& box, int Size) {
        sort(box.begin(),box.end(),re);
        int sum=0,size=0;
        for(auto x:box)
        {
            int curr=min(x[0],Size);
            
             sum+=(curr*x[1]);
             size+=curr;
             Size-=curr;
        
        }
        return sum;
    }
};