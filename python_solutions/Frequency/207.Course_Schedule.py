class Solution:
    def canFinish(self, numCourses, prerequisites):
        # Write your code here
        edges = {i: [] for i in range(numCourses)}
        degrees = [0 for i in range(numCourses)] 
        for i, j in prerequisites:
            edges[j].append(i)
            degrees[i] += 1
        import queue
        queue, count = queue.Queue(maxsize = numCourses), 0
        
        for i in range(numCourses):
            if degrees[i] == 0:
                queue.put(i)

        while not queue.empty():
            node = queue.get()
            count += 1

            for x in edges[node]:
                degrees[x] -= 1
                if degrees[x] == 0:
                    queue.put(x)

        return count == numCourses