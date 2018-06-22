class Vector2D(object):

    def __init__(self, vec2d):
        """
        Initialize your data structure here.
        :type vec2d: List[List[int]]
        """
        self.row = 0
        self.col = 0
        self.vec = vec2d
        

    def next(self):
        """
        :rtype: int
        """
        ret = self.vec[self.row][self.col]
        self.col += 1
        return ret
        

    def hasNext(self):
        """
        :rtype: bool
        """
        while self.row < len(self.vec):
            if self.col < len(self.vec[self.row]):
                return True
            self.col = 0
            self.row += 1
        
        return False

# iterator version
class Vector2D(object):

    def __init__(self, vec2d):
        """
        Initialize your data structure here.
        :type vec2d: List[List[int]]
        """
        def get():
            for row in vec2d:
                for item in row:
                    yield item
        self.myiter = iter(get())
        self.mynext = next(self.myiter, None)
        

    def next(self):
        """
        :rtype: int
        """
        if self.hasNext():
            ret = self.mynext
            self.mynext = next(self.myiter, None)
            return ret

    def hasNext(self):
        """
        :rtype: bool
        """
        return self.mynext != None