class Solution:
    def divisibilityArray(self, S: str, K: int) -> List[int]:
        n=len(S)
        ans=[0]*n
        
        curr=0
        for i in range(n):
            curr=curr+int(S[i])
            if curr%K==0:
                ans[i]=1
            else:
                ans[i]=0
                
            curr*=10
            curr%=K;
        
        return ans
            
        