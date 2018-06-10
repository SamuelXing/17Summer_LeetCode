class Solution:
    def getModifiedArray(self, length, updates):
        """
        :type length: int
        :type updates: List[List[int]]
        :rtype: List[int]
        """
        
        arr = [0]*length
        
        for start, end, inc in updates:
            arr[start] += inc
        
            if end < length - 1:
                arr[end + 1] -= inc 
        
        for i in range(length-1):
            arr[i+1] += arr[i]
        
        return arr
            
        