# Definition for a undirected graph node
# class UndirectedGraphNode:
#     def __init__(self, x):
#         self.label = x
#         self.neighbors = []

# DFS
class Solution:
    # @param node, a undirected graph node
    # @return a undirected graph node
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