class Solution:
    def addToArrayForm(self, A: List[int], k: int) -> List[int]:
        n=len(A)
        for i in range(n-1,-1,-1):
            k,A[i]=divmod(A[i]+k,10)

        while k:
            k,a=divmod(k,10)
            A=[a]+A
        
        return A
        



        