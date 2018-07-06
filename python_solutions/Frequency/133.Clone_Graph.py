# Definition for a undirected graph node
# class UndirectedGraphNode:
#     def __init__(self, x):
#         self.label = x
#         self.neighbors = []

class Solution:
    # @param node, a undirected graph node
    # @return a undirected graph node
    def cloneGraph(self, node):
        if not node:
            return None
        
        hashMap = {}
        root = UndirectedGraphNode(node.label)
        hashMap[node.label] = root
        
        q = [node]
        while q:
            front = q.pop(0)
            for n in front.neighbors:
                if n.label not in hashMap:
                    copy = UndirectedGraphNode(n.label)
                    hashMap[n.label] = copy
                    q.append(n)
                hashMap[front.label].neighbors.append(hashMap[n.label])
                
        return root
        
    def cloneGraph(self, node):
        hashMap = {}
        
        def clone(node):
            if not node: return None
            
            if node.label in hashMap:
                return hashMap[node.label]
            
            root = UndirectedGraphNode(node.label)
            hashMap[root.label] = root
            for n in node.neighbors:
                root.neighbors.append(clone(n))
                
            return root
        
        return clone(node)
