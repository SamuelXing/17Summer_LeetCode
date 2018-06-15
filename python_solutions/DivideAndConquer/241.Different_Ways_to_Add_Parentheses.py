class Solution:
    def diffWaysToCompute(self, input):
        """
        :type input: str
        :rtype: List[int]
        """
        ret = []
        for i, c in enumerate(input):
            if c in '+-*':
                for a in self.diffWaysToCompute(input[:i]):
                    for b in self.diffWaysToCompute(input[i+1:]):
                        ret.append(a+b if c == '+' else a-b if c == '-' else a*b)
        
        return ret if len(ret) > 0 else [int(input)]