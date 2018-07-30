class Solution:
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
            return 0
        stack = []
        
        for i, p in enumerate(s):
            if p == '(':
                stack.append(1)
            else:
                if len(stack) > 0 and stack[-1] == 1: # ()
                    stack[-1] = 2
                elif len(stack) > 1 and stack[-1] > 1 and stack[-2] == 1: # (()())
                    stack[-2] = stack[-1] + 2
                    stack.pop()
                else:
                    stack.append(-1)
                
                while len(stack) > 1 and stack[-1] > 1 and stack[-2] > 1:
                    stack[-2] += stack[-1]
                    stack.pop()
        
        ret = max(stack)
        return ret if ret > 1 else 0