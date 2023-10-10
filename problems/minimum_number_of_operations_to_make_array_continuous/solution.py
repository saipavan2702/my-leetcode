class Solution:
    def minOperations(self, A: List[int]) -> int:
        n = len(A)
        A = sorted(set(A))
        ans = float('inf')

        for i, s in enumerate(A):
            e = s + n - 1
            idx = bisect_right(A, e)

            ans = min(ans, n - (idx - i))
        return ans