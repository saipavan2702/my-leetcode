class Solution:
    def summaryRanges(self, A: List[int]) -> List[str]:
        hash=[]
        size=len(A)
        j=0

        if size==0:
            return {}
        if size==1:
            return {str(A[0])}

        for i in range(1,size):
            if A[i]-A[i-1]!=1:
                if i!=j+1:
                    hash.append(str(A[j])+"->"+str(A[i-1]))
                    j=i
                elif i-1==j:
                    hash.append(str(A[i-1]))
                    j=i
        
        if A[size-1]==A[size-2]+1:
            hash.append(str(A[j])+"->"+str(A[size-1]))
        else:
            hash.append(str(A[size-1]))
        return hash
