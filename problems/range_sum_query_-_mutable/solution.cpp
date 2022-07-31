class NumArray {
public:
    vector<int>res;
    int sum=0;
    NumArray(vector<int>& nums) {
       res=nums; 
        for(int i=0;i<res.size();i++)
        sum+=res[i];
    }
    
    void update(int index, int val) {
        sum-=res[index];
        res[index]=val;
        sum+=res[index];
    }
    
    int sumRange(int left, int right) {
        //int n;n=res.size();
        int pre=sum;
        for(int i=0;i<left;i++)
        {
            pre-=res[i];
        }
        for(int i=right+1;i<res.size();i++)
        {
            pre-=res[i];
        }
        return pre;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */