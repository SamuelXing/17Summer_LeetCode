# k[i] = min(k[p2]*2, k[p3]*3, k[p5]*5)

class Solution:
    def nthUglyNumber(self, n):
        if n <= 1:
            return 1
        
        p2, p3, p5 = 0, 0, 0
        
        k = [0]*n
        k[0] = 1
        
        for i in range(1, n):
            k[i] = min(k[p2]*2, k[p3]*3, k[p5]*5)
            p2 = p2 + 1 if k[p2]*2 == k[i] else p2
            p3 = p3 + 1 if k[p3]*3 == k[i] else p3
            p5 = p5 + 1 if k[p5]*5 == k[i] else p5
            
        return k[n-1]