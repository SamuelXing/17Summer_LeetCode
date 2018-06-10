class Solution:
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        c, m = collections.Counter(s), {}
        
        for k, v in c.items():
            m.setdefault(v, []).append(k*v)
        
        return ''.join([''.join(m[i]) for i in range(len(s), -1, -1) if i in m])
        