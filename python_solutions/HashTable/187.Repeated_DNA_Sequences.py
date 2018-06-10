class Solution:
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        hashMap = collections.defaultdict(int)
        
        for i in range(len(s)):
            hashMap[s[i:i+10]] += 1
        return [key for key, value in hashMap.items() if value > 1]