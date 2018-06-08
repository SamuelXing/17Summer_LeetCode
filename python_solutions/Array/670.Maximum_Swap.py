class Solution:
    def maximumSwap(self, num):
        """
        :type num: int
        :rtype: int
        """
        numStr = list(str(num))
        bucket = [0 for i in range(10)]
        
        for i in range(len(numStr)):
            bucket[ord(numStr[i]) - ord('0')] = i
        
        for i in range(len(numStr)):
            for k in range(9, ord(numStr[i]) - ord('0'), -1):
                if bucket[k] > i:
                    temp = numStr[i]
                    numStr[i] = numStr[bucket[k]]
                    numStr[bucket[k]] = temp
                    return int(''.join(numStr))
                
        return num
