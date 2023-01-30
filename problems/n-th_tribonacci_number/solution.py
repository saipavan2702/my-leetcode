class Solution:
    def tribonacci(self, n: int) -> int:
        if n==0:
            return 0
        if n==2 or n==1:
            return 1
        
        lst=[0]*(n+1)
        lst[0]=0
        lst[1]=1
        lst[2]=1
        
        for i in range (3,n+1):
            lst[i]=lst[i-1]+lst[i-2]+lst[i-3]
        
        return lst[n]