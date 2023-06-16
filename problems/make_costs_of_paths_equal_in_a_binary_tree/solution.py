class Solution:
    def minIncrements(self, n: int, cost: List[int]) -> int:
        inc=0
        def recur(i):
            if i>=n:
                return 0
            nonlocal inc
            ls,rs=recur(2*i+1),recur(2*i+2)
            
            inc+=abs(ls-rs)
            return cost[i]+max(ls,rs)
        recur(0)
        return inc