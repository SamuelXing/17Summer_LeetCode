class Solution:
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        start, end = 0, len(height)-1
        maxVal, area = 0, 0
        
        while start < end:
            if height[start] > height[end]:
                area = (end - start) * height[end]
                end -= 1
            else:
                area = (end - start) * height[start]
                start += 1
                
            maxVal = max(maxVal, area)
        
        return maxVal