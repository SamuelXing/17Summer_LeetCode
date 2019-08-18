class UF:
    def __init__(self, n):
        self.count = n
        self.parent = [i for i in range(n)]
        self.rank = [0 for i in range(n)]
     
    def find(self, p):
        while p != self.parent[p]:
            self.parent[p] = self.parent[self.parent[p]]
            p = self.parent[p]
        return p
    
    def counter(self):
        return self.count
    
    def connected(self, p, q):
        return self.find(p) == self.find(q)
    
    def union(self, p, q):
        rootP = self.find(p)
        rootQ = self.find(q)
        
        if rootP == rootQ:
            return
        
        # make root of smaller rank point to root of larger rank
        if self.rank[rootP] < self.rank[rootQ]:
            self.parent[rootP] = rootQ
        elif self.rank[rootP] > self.rank[rootQ]:
            self.parent[rootQ] = rootP
        else:
            self.parent[rootQ] = rootP
            self.rank[rootP] += 1
        self.count -= 1



