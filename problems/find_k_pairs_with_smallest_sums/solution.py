class Solution:
    def kSmallestPairs(self, A:List[int], B:List[int], k: int) -> List[List[int]]:
        n,p=len(A),len(B)
        heap,pairs=[],[]

        for i in range(n):
            heapq.heappush(heap,[A[i]+B[0],0])
        
        while k and heap:
            pair,idx=heapq.heappop(heap)
            pairs.append([pair-B[idx],B[idx]])
            k-=1

            if idx+1<p:
                heapq.heappush(heap,[pair-B[idx]+B[idx+1],idx+1])
        
        return pairs



