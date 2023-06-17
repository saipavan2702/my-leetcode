class Solution:
    def makeArrayIncreasing(self, A: List[int], B: List[int]) -> int:
        n,p=len(A),len(B)
        B.sort()
        dp={}

        def bs(key):
            lo,hi=0,p-1
            while lo<=hi:
                u=(lo+hi)//2
                if B[u]>key:
                    hi=u-1
                else:
                    lo=u+1
            return lo

        def recur(i,prev):
            if i>=n:
                return 0
            if (i,prev) in dp:
                return dp[(i,prev)]
            cost=10**9+1
            if A[i]>prev:
                cost=recur(i+1,A[i])
            u=bs(prev)
            if(u<p):
                cost=min(cost,1+recur(i+1,B[u]))
            dp[(i,prev)]=cost
            return cost
        ans=recur(0,-1)

        if ans<10**9+1: 
            return ans 
        return -1


            
