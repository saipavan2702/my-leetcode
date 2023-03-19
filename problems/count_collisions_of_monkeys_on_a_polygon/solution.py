class Solution:
    def monkeyMove(self, n: int) -> int:
        k = 10**9 + 7
        ans=pow(2,n,k)
        ans=ans-2
        if ans<=0:
            ans=ans+k
        return ans%k