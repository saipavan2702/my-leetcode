class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string a=to_string(n);
        sort(a.begin(),a.end());
        for(int i=0;i<31;i++)
        {
            string b=to_string(1<<i);
            sort(b.begin(),b.end());
            if(a==b)
            return 1;
        }
        return 0;
    }
};