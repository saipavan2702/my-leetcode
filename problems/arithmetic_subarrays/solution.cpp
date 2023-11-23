class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& A, vector<int>& l, vector<int>& r) {
        
        vector<bool> ans(l.size(),false);
        for(int i=0;i<l.size();i++)
        {
            if(r[i]-l[i]+1==2)
                ans[i]=true;
            else if(isArthemetic(A,l[i],r[i]))
                ans[i]=true;
        }
        return ans;
    }

    bool isArthemetic(vector<int>& A,int start,int end)
    {
        
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=start;i<=end;i++)
        {
            mini=min(A[i],mini);
            maxi=max(A[i],maxi);
        }

        if(mini==maxi)
            return true; 
  
        if((maxi-mini)%(end-start)!=0)
            return false;

        int diff=(maxi-mini)/(end-start);

        vector<bool> present(end-start+1,false);
        for(int i=start;i<=end;i++)
        {
            
            if((A[i]-mini)%diff!=0)
                return false;
            
            int ind=(A[i]-mini)/diff;
            if(present[ind])
                return false;
            present[ind]=true;
            
        }
        return true;
        
    }
};