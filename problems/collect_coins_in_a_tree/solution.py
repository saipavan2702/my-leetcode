class Solution:
    def collectTheCoins(self, coins: List[int], E: List[List[int]]) -> int:
        graph=defaultdict(list)
        n=len(coins)

        for i,j in E:
            graph[i].append(j)
            graph[j].append(i)
        indeg=[0]*n
        for i in range(n):
            for node in graph[i]:
                indeg[node]+=1
        queue=[]
        for i in range(n):
            if(indeg[i]==1):
                queue.append(i)
        # print(indeg)
        while queue:
            node=queue.pop(0)
            if coins[node]==0:
                indeg[node]-=1
                for i in graph[node]:
                    del graph[node]
                    graph[i].remove(node)
                    if len(graph[i])==1:
                        queue.append(i)
        # print(queue)
        for _ in range(2):
            queue=[i for i in graph if len(graph[i])==1]
            # print(queue)
            for u in queue:
                par=graph[u].pop(0)
                del graph[u]
                # print(graph[u])
                graph[par].remove(u)
                if len(graph)<2:
                    return 0

        return 2*len(graph)-2





