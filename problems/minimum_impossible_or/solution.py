class Solution:
    def minImpossibleOR(self, Q: List[int]) -> int:
        Q=set(Q)
        for i in range(33):
            if 1<<i not in Q:
                return 1<<i
        