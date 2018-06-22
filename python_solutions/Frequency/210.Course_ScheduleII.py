# BFS
class Solution:
    def findOrder(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: List[int]
        """
        edges = {i: [] for i in range(numCourses)}
        degrees = [0 for i in range(numCourses)]
        
        # initialize graph
        for i, j in prerequisites:
            edges[j].append(i)
            degrees[i] += 1
            
        # push courses without prerequisites to queue
        queue = []
        queue = [i for i in range(numCourses) if degrees[i] == 0]
        
        count, res = 0, []
        while queue:
            node = queue.pop(0)
            res.append(node)
            count += 1
            for x in edges[node]:
                degrees[x] -= 1
                if degrees[x] == 0:
                    queue.append(x)
                    
        return res if count == numCourses else []

# dfs
class Solution:
    def findOrder(self, numCourses, prerequisites):
        """
        :type numCourses: int
        :type prerequisites: List[List[int]]
        :rtype: List[int]
        """
        edges = {i: [] for i in range(numCourses)}
        degrees = [0 for i in range(numCourses)]
        
        # initialize graph
        for i, j in prerequisites:
            edges[j].append(i)
            degrees[i] += 1
            
        # push courses without prerequisites to stack
        stack = []
        stack = [i for i in range(numCourses) if degrees[i] == 0]
        
        res = []
        while stack:
            node = stack.pop()
            res.append(node)
            for x in edges[node]:
                degrees[x] -=  1
                if degrees[x] == 0:
                    stack.append(x)
                    
        for i in range(numCourses):
            if degrees[i] > 0:
                return []
        return res