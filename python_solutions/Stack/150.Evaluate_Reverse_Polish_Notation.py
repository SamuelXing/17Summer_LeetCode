class Solution:
    def evalRPN(self, tokens):
        """
        :type tokens: List[str]
        :rtype: int
        """
        stack = []
        for tok in tokens:
            if tok in '+-*/':
                num2 = stack.pop()
                num1 = stack.pop()
                if tok == '+':
                    stack.append(num1+num2)
                if tok == '-':
                    stack.append(num1-num2)
                if tok == '*':
                    stack.append(num1*num2)
                if tok == '/':
                    stack.append(int(num1/num2))
            else:
                stack.append(int(tok))
        
        return stack[-1]
            
     