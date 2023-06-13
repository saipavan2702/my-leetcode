class Solution:
    def equalPairs(self, grid: List[List[int]]) -> int:
        dict=defaultdict(int)
        h=0
        for i in grid:
            dict[tuple(i)]+=1
        
        for i in zip(*grid):
            h+=dict[tuple(i)]
        return h