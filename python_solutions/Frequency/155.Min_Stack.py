class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []
        

    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        curMin  = self.getMin()
        if curMin == None or x < curMin:
            curMin = x
        self.stack.append((x, curMin))
        

    def pop(self):
        """
        :rtype: void
        """
        if not self.stack:
            return
        self.stack.pop()
        

    def top(self):
        """
        :rtype: int
        """
        if not self.stack:
            return None
        return self.stack[-1][0]
        

    def getMin(self):
        """
        :rtype: int
        """
        if not self.stack:
            curMin = None
        else:
            curMin = self.stack[-1][1]
        return curMin


class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.stack = []
        self.curMin = float('inf')
        

    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        if not self.stack:
            self.stack.append(float('inf'))
            self.curMin = x
        else:
            self.stack.append(x-self.curMin)
            self.curMin = min(self.curMin, x)
        

    def pop(self):
        """
        :rtype: void
        """
        top = self.stack.pop()
        if top < 0:
            self.curMin -= top
        

    def top(self):
        """
        :rtype: int
        """
        if not self.stack:
            return None
        if self.stack[-1] == float('inf'):
            return self.curMin
        if self.stack[-1] < 0:
            return self.curMin
        else:
            return self.curMin + self.stack[-1]
        

    def getMin(self):
        """
        :rtype: int
        """
        return self.curMin