class Solution:
    def leastInterval(self, tasks, n):
        """
        :type tasks: List[str]
        :type n: int
        :rtype: int
        """
        dic = [0]*26
        
        for t in tasks:
            dic[ord(t) - ord('A')] += 1
        
        dic.sort()
        i = 25
        while i >= 0 and dic[i] == dic[25]:
            i -= 1
        
        return max(len(tasks), (dic[25] - 1)*(n + 1) + 25 - i)
        