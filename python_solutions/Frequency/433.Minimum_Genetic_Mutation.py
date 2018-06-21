class Solution(object):
    def canMutate(self, cur, gene):
        diff = 0
        for i, s in enumerate(gene):
            if s != cur[i]:
                diff += 1
        return diff == 1
    
    def minMutation(self, start, end, bank):
        """
        :type start: str
        :type end: str
        :type bank: List[str]
        :rtype: int
        """
        queue = [[start, start, 0]]
        while queue:
            cur, pre, step = queue.pop(0)
            if cur == end:
                return step
            for gene in bank:
                if self.canMutate(cur, gene) and gene!=pre:
                    queue.append([gene, cur, step+1])
        return -1