# 1. Pick out tallest group of people and sort them in a subarray (S). Since there's no other groups of people taller than them, therefore each guy's index will be just as same as his k value.
# 2. For 2nd tallest group (and the rest), insert each one of them into (S) by k value. So on and so forth.

class Solution:
    def reconstructQueue(self, people):
        """
        :type people: List[List[int]]
        :rtype: List[List[int]]
        """
        people.sort(key=lambda p: (-p[0], p[1]))
        print(people)
        queue = []
        for p in people:
            queue.insert(p[1], p)
        return queue
        